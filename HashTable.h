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
template <typename key, typename value>
class HashTable {
private:
    //bucket size
    int amountOfBuckets;
    //amount of objects in hashtable
    int size;
    //inner class for classing, pairs keys to values
    class Duo{
        public:
            key first;
            value second;
            Duo(const key& first, const value& second){
                this->first = first;
                this->second = second;
            }
            Duo(){}
            //operators for AVLTree
            bool operator > (const Duo& duo) const{ return (this->first > duo.first); };
            bool operator < (const Duo& duo) const{ return (this->first < duo.first); };
            bool operator == (const Duo& duo) const{ return (this->first == duo.first); };
            bool operator > (const string& duo) const{ return (this->first > duo); };
            bool operator < (const string& duo) const{ return (this->first < duo); };
            bool operator == (const string& duo) const{ return (this->first == duo); };

    };
    AVLTree<Duo>* table = nullptr; //initalized to nullptr;

public:
    //default constructor initializes table to 10 values
    HashTable() {
        amountOfBuckets = 10;
        table = new AVLTree<Duo>[amountOfBuckets];
        size = 0;
    }
    //sets amount of space in hash table
    HashTable(int buckets) {
        amountOfBuckets = buckets;
        table = new AVLTree<Duo>[amountOfBuckets];
        size = 0;
    }
    //deletes table
    ~HashTable() {
        delete[] table;
    }
    //default insert function, checks for the variable type
    void insert(const key& keyVal, const value& valueVal){
        long long int hash = 0;
        std::cout << typeid(keyVal).name() << std::endl;
        if (strcmp(typeid(keyVal).name(), "Ss") ==0)
            hash = compute_hash(keyVal);
        else {
            std::hash<key> hasher;
            hash = hasher(keyVal);
        }
        int index = hashFunction(hash);
        Duo duo(keyVal, valueVal);
        table[index].insert(duo);
        this->size++;
    }

    //specific insert type for authors
    void insertAuthor(Author& name) {
        long long int hash = compute_hash(name.getAuthorName());
        int index = hashFunction(hash);
        Duo duo(name.getAuthorName(), name);
        table[index].insert(duo);
        this->size++;
    }

    void deleteAuthor(int position) {

    }

    void deleteAuthor(Author &nameToBeDeleted) {


    }

    //stringer hasher
    long long int compute_hash(const key& s) { //found on the internet (https://cp-algorithms.com/string/string-hashing.html)
        const int p = 31;
        const int m = 1e9+9;
        long long int hash_value = 0;
        long long p_pow = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            if (isalpha(c) && c != ' ') {
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            }
            p_pow = (p_pow*p) % m;
        }
        return hash_value;
    }

    //outputs index
    int hashFunction(int x) {
        return (x % amountOfBuckets);
    }
    //searches for author
    Author& searchForAuthor(string authorName) { //searches through tree and returns the author
        long long int hash = compute_hash(authorName);
        int index = hashFunction(hash);
        bool contains = table[index].contains(authorName);
        if (contains)
            return table[index].getValue(authorName).second;
        else
            cout << "No author in tree" << endl;
    }
    //checks if author exists
    bool containsAuthor(string& authorName){
        long long int hash = compute_hash(authorName);
        int index = hashFunction(hash);
        return table[index].contains(authorName);
    }
    //get operator
    value& operator[] (const key& keyVal){
        long long int hash = 0;
        if (strcmp(typeid(keyVal).name(), "Ss") ==0)
            hash = compute_hash(keyVal);
        else {
            std::hash<key> hasher;
            hash = hasher(keyVal);
        }
        int index = hashFunction(hash);
        return table[index].getValue(keyVal).second;
    }
    //returns number of elements
    int getSize(){
        return this->size;
    }

    void emptyAVLs(){
        for(int i = 0; i < amountOfBuckets; i++){
            table[i].emptyTree();
        }
    }
};

#endif //SEARCH_ENGINE_PLUSPLUS_HASHTABLE_H
