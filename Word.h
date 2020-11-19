//
// Created by Brandon Herman on 11/15/20.
//

#ifndef SEARCH_ENGINE_PLUSPLUS_WORD_H
#define SEARCH_ENGINE_PLUSPLUS_WORD_H
#include "AVLTree.h"
#include "InnerDoc.h"
#include <vector>
class Word {
private:
    //the word being saved
    string word;
    //numbers of appearances in all documents
    int freq; //frequency of words in all documents
    //tree of documents
    AVLTree<InnerDoc> docTree;

public:
    Word();
    //the only constructor to be used
    Word(string& newWord);
    //utility function to increase frequency
    void increaseFreq();
    //getters
    string getWord();
    int getFreq();
    InnerDoc& getDocument(string& documentID);
    //setters
    void setWord(string newWord);
    //inserts new document
    void insertDoc(InnerDoc& doc);
    //creates new document based on string
    void newDoc(string& documentID);
    //checks if docTree has document
    bool hasDocument(string& documentID);
    //increases the frequency count of certain document
    void increaseDocumentFrequency(string& documentID);
    vector<InnerDoc> getDocTreeInOrder();
    //overloaded operators for AVLTree sorting
    bool operator == (const string& word) const;
    bool operator == (const Word& word) const;
    bool operator > (const Word& word) const;
    bool operator < (const Word& word) const;
    bool operator > (const string& word) const;
    bool operator < (const string& word) const;
};


#endif //SEARCH_ENGINE_PLUSPLUS_WORD_H
