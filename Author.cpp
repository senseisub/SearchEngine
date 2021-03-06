//
// Created by seuns on 11/12/2020.
//

#include "Author.h"

Author::Author(string authorName){
    this->name = authorName;
    articles = new vector<Article>();
}

void Author::printCopy(){

}
string& Author::getAuthorName(){
    return this->name;
}
vector<Article>& Author::getArticleList(){
    return *(this->articles);
}
bool Author::operator < (const Author& author) const{
    return this->name.compare(author.name)  < 0 ? true : false;
}

bool Author::operator > (const Author& author) const{
    return this->name.compare(author.name)  > 0 ? true : false;
}

bool Author::operator == (const Author& author) const{
    return this->name.compare(author.name)  == 0 ? true : false;
}

void Author::addArticles(Article& article) {
    this->articles->push_back(article);
}

bool Author::operator == (const string& author) const{
    return this->name.compare(author)  == 0 ? true : false;
}

bool Author::operator < (const string& author) const{
    return this->name.compare(author) < 0 ? true : false;
}

bool Author::operator > (const string& author) const{
    return this->name.compare(author) > 0 ? true : false;
}


void Author::deleteVector() {
//    for(Article*& a : *articles){
//        if(a != nullptr){
//            delete a;
//            a = nullptr;
//
//        }
//    }
    delete articles;
}