#include <iostream>
#include "Functions.h"
#include "AVLTree.h"
#include "Author.h"


int main(int argc, char** argv) {
    char* directory;
    char *searchWord;
    if (argc == 1) {
        directory = "../Documents/cs2341_data";
    }
    if (argc == 3) {
        searchWord = argv[2];
        directory = argv[1];
    };
    //Hashtable for Authors
    HashTable<string, Author*> authors(35999);
    //Hashset for stop words
    HashSet<string> stopWords(499);
    //persistent File File
    ofstream persistentFile("../persistentFile.txt");
    //AVLTree for stemmed words
    AVLTree<Word> allWords;
    //number of Documents parsed
    int numberOfDocs = 0;
    //Words that aren't stemmed paired with their stemmed counterparts
    AVLTree<StopWordAssociation> stopWordAssociation;
    //stop words file
    ifstream stopWordFile("../stopWords.txt");
    //function to load the stop word hashset with stop words
    loadStopWords(stopWordFile, stopWords);
    //File parser to load the AVLtree for stemmed word and hashtable for authors, returns the number of documents parsed
    numberOfDocs = fileParser(stopWords, allWords, stopWordAssociation, authors, directory);
    //function to create persistent file
    createPersistentFile(persistentFile, allWords);
    //show initial UI
    showBasicInputUI();
    //begins the querying proccess
    startIndex(allWords, authors, directory, searchWord, argc);
    //returns the statistics
    outputStatistics(allWords, authors, numberOfDocs);
    //frees memory allocated
    allWords.forWords();
    stopWordAssociation.emptyTree();
    authors.emptyAVLs();
    stopWords.emptyAVLs();
    return 0;
}
