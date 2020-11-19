//
// Created by Brandon Herman on 11/15/20.
//
#include "Word.h"


Word::Word() {
    freq = 0;
    word = "";
}

Word::Word(string& newWord) {
    freq = 1; //if making word, it shows up atleast once
    word = newWord;
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
    docTree.insert(doc);
}

bool Word::hasDocument(string &documentID) {
    return docTree.contains(documentID);
}

void Word::increaseDocumentFrequency(string& documentID){
    InnerDoc doc = docTree.getValue(documentID);
    doc.increaseRelativeFreq();
}
InnerDoc& Word::getDocument(string& documentID){
    return docTree.getValue(documentID);
}

void Word::newDoc(string& documentID){
    InnerDoc doc(documentID);
    docTree.insert(doc);
};

vector<InnerDoc> Word::getDocTreeInOrder(){
    return docTree.toArrayInOrder();
}