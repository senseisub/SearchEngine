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
    HashTable<string, Author*> authors(19999);
    HashSet<string> stopWords(499);
    ofstream persistentFile("../persistentFile.txt");
    AVLTree<Word> allWords;
    int numberOfDocs = 0;
    AVLTree<StopWordAssociation> stopWordAssociation;
    ifstream stopWordFile("../stopWords.txt");
    loadStopWords(stopWordFile, stopWords);
    fileParser(stopWords, allWords, stopWordAssociation, authors, directory, numberOfDocs);
    createPersistentFile(persistentFile, allWords);
    showBasicInputUI();
    startIndex(allWords, authors, directory, searchWord, argc);
    outputStatistics(allWords, authors, numberOfDocs);
    allWords.forWords();
    stopWordAssociation.emptyTree();
    authors.emptyAVLs();
    stopWords.emptyAVLs();
    return 0;
}
