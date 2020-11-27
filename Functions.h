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

using namespace std;
#ifndef SEARCHENGINETEMPLATES_FUNCTIONS_H
#define SEARCHENGINETEMPLATES_FUNCTIONS_H
int fileParser(HashSet<string>& set, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations, HashTable<string, Author*>& authors, char*& directory);
void loadStopWords(ifstream& stops, HashSet<string>& stopWords);
void createPersistentFile(ofstream& persistentIndex, AVLTree<Word>& words);
bool treeContains(AVLTree<Word>& words, char*& searchWord, char*& directory);
bool getAuthor(HashTable<string, Author*>& authors);
void ANDProcessor(AVLTree<Word>& words, vector<Word>& wordVector);
void getANDFromConsole(AVLTree<Word>& words);
void ORProcessor(AVLTree<Word>& words, vector<Word>& wordVector);
void getORFromConsole(AVLTree<Word>& words);
void showBasicInputUI();
void clearConsole();
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
