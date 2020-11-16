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
    InnerDoc(string documentID);
    void increaseRelativeFreq();
    bool AVLTree<InnerDoc>::operator<(InnerDoc& rhs);
    bool AVLTree<InnerDoc>::operator>(InnerDoc& rhs);
};


#endif //SEARCH_ENGINE_PLUSPLUS_INNERDOC_H
