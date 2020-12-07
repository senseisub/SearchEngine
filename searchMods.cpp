//
// Created by Brandon Herman on 11/24/2020.
//
#include "Functions.h"


void defineMods(string searchQuery) { //excludes author
    bool NOT = false;
    bool AND = false;
    bool OR = false;
    string notMod = "NOT";
    string andMod = "AND";
    string orMod = "OR";
    if (searchQuery.find(notMod) != string::npos) {
        NOT = true;
    } if (searchQuery.find(andMod) != string::npos) {
        AND = true;
    } if (searchQuery.find(orMod) != string::npos) {
        OR = true;
    }

    //and used both other words and search terms. must include both
    // or searches for one that contains one or the other
    // not searches for articles without that word

}

int partition(vector<Word>& data, int i, int j) {
    int low = i;
    int high = j;
    int midpoint = i + (high - low)/2;
    bool done = false;
    if(data[low].getFreq() > data[midpoint].getFreq()){
        Word temp = data[low];
        data[low] = data[midpoint];
        data[midpoint] = temp;
    }
    if(data[high].getFreq() < data[low].getFreq()){
        Word temp = data[low];
        data[low] = data[high];
        data[high] = temp;
    }
    if(data[high].getFreq() < data[midpoint].getFreq()){
        Word temp = data[high];
        data[high] = data[midpoint];
        data[midpoint] = temp;
    }

    while(!done){
        while(data[low].getFreq() < data[midpoint].getFreq()){
            low++;
        }
        while(data[high].getFreq() > data[midpoint].getFreq()){
            high--;
        }
        if(high <= low){
            done = true;
        }
        else{
            Word temp = data[low];
            data[low] = data[high];
            data[high] = temp;
            high--;
            low++;
        }
    }

    return high;
}

void Quicksorter(vector<Word>& data, int i, int j) {
    if(i >= j){
        return;
    }
    int m = partition(data, i, j);
    Quicksorter(data, i, m);
    Quicksorter(data, m+1, j);
}





void outputStatistics(AVLTree<Word>& words, HashTable<string, Author*>& authors, int& numberOfDocs){
    vector<Word> sortedWords(words.toArrayInOrder());
    Quicksorter(sortedWords, 0, sortedWords.size()-1);
    cout << "Number of articles parsed: " << numberOfDocs << endl;
    cout << "Average words per article: " << ((double)words.getSize()) / ((double)numberOfDocs) << endl;
    cout << "Number of parsed words: " << words.getSize() << endl;
    cout << "Number of authors: " << authors.getSize() << endl;
    cout << "Top 50 most frequent words: " << endl << "\t";
    for(int i = sortedWords.size() -1; i >= (sortedWords.size() - 50); i--){
        if(i % 10 == 0)
            cout << endl << "\t";
        if(sortedWords[i].getWord().size() > 2)
            cout << (sortedWords[i].getWord()) << ", ";
    }
}