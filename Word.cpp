//
// Created by Brandon Herman on 11/15/20.
//
#include "Word.h"


Word::Word() {
    freq = 0;
    word = "";
}

Word::Word(string newWord) {
    freq = 1; //if making word, it shows up atleast once. lmk if im wrong here
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

void Word::setWord(int newWord) {
    word = newWord;
}

