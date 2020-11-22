//
// Created by Oluwaseun Suberu on 11/22/20.
//
#include <iostream>
#include "AVLTree.h"
using namespace std;
#ifndef SEARCHENGINETEMPLATES_HASHSET_H
#define SEARCHENGINETEMPLATES_HASHSET_H
template <typename t>
class HashSet{
    private:
        AVLTree<t>* table;
        int size;
        int amountOfBuckets;
    public:
        HashSet(){
            amountOfBuckets = 10;
            table = new AVLTree<t>[amountOfBuckets];
            size = 0;
        }
        HashSet(int size){
            amountOfBuckets = size;
            table = new AVLTree<t>[amountOfBuckets];
            size = 0;
        }
        //default insert function, checks for the variable type
        void insert(const t& value){
            long long int hash = 0;
            if (strcmp(typeid(value).name(), "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") ==0) {
                hash = compute_hash(value);
            }
            else {
                std::hash<t> hasher;
                hash = hasher(value);
            }
            int index = hashFunction(hash);
            table[index].insert(value);
            this->size++;
        }

        //stringer hasher
        long long int compute_hash(const t& s) { //found on the internet (https://cp-algorithms.com/string/string-hashing.html)
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
        int hashFunction(long long int& x) {
            return (x % amountOfBuckets);
        }

        //returns number of elements
        int getSize(){
            return this->size;
        }

        //checks if author exists
        bool contains(const t& value){
            long long int hash = 0;
            if (strcmp(typeid(value).name(), "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") ==0)
                hash = compute_hash(value);
            else {
                std::hash<t> hasher;
                hash = hasher(value);
            }
            int index = hashFunction(hash);
            return table[index].containsForSet(value);
        }

        void emptyAVLs(){
            for(int i = 0; i < amountOfBuckets; i++){
                table[i].emptyTree();
            }
        }
};
#endif //SEARCHENGINETEMPLATES_HASHSET_H
