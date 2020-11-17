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
        Author(){}
        Author(string);
        ~Author();
        void printCopy();
        string& getAuthorName();
        vector<Article*>& getArticleList();
        bool operator < (const Author& author) const;
        bool operator > (const Author& author) const;
        bool operator == (const Author& author) const;
};
#endif //SEARCHENGINETEMPLATES_AUTHOR_H
