//
// Created by seuns on 11/19/2020.
//

#include "Functions.h"

void createPersistentFile(ofstream& persistentIndex, AVLTree<Word>& words){
    persistentIndex << "start" << endl;
    vector<Word> wordList(words.toArrayInOrder());
    cout << "vector1 size: " << wordList.size() << endl;
    for(Word& currentWord : wordList){
        persistentIndex << currentWord.getWord() << ": ";
        vector<InnerDoc> docList = currentWord.getDocTreeInOrder();
        int size = 1;
        for(InnerDoc& doc : docList){
            if(size == docList.size())
                persistentIndex << doc.getID() ;
            else
                persistentIndex << doc.getID() << ", ";
            size++;
        }
        persistentIndex << endl;
    }
    persistentIndex.close();
}
