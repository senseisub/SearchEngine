//
// Created by Brandon Herman on 11/15/20.
//
#include "InnerDoc.h"

InnerDoc::InnerDoc(){
    documentID = "";
    relativeFreq = 0;
}

InnerDoc::InnerDoc(string& documentID) {
    this->documentID = documentID;
    relativeFreq = 1; //same thing with word file, if it has a documentID, it should have atleast one freq right?
}
void InnerDoc::increaseRelativeFreq(){
    relativeFreq++;
}

bool InnerDoc::operator<(const InnerDoc& rhs) const{
    return this->documentID.compare(rhs.documentID)  < 0 ? true : false;
}
bool InnerDoc::operator>(const InnerDoc& rhs) const{
    return this->documentID.compare(rhs.documentID)  > 0 ? true : false;
}

bool InnerDoc::operator == (const InnerDoc& doc) const{
    return this->documentID.compare(doc.documentID)  == 0 ? true : false;
}
bool InnerDoc::operator == (const string& documentName) const{
    return this->documentID.compare(documentName)  == 0 ? true : false;
}

bool InnerDoc::operator > (const string& documentName) const{
    return this->documentID.compare(documentName)  > 0 ? true : false;
}

bool InnerDoc::operator < (const string& documentName) const{
    return this->documentID.compare(documentName)  < 0 ? true : false;
}

string& InnerDoc::getID() {
    return this->documentID;
}