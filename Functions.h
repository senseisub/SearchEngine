//
// Created by seuns on 11/17/2020.
//
#include <iostream>
#include <fstream>
#include <bits/unordered_set.h>

using namespace std;
#ifndef SEARCHENGINETEMPLATES_FUNCTIONS_H
#define SEARCHENGINETEMPLATES_FUNCTIONS_H
void fileParser();
void loadStopWord(ifstream& stops, unordered_set<string>& stopWords);
#endif //SEARCHENGINETEMPLATES_FUNCTIONS_H
