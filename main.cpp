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
    }
    HashTable<string, Author*> authors(19999);
    HashSet<string> stopWords(499);
    ofstream persistentFile("../persistentFile.txt");
    AVLTree<Word> allWords;
    AVLTree<StopWordAssociation> stopWordAssociation;
    ifstream stopWordFile("../stopWords.txt");
    loadStopWords(stopWordFile, stopWords);
    fileParser(stopWords, allWords, stopWordAssociation, authors, directory);
//    cout << "number of words : " << allWords.getSize() << endl;
//    cout << "number of stops : " << stopWordAssociation.getSize() << endl;
    cout << "Number of accessible authors : " << authors.getSize() << endl;
//    cout << "number of words that are stops : " << stopWords.getSize() << endl;
    cout << "Available keywords: AND, OR, NOT, AUTHOR" << endl;
    cout << "Please enter your search query:" << endl;
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
        treeContains(allWords, searchWord, directory);
    }
    else{
//        getAuthor(authors);
//        getANDFromConsole(allWords);
        primaryOperatorProcessor(allWords, authors);
//        getORFromConsole(allWords);
//        getAUTHORFromConsole(allWords, authors);

    }
    allWords.forWords();
    stopWordAssociation.emptyTree();
    authors.emptyAVLs();
    stopWords.emptyAVLs();
//    showBasicInputUI();
    return 0;
}
