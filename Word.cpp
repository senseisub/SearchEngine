//
// Created by Brandon Herman on 11/15/20.
//
#include "Word.h"


Word::Word() {
    freq = 0;
    word = "";
    docTree = new AVLTree<InnerDoc>();
}

Word::Word(string& newWord) {
    freq = 1; //if making word, it shows up atleast once
    word = newWord;
    docTree = new AVLTree<InnerDoc>();
}

void Word::increaseFreq() {
    freq++;
}

string Word::getWord() {
    return word;
}

int Word::getFreq() {
    return freq;
}

void Word::setWord(string newWord) {
    word = newWord;
}

bool Word::operator == (const string& word) const{
    return this->word.compare(word)  == 0 ? true : false;
}

bool Word::operator == (const Word& word) const{
    return this->word.compare(word.word)  == 0 ? true : false;
}

bool Word::operator > (const Word& word) const{
    return this->word.compare(word.word)  > 0 ? true : false;
}

bool Word::operator < (const Word& word) const{
    return this->word.compare(word.word)  < 0 ? true : false;
}

bool Word::operator > (const string& word) const{
    return this->word.compare(word)  > 0 ? true : false;
}

bool Word::operator < (const string& word) const{
    return this->word.compare(word)  < 0 ? true : false;
}

void Word::insertDoc(InnerDoc &doc) {
    docTree->insert(doc);
}

bool Word::hasDocument(string &documentID) {
    return docTree->contains(documentID);
}

void Word::increaseDocumentFrequency(string& documentID){
    InnerDoc* doc = &(docTree->getValue(documentID));
    doc->increaseRelativeFreq();
    doc->setRatio(this->getFreq());
}
InnerDoc& Word::getDocument(string& documentID){
    return docTree->getValue(documentID);
}

void Word::newDoc(string& documentID, string& documentTitle, string& firstAuthor){
    InnerDoc doc(documentID, documentTitle, firstAuthor);
    docTree->insert(doc);
};

vector<InnerDoc> Word::getDocTreeInOrder() {
    return docTree->toArrayInOrder();
}

void Word::printWordDocuments(char*& documentPath){
//    cout << docTree->getSize() << endl;
    this->docTree->inorder15(documentPath);
}

void Word::wipeDocuments() {
    this->docTree->emptyTree();
    delete docTree;
}

int Word::getDocTreeSize() {
    return docTree->getSize();
}