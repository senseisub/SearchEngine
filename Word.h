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
    Word(string newWord);
    void increaseFreq();
    string getWord();
    int getFreq();
    void setWord(string newWord);

};


#endif //SEARCH_ENGINE_PLUSPLUS_WORD_H
