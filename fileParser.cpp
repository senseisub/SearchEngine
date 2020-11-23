//
// Created by seuns on 11/17/2020.
//
#include "Functions.h"
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include <dirent.h>
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filereadstream.h"
#include <ctype.h>
#include "rapidjson/include/rapidjson/istreamwrapper.h"
#include "porter2_stemmer.h"


using namespace rapidjson;



void loadStopWords(ifstream& stops, HashSet<string>& stopWords){ //Unordered set of stop words of O(1)
    std::string str;
    while(stops >> str) {
        stopWords.insert(str);
    }
}

void parseBody(HashSet<string>& stopWords, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, istringstream& ss, string& documentID){
    do {
        // Read a word
        string word;
        ss >> word;

        size_t pos = 0;
        //if words consists only of alphabetical characters
        for(char c : word){
            if(((int)c < 65 || ((int)c < 97) && ((int)c > 90) || (int)c >122)){
                if (word.find(c) != std::string::npos) {
                    word.erase(word.find(c));
                }
            }
        }

        transform(word.begin(), word.end(), word.begin(), ::tolower);

        //if not a stop word
        if (!stopWords.contains(word)) {
            if(stopWordAssociations.contains(word)){
                //if stop word association exists then get the stemmed word associated with it
                StopWordAssociation currentStopWord = stopWordAssociations.getValue(word);
                if(words.contains(currentStopWord.getWordAssociation())){
                    //gets the word object and increments the document frequency and word frequency
                    Word currentWord = words.getValue(currentStopWord.getWordAssociation());
                    if(currentWord.hasDocument(documentID)){
                        currentWord.increaseDocumentFrequency(documentID);
                    }
                    else{
                        currentWord.newDoc(documentID);
                    }
                    currentWord.increaseFreq();
                }
                else{
                    //creates new word and adds it to the AVL
                    Word currentWord(word);
                    currentWord.newDoc(documentID);
                    words.insert(currentWord);
                }
            }
            else {
                //string before it gets stemmed
                string originalWord = word;
                //stems word
                Porter2Stemmer::stem(word);
                //both stemmed and non-stemmed words transformed to lowercase
                transform(originalWord.begin(), originalWord.end(), originalWord.begin(), ::tolower);

                //new stop word association with non-stemmed word and stemmed-word associate
                StopWordAssociation newStopWord(originalWord, word);
                stopWordAssociations.insert(newStopWord);


                if(words.contains(word)){
                    //if word already exists then increment document frequency and word frequency
                    Word currentWord = words.getValue(word);
                    if(currentWord.hasDocument(documentID)){
                        currentWord.increaseDocumentFrequency(documentID);
                    }
                    else{
                        currentWord.newDoc(documentID);
                    }
                    currentWord.increaseFreq();
                }
                else{
                    //word add new word to the words avl
                    Word currentWord(word);
                    currentWord.newDoc(documentID);
                    words.insert(currentWord);
                }
            }
        }

        // While there is more to read
    } while (ss);
}

int fileParser(HashSet<string>& stopWords, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, HashTable<string, Author>& authors, char*& directory){
    DIR *pDIR;
    struct dirent *entry;
    cout << directory << endl;
    if( pDIR=opendir(directory) ) {
        cout << "found" << endl;
        int num = 0;

        while (entry = readdir(pDIR)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                num++;
                // 1. Parse a JSON string into DOM.
                char str[100];
                strcpy(str, directory);
                strcat(str, "/");
                string fullname = str;
                fullname += entry->d_name; //change from char* to string because json / strcat didnt accept string?

//                cout << fullname << endl;
                const char * c = fullname.c_str();
//                cout << realpath(c, NULL) << endl;

                std::ifstream ifs{fullname};
                if (!ifs.is_open()) {
                    std::cerr << "Could not open file for reading!\n";
                    return EXIT_FAILURE;
                }
                if (strcmp(entry->d_name, "metadata-cs2341.csv") == 0)
                    return 0;

                IStreamWrapper isw{ifs};

                Document d;
                d.ParseStream(isw);
                StringBuffer buffer;
                Writer<StringBuffer> writer(buffer);
                d.Accept(writer);

                //get Document ID
                string documentID = d["paper_id"].GetString();
                string title = d["metadata"]["title"].GetString();


                //initializes string array
                //if authors are empty
                Article thisArticle(title, documentID);
                for (int i = 0; i < d["metadata"]["authors"].GetArray().Size(); i++) {
                    string first = d["metadata"]["authors"].GetArray()[i]["first"].GetString();
                    string last = d["metadata"]["authors"].GetArray()[i]["last"].GetString();
                    //put first and last name in one word with no space
                    string authorName = first + last;
                    //tranforms to lowercase
                    transform(authorName.begin(), authorName.end(), authorName.begin(), ::tolower);
                    if (authors.containsAuthor(authorName)) {
                        Author currentAuthor = authors[authorName];
                        currentAuthor.addArticles(thisArticle);
                    } else {
                        Author currentAuthor(authorName);
                        currentAuthor.addArticles(thisArticle);
                        authors.insertAuthor(currentAuthor);
                    }
                }
                for (int i = 0; i < d["abstract"].GetArray().Size(); i++) {
                    string temp = d["abstract"].GetArray()[i]["text"].GetString();
                    istringstream ss(temp);
                    //reads through all words
                    parseBody(stopWords, words, stopWordAssociations, ss, documentID);
                }
                for (int i = 0; i < d["body_text"].GetArray().Size(); i++) {
                    string temp = d["body_text"].GetArray()[i]["text"].GetString();
                    istringstream ss(temp);
                    //reads through all words
                    parseBody(stopWords, words, stopWordAssociations, ss, documentID);
                }
            }
            if (num == 1000) {
                cout << " test " << endl;
                return 0;
            }
        }
        closedir(pDIR);
    }
}

bool treeContains(AVLTree<Word>& words, char*& searchWord, char*& directory) {
    string word = searchWord;
    cout << word << endl;
    if (words.contains(word)) {
        Word currentWord = words.getValue(word);
        currentWord.printWordDocuments(directory);
        return true;
    } else {
        cout << "Word is not in any documents. Try again." << endl;
        return false;
    }
}