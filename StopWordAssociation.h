//
// Created by seuns on 11/17/2020.
//
#include <iostream>
using namespace std;
#ifndef SEARCHENGINETEMPLATES_STOPWORDASSOCIATION_H
#define SEARCHENGINETEMPLATES_STOPWORDASSOCIATION_H
class StopWordAssociation{
    private:
        string word;
        string wordAssociation;
    public:
        StopWordAssociation();
        StopWordAssociation(string& word, string& wordAssociation);
        void setWord(string& word);
        void setWordAssociation(string& wordAssociation);
        string& getWord();
        string& getWordAssociation();
        bool operator < (const StopWordAssociation& stopWordAssociation) const;
        bool operator > (const StopWordAssociation& stopWordAssociation) const;
        bool operator < (const string& stopWordAssociation) const;
        bool operator > (const string& stopWordAssociation) const;
        bool operator == (const StopWordAssociation& stopWordAssociation) const;
        bool operator == (const string& stopWordAssociation) const;
};
#endif //SEARCHENGINETEMPLATES_STOPWORDASSOCIATION_H
