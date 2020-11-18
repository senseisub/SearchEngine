//
// Created by seuns on 11/17/2020.
//
#include <iostream>
using namespace std;
#ifndef SEARCHENGINETEMPLATES_STOPWORDASSOCIATION_H
#define SEARCHENGINETEMPLATES_STOPWORDASSOCIATION_H
//for pairing whole words with their stemmed equivalents
class StopWordAssociation{
    private:
        //whole word
        string word;
        //stemmed equivalent
        string wordAssociation;
    public:
        StopWordAssociation();
        //intializes both word and wordAssociation, the only constructor that will be used
        StopWordAssociation(string& word, string& wordAssociation);
        //setters
        void setWord(string& word);
        void setWordAssociation(string& wordAssociation);
        //getters
        string& getWord();
        string& getWordAssociation();
        //overloaded operators for AVLTree sorting
        bool operator < (const StopWordAssociation& stopWordAssociation) const;
        bool operator > (const StopWordAssociation& stopWordAssociation) const;
        bool operator < (const string& stopWordAssociation) const;
        bool operator > (const string& stopWordAssociation) const;
        bool operator == (const StopWordAssociation& stopWordAssociation) const;
        bool operator == (const string& stopWordAssociation) const;
};
#endif //SEARCHENGINETEMPLATES_STOPWORDASSOCIATION_H
