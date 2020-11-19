#include <iostream>
#include "AVLTree.h"
#include "Author.h"
#include "Functions.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    ofstream persistentFile("../persistentFile.txt");
    HashTable authors(20000);
    unordered_set<string> stopWords;
    AVLTree<Word> allWords;
    AVLTree<StopWordAssociation> stopWordAssociation;
    ifstream stopWordFile("../stopWords.txt");
    loadStopWords(stopWordFile, stopWords);
    fileParser(stopWords, allWords, stopWordAssociation, authors);
    cout << "number of words : " << allWords.getSize() << endl;
    cout << "number of stops : " << stopWordAssociation.getSize() << endl;
    cout << "number of authors : " << authors.getSize() << endl;
    cout << "number of words that are stops : " << stopWords.size() << endl;
    cout << "type of avltree : " << typeid(allWords).name() << endl;
    createPersistentFile(persistentFile, allWords);
    allWords.emptyTree();
    return 0;
}
