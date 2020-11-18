//
// Created by Brandon Herman on 11/16/20.
//
#include <iostream>
using namespace std;
//https://cp-algorithms.com/string/string-hashing.html
#ifndef SEARCH_ENGINE_PLUSPLUS_HASHTABLE_H
#define SEARCH_ENGINE_PLUSPLUS_HASHTABLE_H
#include <iostream>
#include "AVLTree.h"
#include "Author.h"

class HashTable {
private:
    int amountOfBuckets;
    AVLTree<Author>* table = nullptr; //initalized to nullptr;

public:
    HashTable();
    HashTable(int buckets);
    ~HashTable();

    void insertAuthor(Author& name); //inserts author to hash table

    void deleteAuthor(Author& nameToBeDeleted); //deletes based on name

    void deleteAuthor(int position); //deletes based on position

    int hashFunction(int x); //returns mod of the hash

    long long int compute_hash(string s); //hashing algorithm from internet

    Author& searchForAuthor(string authorName); //search for author based on the name, return reference author

    bool containsAuthor(string& authorName);
};

#endif //SEARCH_ENGINE_PLUSPLUS_HASHTABLE_H
