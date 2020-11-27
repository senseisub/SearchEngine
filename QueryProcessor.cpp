//
// Created by seuns on 11/26/2020.
//

#include "Functions.h"

void getANDFromConsole(AVLTree<Word>& words){
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<Word> wordList;
    do{
      string singleWord;
      ss >> singleWord;
      if(words.contains(singleWord) && singleWord.size() > 1)
          wordList.push_back(words.getValue(singleWord));
    }while(ss);
    if(wordList.size() == 0)
        cout << "nothing" << endl;
    else
        ANDProcessor(words, wordList);
}

double getMaxRatio(list<double>& docs){
    double max = 0;
    for (list<double>::iterator i = docs.begin();
         i != docs.end();
         i++){
        if((*i) > max)
            max = (*i);
    }
    return max;
}

void ANDProcessor(AVLTree<Word>& words, vector<Word>& wordVector){
    vector<InnerDoc> documentsVector = wordVector.at(0).getDocTreeInOrder();
    list<InnerDoc> sortedList;
    for(InnerDoc& doc : documentsVector){
        list<double> tempList;
        for(Word& word : wordVector){
            if(word.hasDocument(doc.getID())){
                InnerDoc wordDoc = word.getDocument(doc.getID());
                tempList.push_back(wordDoc.getRatio());
            }
        }
        if(tempList.size() == wordVector.size()){
            doc.setRatioPrecise(getMaxRatio(tempList));
            if(sortedList.size() == 0){
                sortedList.push_back(doc);
                continue;
            }
            bool exist = false;
            for (list<InnerDoc>::iterator i = sortedList.begin();
                 i != sortedList.end();
                 i++){

                if(( doc.getRatio() > (*i).getRatio())){
                    sortedList.insert(i, doc);
                    exist = true;
                    break;
                }
            }
            if(!exist)
                sortedList.push_back(doc);
        }
    }
    int size= 0;
    for (list<InnerDoc>::iterator i = sortedList.begin();
         i != sortedList.end();
         i++){
        size++;
        cout << (*i).getID() << endl;
        if(size == 15)
            break;
    }
}

void ORProcessor(AVLTree<Word>& words, vector<Word>& wordVector){
    list<InnerDoc> sortedList;
    for(Word& word : wordVector)
        cout << word.getWord() << endl;
    for(Word& word : wordVector){
        vector<InnerDoc> documentsVector = word.getDocTreeInOrder();
        for(InnerDoc& doc : documentsVector){
            if(sortedList.size() == 0){
                sortedList.push_back(doc);
                continue;
            }
            bool exist = false;
            for (list<InnerDoc>::iterator i = sortedList.begin();
                 i != sortedList.end();
                 i++){

                if(( doc.getRatio() > (*i).getRatio())){
                    sortedList.insert(i, doc);
                    exist = true;
                    break;
                }
            }
            if(!exist)
                sortedList.push_back(doc);
        }

    }
    int size= 0;
    for (list<InnerDoc>::iterator i = sortedList.begin();
         i != sortedList.end();
         i++){
        size++;
        cout << (*i).getID() << endl;
        if(size == 15)
            break;
    }
}
void getORFromConsole(AVLTree<Word>& words){
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<Word> wordList;
    do{
        string singleWord;
        ss >> singleWord;
        if(words.contains(singleWord) && singleWord.size() > 1)
            wordList.push_back(words.getValue(singleWord));
    }while(ss);
    if(wordList.size() == 0)
        cout << "nothing" << endl;
    else
        ORProcessor(words, wordList);
}