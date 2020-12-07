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
//Operational functions
//parses the json files using rapid json
int fileParser(HashSet<string>& set, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, HashTable<string, Author*>& authors, char*& directory);
//loads the hashset with stop words
void loadStopWords(ifstream& stops, HashSet<string>& stopWords);
//creates a persistent file
void createPersistentFile(ofstream& persistentIndex, AVLTree<Word>& words);
//test file for parsing demo
bool treeContains(AVLTree<Word>& words, char*& searchWord, char*& directory);
//prints all the statistics of the search engine
void outputStatistics(AVLTree<Word>& words, HashTable<string, Author*>& authors, int& numberOfDocs);

// UI
//shows initial search engine prompt
void showBasicInputUI();
//the main driver for the user interface
void startIndex(AVLTree<Word>& allWords, HashTable<string, Author*>& authors, char* directory, char* searchWord, int& argc);
//clears console
void clearConsole();
//test function that gets OR query from terminal
void getORFromConsole(AVLTree<Word>& words);
//test function that gets AND query from terminal
void getANDFromConsole(AVLTree<Word>& words);
//test function that gets author from terminal
void getAUTHORFromConsole(AVLTree<Word>& words, HashTable<string, Author*>& authors);
//prints the articles and the information associated with them
void printArticles(list<Article>& articles, string& author);
//prints the inner documents and the information associated with them
void printInnerDocs(list<InnerDoc>& docs);
//prints the 300 words requested by the user
void getPreview(string docName);
//prints the content of the persistent file
void printPersistentFile(ifstream& file);

//searchMods
void defineMods(string searchquery);
//test function for finding author files
bool getAuthor(HashTable<string, Author*>& authors);
//processes AND queries and lone word queries
void ANDProcessor(AVLTree<Word>& words, list<Word>& wordVector, list<InnerDoc>*& finalDocument);
//processes or queries
void ORProcessor(AVLTree<Word>& words, list<Word>& wordVector, list<InnerDoc>*& finalDocument);
//processes author queries
void AUTHORProcessor(AVLTree<Word>& words, list<Word>& wordVector, string& author, HashTable<string, Author*>& authors, list<Article>*& finalDocument);
//if any query contains the NOT operator then it immediately goes to this operator after it goes through the AND, or OR processors
void NOTOperator( list<InnerDoc>& doc, list<Word>& wordVector);
//if any query contains the NOT operator then it immediately goes to this operator after it goes through the AUTHOR processor
void NOTOperator( list<Article>& doc, list<Word>& wordVector);
//handles user input and directs the the flow of the program based on the user query
void primaryOperatorProcessor(AVLTree<Word>& words, HashTable<string, Author*>& authors);
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
