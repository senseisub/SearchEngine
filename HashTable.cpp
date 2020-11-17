//
// Created by Brandon Herman on 11/17/20.
//

#include "HashTable.h"

HashTable::HashTable() {
    amountOfBuckets = 10;
    table = new AVLTree<Author>[amountOfBuckets];
}

HashTable::HashTable(int buckets) {
    amountOfBuckets = buckets;
    table = new AVLTree<Author>[amountOfBuckets];
}

HashTable::~HashTable() {
    delete table;
}

void HashTable::insertAuthor(Author& name) {
    long long int hash = compute_hash(name.getAuthorName());
    int index = hashFunction(hash);
    table[index].insert(name);
}

void HashTable::deleteAuthor(int position) {

}

void HashTable::deleteAuthor(Author &nameToBeDeleted) {


}

long long int HashTable::compute_hash(string s) { //found on the internet (https://cp-algorithms.com/string/string-hashing.html)
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

int HashTable::hashFunction(int x) {
    return (x % amountOfBuckets);
}

Author& HashTable::searchForAuthor(string authorName) { //searches through tree and returns the author
    long long int hash = compute_hash(authorName);
    int index = hashFunction(hash);
    bool contains = table[index].contains(authorName);
    if (contains) {
        table[index].getValue(authorName);
    } else {
        cout << "No author in tree" << endl;
    }
}