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


using namespace std;
#ifndef SEARCHENGINETEMPLATES_FUNCTIONS_H
#define SEARCHENGINETEMPLATES_FUNCTIONS_H
int fileParser(HashSet<string>& set, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, HashTable<string, Author*>& authors, char*& directory);
void loadStopWords(ifstream& stops, HashSet<string>& stopWords);
void createPersistentFile(ofstream& persistentIndex, AVLTree<Word>& words);
bool treeContains(AVLTree<Word>& words, char*& searchWord, char*& directory);

// UI
void showBasicInputUI();
void clearConsole();
void getORFromConsole(AVLTree<Word>& words);
void getANDFromConsole(AVLTree<Word>& words);
void getAUTHORFromConsole(AVLTree<Word>& words, HashTable<string, Author*>& authors);

//searchMods
void defineMods(string searchquery);
    //console tests, don't put "AND" or "OR" in front of searches, only put the words you want to search seperated by spaces, With author you can only search the last name and that's it
bool getAuthor(HashTable<string, Author*>& authors);
void ANDProcessor(AVLTree<Word>& words, vector<Word>& wordVector);
void ORProcessor(AVLTree<Word>& words, vector<Word>& wordVector);
void AUTHORProcessor(AVLTree<Word>& words, vector<Word>& wordVector, string& author, HashTable<string, Author*>& authors);
void NOTOperator( list<InnerDoc>& doc, vector<Word>& wordVector);
void NOTOperator( list<Article>& doc, vector<Word>& wordVector);
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
