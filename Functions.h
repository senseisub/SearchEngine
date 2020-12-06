//
// Created by seuns on 11/17/2020.
//
#include <iostream>
#include "AVLTree.h"
#include "Word.h"
#include "StopWordAssociation.h"
#include "HashTable.h"
#include "HashSet.h"
#include "stdc++.h"
#include <unordered_set>
#include <fstream>
#include "porter2_stemmer.h"
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include <dirent.h>
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filereadstream.h"
#include <ctype.h>
#include "rapidjson/include/rapidjson/istreamwrapper.h"


using namespace std;
#ifndef SEARCHENGINETEMPLATES_FUNCTIONS_H
#define SEARCHENGINETEMPLATES_FUNCTIONS_H
int fileParser(HashSet<string>& set, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, HashTable<string, Author*>& authors, char*& directory, int& numberOfDocs);
void loadStopWords(ifstream& stops, HashSet<string>& stopWords);
void createPersistentFile(ofstream& persistentIndex, AVLTree<Word>& words);
bool treeContains(AVLTree<Word>& words, char*& searchWord, char*& directory);
void outputStatistics(AVLTree<Word>& words, HashTable<string, Author*>& authors, int& numberOfDocs);
// UI
void showBasicInputUI();
void startIndex(AVLTree<Word>& allWords, HashTable<string, Author*>& authors, char* directory, char* searchWord, int& argc);
void clearConsole();
void getORFromConsole(AVLTree<Word>& words);
void getANDFromConsole(AVLTree<Word>& words);
void getAUTHORFromConsole(AVLTree<Word>& words, HashTable<string, Author*>& authors);
void printArticles(list<Article>& articles, string& author);
void printInnerDocs(list<InnerDoc>& docs);
void getPreview(string docName);
//searchMods
void defineMods(string searchquery);
    //console tests, don't put "AND" or "OR" in front of searches, only put the words you want to search seperated by spaces, With author you can only search the last name and that's it
bool getAuthor(HashTable<string, Author*>& authors);
void ANDProcessor(AVLTree<Word>& words, list<Word>& wordVector, list<InnerDoc>*& finalDocument);
void ORProcessor(AVLTree<Word>& words, list<Word>& wordVector, list<InnerDoc>*& finalDocument);
void AUTHORProcessor(AVLTree<Word>& words, list<Word>& wordVector, string& author, HashTable<string, Author*>& authors, list<Article>*& finalDocument);
void NOTOperator( list<InnerDoc>& doc, list<Word>& wordVector);
void NOTOperator( list<Article>& doc, list<Word>& wordVector);
void primaryOperatorProcessor(AVLTree<Word>& words, HashTable<string, Author*>& authors);
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
