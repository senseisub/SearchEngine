//
// Created by Brandon Herman on 11/15/20.
//
#include "InnerDoc.h"

InnerDoc::InnerDoc(){
    documentID = "";
    relativeFreq = 0;
    ratio = 0;
}

InnerDoc::InnerDoc(string& documentID, string& documentTitle, string& firstAuthor) {
    this->documentID = documentID;
    this->documentTitle = documentTitle;
    this->firstAuthor = firstAuthor;
    relativeFreq = 1; //same thing with word file, if it has a documentID, it should have atleast one freq right?
    ratio = 0;
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

void InnerDoc::setRatio (int wordFreq){
    this->ratio = this->relativeFreq/(double)wordFreq;
}

double InnerDoc::getRatio() {
    return this->ratio;
}

int InnerDoc::getFreq() {
    return this->relativeFreq;
}

void InnerDoc::setRatioPrecise(double ratio) {
    this->ratio = ratio;
}

string& InnerDoc::getTitle() {
    return this->documentTitle;
}

string& InnerDoc::getAuthor() {
    return this->firstAuthor;
}