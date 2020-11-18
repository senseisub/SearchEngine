//
// Created by seuns on 11/17/2020.
//

#include "StopWordAssociation.h"

StopWordAssociation::StopWordAssociation() {

}

StopWordAssociation::StopWordAssociation(string& word, string& wordAssociation) {
    this->word = word;
    this->wordAssociation = wordAssociation;
}

bool StopWordAssociation::operator < (const StopWordAssociation& stopWordAssociation) const{
    return this->word.compare(stopWordAssociation.word)  < 0 ? true : false;
}

bool StopWordAssociation::operator > (const StopWordAssociation& stopWordAssociation) const{
    return this->word.compare(stopWordAssociation.word)  > 0 ? true : false;
}

bool StopWordAssociation::operator == (const StopWordAssociation& stopWordAssociation) const{
    return this->word.compare(stopWordAssociation.word)  == 0 ? true : false;
}

bool StopWordAssociation::operator == (const string& stopWordAssociation) const{
    return this->word.compare(stopWordAssociation)  == 0 ? true : false;
}

bool StopWordAssociation::operator > (const string& stopWordAssociation) const{
    return this->word.compare(stopWordAssociation)  > 0 ? true : false;
}
bool StopWordAssociation::operator < (const string& stopWordAssociation) const{
    return this->word.compare(stopWordAssociation)  < 0 ? true : false;
}

void StopWordAssociation::setWord(string& word){
    this->word = word;
}
void StopWordAssociation::setWordAssociation(string& wordAssociation){
    this->wordAssociation = wordAssociation;
}

string& StopWordAssociation::getWord(){
    return this->word;
}
string& StopWordAssociation::getWordAssociation(){
    return this->wordAssociation;
}