//
// Created by seuns on 11/17/2020.
//
#include <iostream>
#include <fstream>
#include "stdc++.h"
#include "AVLTree.h"
#include "Word.h"
#include "StopWordAssociation.h"
#include "HashTable.h"
using namespace std;
#ifndef SEARCHENGINETEMPLATES_FUNCTIONS_H
#define SEARCHENGINETEMPLATES_FUNCTIONS_H
int fileParser(unordered_set<string>& set, AVLTree<Word>& words, AVLTree<StopWordAssociation>& stopWordAssociations);
void loadStopWords(ifstream& stops, unordered_set<string>& stopWords);
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
