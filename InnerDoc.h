//
// Created by Brandon Herman on 11/15/20.
//

#ifndef SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
#define SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
#include "AVLTree.h"

class InnerDoc {
private:
    //amount of times word parent shows up in this particular document
    int relativeFreq;
    //documentID for identification
    string documentID;
public:
    InnerDoc();
    //the constructor that will be used
    InnerDoc(string& documentID);
    //utility function to increase frequency when the same word shows up again in the same document
    void increaseRelativeFreq();
    //overloaded operators for AVLTree sorting
    bool operator<(const InnerDoc& rhs) const;
    bool operator>(const InnerDoc& rhs) const;
    bool operator<(const string& rhs) const;
    bool operator>(const string& rhs) const;
    bool operator == (const InnerDoc& doc) const;
    bool operator == (const string& documentName) const;
};


#endif //SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
