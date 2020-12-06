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
    cout << numberOfDocs << endl;
    createPersistentFile(persistentFile, allWords);
//    cout << "number of words : " << allWords.getSize() << endl;
//    cout << "number of stops : " << stopWordAssociation.getSize() << endl;
    bool loop = true;
    while (loop) {
    cout << "Number of accessible authors : " << authors.getSize() << endl;
//    cout << "number of words that are stops : " << stopWords.getSize() << endl;
    cout << "Available keywords: AND, OR, NOT, AUTHOR" << endl;
    cout << "Please enter your search query:" << endl;
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
    cout << "\nWould you like to search again?" << endl;
    cout << "Y / N or clear: " << endl;
    string decision;
    cin.ignore();

    bool loop2 = false;
    while (loop2 == false) { //loop that waits for a Y/N/clear command. anything else returns invalid.
        getline(cin, decision);
    if (decision == "N" || decision == "no" || decision == "No" || decision == "n") {
        loop = false;
        break;
    }
    if (decision == "clear") {
        clearConsole();
        cout << "\nWould you like to search again?" << endl;
        cout << "Y / N:" << endl;
    }
    if (decision == "Yes" || decision == "y" || decision == "yes" || decision == "YES" || decision == "Y"){
        loop2 = true;
    }
    else {
        cout << "\nInvalid command. Please enter Y / N : \n";
    }
    }
    }
    outputStatistics(allWords, authors, numberOfDocs);
    allWords.forWords();
    stopWordAssociation.emptyTree();
    authors.emptyAVLs();
    stopWords.emptyAVLs();
//    showBasicInputUI();
    return 0;
}
