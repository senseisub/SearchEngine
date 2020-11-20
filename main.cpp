#include <iostream>
#include "AVLTree.h"
#include "Author.h"
#include "Functions.h"

int main(int argc, char** argv) {
    char* directory;
    char *searchWord;
    if (argc == 1) {
        char* directory = "../Documents/cs2341_data";
    }
    if (argc == 3) {
        char *searchWord = argv[2];
        char *directory = argv[1];
    }
    HashTable authors(20000);
    unordered_set<string> stopWords;
    ofstream persistentFile("../persistentFile.txt");
    AVLTree<Word> allWords;
    AVLTree<StopWordAssociation> stopWordAssociation;
    ifstream stopWordFile("../stopWords.txt");
    loadStopWords(stopWordFile, stopWords);
    fileParser(stopWords, allWords, stopWordAssociation, authors, directory);
    cout << "number of words : " << allWords.getSize() << endl;
    cout << "number of stops : " << stopWordAssociation.getSize() << endl;
    cout << "number of authors : " << authors.getSize() << endl;
    cout << "number of words that are stops : " << stopWords.size() << endl;
    cout << "type of avltree : " << typeid(allWords).name() << endl;
    createPersistentFile(persistentFile, allWords);
    // 1) command line string
    //search documents for string
    //print documents ID
    // 1.5) author hash table
    // 2) search query, defining the AUTHOR word, the NOT word. user input handling
    // 3) wants we get that and it works, then we do user interface, allow them to reset console, reset search, etc etc
    // 4) index persistance
    // 5)
    if(argc == 3){
        treeContains(allWords, searchWord);
    }
    allWords.emptyTree();
    return 0;
}
