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
        Porter2Stemmer::stem(singleWord);
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
        Porter2Stemmer::stem(singleWord);
        if(words.contains(singleWord) && singleWord.size() > 1)
            wordList.push_back(words.getValue(singleWord));
    }while(ss);
    if(wordList.size() == 0)
        cout << "nothing" << endl;
    else
        ORProcessor(words, wordList);
}

void getAUTHORFromConsole(AVLTree<Word>& words, HashTable<string, Author*>& authors){
    string userInput;
    getline(cin, userInput);
    int place = 1;
    istringstream ss(userInput);
    vector<Word> wordList;
    string author;
    do{
        string singleWord;
        ss >> singleWord;
        if(place == 1)
            author = singleWord;
        else
            Porter2Stemmer::stem(singleWord);
            if(words.contains(singleWord) && singleWord.size() > 1)
                wordList.push_back(words.getValue(singleWord));
        place++;
    }while(ss);
    if(wordList.size() == 0){
        if(authors.containsAuthor(author)){
            Author currentAuthor = *authors[author];
            cout << "Current Author : " << currentAuthor.getAuthorName() << endl;
            for(Article& a : currentAuthor.getArticleList()){
                cout  <<a.getID() << endl;
            }
        }
        else
            cout << "Author doesn't exist" << endl;
    }
    else{
        if(authors.containsAuthor(author)){
            AUTHORProcessor(words, wordList, author, authors);
        }
        else
            cout << "Author doesn't exist" << endl;
    }

}

void AUTHORProcessor(AVLTree<Word>& words, vector<Word>& wordVector, string& author, HashTable<string, Author*>& authors){
    list<Article> sortedList;
    Author currentAuthor = *authors[author];
    for(Article& a : currentAuthor.getArticleList()){
        list<double> tempList;
        for(Word& word : wordVector){
            if(word.hasDocument(a.getID())){
                InnerDoc wordDoc = word.getDocument(a.getID());
                tempList.push_back(wordDoc.getRatio());
            }
        }
        if(tempList.size() == wordVector.size()){
            a.setRatio(getMaxRatio(tempList));
            if(sortedList.size() == 0){
                sortedList.push_back(a);
                continue;
            }
            bool exist = false;
            for (list<Article>::iterator i = sortedList.begin();
                 i != sortedList.end();
                 i++){

                if(( a.getRatio() > (*i).getRatio())){
                    sortedList.insert(i, a);
                    exist = true;
                    break;
                }
            }
            if(!exist)
                sortedList.push_back(a);
        }
    }
    int size= 0;
    for (list<Article>::iterator i = sortedList.begin();
         i != sortedList.end();
         i++){
        size++;
        cout << (*i).getID() << endl;
        if(size == 15)
            break;
    }
}

void NOTOperator(list<InnerDoc>& doc, vector<Word>& wordVector){
    for(list<InnerDoc>::iterator i= doc.begin(); i!= doc.end(); i++){
        InnerDoc* document = &(*(i));
        for(Word& word : wordVector){
            if(word.hasDocument(document->getID())){
                doc.erase(i);
                break;
            }
        }
    }
}
void NOTOperator( list<Article>& doc, vector<Word>& wordVector){
    for(list<Article>::iterator i= doc.begin(); i!= doc.end(); i++){
        Article* document = &(*(i));
        for(Word& word : wordVector){
            if(word.hasDocument(document->getID())){
                doc.erase(i);
                break;
            }
        }
    }
}