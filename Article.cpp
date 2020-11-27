//
// Created by seuns on 11/12/2020.
//

#include "Article.h"
Article::Article(string articleTitle, string printCopy, string datePublished, string articleID){
    this->articleID = articleID;
    this->printCopy = printCopy;
    this->datePublished = datePublished;
    this->articleTitle = articleTitle;
}

Article::Article(string articleTitle, string articleID){
    this->articleID = articleID;
    this->articleTitle = articleTitle;
}

string& Article::getPrintCopy(){
    return this->printCopy;
}
string& Article::getTitle(){
    return this->getTitle();
}
string& Article::getDatePub(){
    return this->getDatePub();
}
string& Article::getID(){
    return this->articleID;
}