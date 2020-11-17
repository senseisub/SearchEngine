//
// Created by seuns on 11/17/2020.
//
#include <iostream>
#include <fstream>
#include "stdc++.h"
#include "AVLTree.h"


using namespace std;
#ifndef SEARCHENGINETEMPLATES_FUNCTIONS_H
#define SEARCHENGINETEMPLATES_FUNCTIONS_H
void fileParser(unordered_set<string>& set, AVLTree<string>& words);
void loadStopWords(ifstream& stops, unordered_set<string>& stopWords);
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
