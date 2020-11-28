//
// Created by seuns on 11/12/2020.
//
#include "iostream"
using namespace std;
#ifndef SEARCHENGINETEMPLATES_ARTICLE_H
#define SEARCHENGINETEMPLATES_ARTICLE_H
class Article{
    private:
        string articleTitle;
        string printCopy;
        string datePublished;
        string articleID;
        double ratio;
    public:
        Article(string, string, string, string);
        Article(string, string);
        string& getPrintCopy();
        string& getTitle();
        string& getDatePub();
        string& getID();
        void setRatio(double ratio);
        double getRatio();

};
#endif //SEARCHENGINETEMPLATES_ARTICLE_H
