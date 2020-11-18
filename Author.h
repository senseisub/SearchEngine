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
        vector<Article> articles;
    public:
        Author(){}
        Author(string);
        ~Author();
        void printCopy();
        string& getAuthorName();
        vector<Article>& getArticleList();
        void addArticles(Article& article);
        bool operator < (const Author& author) const;
        bool operator > (const Author& author) const;
        bool operator < (const string& author) const;
        bool operator > (const string& author) const;
        bool operator == (const Author& author) const;
        bool operator == (const string& author) const;

    };
#endif //SEARCHENGINETEMPLATES_AUTHOR_H
