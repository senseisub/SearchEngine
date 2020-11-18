#include <iostream>
#include "AVLTree.h"
#include "Author.h"
#include "Functions.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(22);
    tree.insert(4);
    tree.insert(6);
    tree.insert(35);
    tree.insert(21);
    tree.insert(23);
    tree.insert(24);
    tree.inorder();
    HashTable authors(20000);
    unordered_set<string> stopWords;
    AVLTree<Word> allWords;
    AVLTree<StopWordAssociation> stopWordAssociation;
    fileParser(stopWords, allWords, stopWordAssociation);
    cout << "number of words : " << allWords.getSize() << endl;
    cout << "number of stops : " << stopWordAssociation.getSize() << endl;
    return 0;
}
