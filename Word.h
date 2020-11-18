//
// Created by Brandon Herman on 11/15/20.
//

#ifndef SEARCH_ENGINE_PLUSPLUS_WORD_H
#define SEARCH_ENGINE_PLUSPLUS_WORD_H
#include "AVLTree.h"
#include "InnerDoc.h"
class Word {
private:
    string word;
    int freq; //frequency of words in all documents
    AVLTree<InnerDoc> docTree;

public:
    Word();
    Word(string& newWord);
    void increaseFreq();
    string getWord();
    int getFreq();
    void setWord(string newWord);
    void insertDoc(InnerDoc& doc);
    void newDoc(string& documentID);
    bool hasDocument(string& documentID);
    void increaseDocumentFrequency(string& documentID);
    InnerDoc& getDocument(string& documentID);
    bool operator == (const string& word) const;
    bool operator == (const Word& word) const;
    bool operator > (const Word& word) const;
    bool operator < (const Word& word) const;
    bool operator > (const string& word) const;
    bool operator < (const string& word) const;
};


#endif //SEARCH_ENGINE_PLUSPLUS_WORD_H
