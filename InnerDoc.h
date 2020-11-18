//
// Created by Brandon Herman on 11/15/20.
//

#ifndef SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
#define SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
#include "AVLTree.h"

class InnerDoc {
private:
    int relativeFreq;
    string documentID;
public:
    InnerDoc();
    InnerDoc(string& documentID);
    void increaseRelativeFreq();
    bool operator<(const InnerDoc& rhs) const;
    bool operator>(const InnerDoc& rhs) const;
    bool operator<(const string& rhs) const;
    bool operator>(const string& rhs) const;
    bool operator == (const InnerDoc& doc) const;
    bool operator == (const string& documentName) const;
};


#endif //SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
