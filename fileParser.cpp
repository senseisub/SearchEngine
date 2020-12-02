//
// Created by seuns on 11/17/2020.
//
#include "Functions.h"



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

        if(word.size() < 2)
            continue;

        size_t pos = 0;
        //if words consists only of alphabetical characters
        for(char c : word){
            if(!isalpha(c)){
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
                    Word* currentWord = &(words.getValue(currentStopWord.getWordAssociation()));
                    if(currentWord->hasDocument(documentID)){
                        currentWord->increaseDocumentFrequency(documentID);
                    }
                    else{

                        currentWord->newDoc(documentID);
                    }
                    currentWord->increaseFreq();
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

                //new stop word association with non-stemmed word and stemmed-word associate
                StopWordAssociation newStopWord(originalWord, word);

                stopWordAssociations.insert(newStopWord);


                if(words.contains(word)){
                    //if word already exists then increment document frequency and word frequency
                    Word* currentWord = &(words.getValue(word));
                    if(currentWord->hasDocument(documentID)){
                        currentWord->increaseDocumentFrequency(documentID);
                    }
                    else{
                        currentWord->newDoc(documentID);
                    }
                    currentWord->increaseFreq();
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

int fileParser(HashSet<string>& stopWords, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, HashTable<string, Author*>& authors, char*& directory){
    DIR *pDIR;
    struct dirent *entry;
    if( pDIR=opendir(directory) ) {
        cout << "Directory found!" << endl << endl;
        cout << "Loading. . ." << endl;
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

                    transform(last.begin(), last.end(), last.begin(), ::tolower);
                    if (authors.containsAuthor(last)) {
                        Author* currentAuthor = authors[last];
                        currentAuthor->addArticles(thisArticle);
                    } else {
                        Author* currentAuthor = new Author(last);
                        currentAuthor->addArticles(thisArticle);
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
            if (num == 100) {
                return 0;
            }
        }
        closedir(pDIR);
    }
    else{
        cout << "Directory not found :(" << endl;
    }
}

bool treeContains(AVLTree<Word>& words, char*& searchWord, char*& directory) {
    string word = searchWord;
    cout << endl;
    cout<< "Searching for " << word << ". . ." << endl << endl;
    Porter2Stemmer::stem(word);
    if (words.contains(word)) {
        Word currentWord = words.getValue(word);
        currentWord.printWordDocuments(directory);
        return true;
    } else {
        cout << "Word is not in any documents. Try again." << endl;
        return false;
    }
}

bool getAuthor(HashTable<string, Author*>& authors){
    string userInput;
    getline(cin, userInput);
    if(authors.containsAuthor(userInput)){
        Author currentAuthor = *authors[userInput];
        cout << "Current Author : " << currentAuthor.getAuthorName() << endl;
        for(Article& a : currentAuthor.getArticleList()){
            cout  <<a.getID() << endl;
        }
    }
    else{
        cout << "Author doesn't exist" << endl;
    }
}