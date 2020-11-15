//
// Created by seuns on 11/12/2020.
//
#include "Article.h"
#include "vector"
#ifndef SEARCHENGINETEMPLATES_AUTHOR_H
#define SEARCHENGINETEMPLATES_AUTHOR_H
class Author{
    private:
        string name;
        vector<Article*> articles;
    public:
        Author(string);
        ~Author();
        void printCopy();
        string& getAuthorName();
        vector<Article*>& getArticleList();
        bool operator < (Author& author);
        bool operator > (Author& author);
        bool operator == (Author& author);
};
#endif //SEARCHENGINETEMPLATES_AUTHOR_H
