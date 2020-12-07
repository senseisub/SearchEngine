//
// Created by seuns on 11/26/2020.
//

#include "Functions.h"

void getANDFromConsole(AVLTree<Word>& words){
    string line;
    getline(cin, line);
    istringstream ss(line);
    list<Word> wordList;
    do{
      string singleWord;
      ss >> singleWord;
        Porter2Stemmer::stem(singleWord);
        if(words.contains(singleWord) && singleWord.size() > 1)
          wordList.push_back(words.getValue(singleWord));
    }while(ss);
    list<InnerDoc>* finalDocs = nullptr;
    if(wordList.size() == 0)
        cout << "nothing" << endl;
    else
        ANDProcessor(words, wordList, finalDocs);
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

void ANDProcessor(AVLTree<Word>& words, list<Word>& wordVector, list<InnerDoc>*& finalDocument){
    vector<InnerDoc> documentsVector = (*wordVector.begin()).getDocTreeInOrder();
    list<InnerDoc>* sortedList = new list<InnerDoc>();
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
            if(sortedList->size() == 0){
                sortedList->push_back(doc);
                continue;
            }
            bool exist = false;
            for (list<InnerDoc>::iterator i = sortedList->begin();
                 i != sortedList->end();
                 i++){

                if(( doc.getRatio() > (*i).getRatio())){
                    sortedList->insert(i, doc);
                    exist = true;
                    break;
                }
            }
            if(!exist)
                sortedList->push_back(doc);
        }
    }
    int size= 0;
    for (list<InnerDoc>::iterator i = sortedList->begin();
         i != sortedList->end();
         i++){
        size++;
        cout << (*i).getID() << endl;
        if(size == 15)
            break;
    }

    finalDocument = sortedList;
}

void ORProcessor(AVLTree<Word>& words, list<Word>& wordVector, list<InnerDoc>*& finalDocument){
    list<InnerDoc>* sortedList = new list<InnerDoc>();
    for(Word& word : wordVector)
        cout << word.getWord() << endl;
    for(Word& word : wordVector){
        vector<InnerDoc> documentsVector = word.getDocTreeInOrder();
        for(InnerDoc& doc : documentsVector){
            if(sortedList->size() == 0){
                sortedList->push_back(doc);
                continue;
            }
            bool exist = false;
            for (list<InnerDoc>::iterator i = sortedList->begin();
                 i != sortedList->end();
                 i++){

                if(( doc.getRatio() > (*i).getRatio())){
                    sortedList->insert(i, doc);
                    exist = true;
                    break;
                }
            }
            if(!exist)
                sortedList->push_back(doc);
        }

    }
    int size= 0;
    for (list<InnerDoc>::iterator i = sortedList->begin();
         i != sortedList->end();
         i++){
        size++;
        cout << (*i).getID() << endl;
        if(size == 15)
            break;
    }
    finalDocument = sortedList;
}
void getORFromConsole(AVLTree<Word>& words){
    string line;
    getline(cin, line);
    istringstream ss(line);
    list<Word> wordList;
    do{
        string singleWord;
        ss >> singleWord;
        Porter2Stemmer::stem(singleWord);
        if(words.contains(singleWord) && singleWord.size() > 1)
            wordList.push_back(words.getValue(singleWord));
    }while(ss);
    list<InnerDoc>* finalDoc = nullptr;
    if(wordList.size() == 0)
        cout << "nothing" << endl;
    else
        ORProcessor(words, wordList, finalDoc);
}

void getAUTHORFromConsole(AVLTree<Word>& words, HashTable<string, Author*>& authors){
    string userInput;
    getline(cin, userInput);
    int place = 1;
    istringstream ss(userInput);
    list<Word> wordList;
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
        list<Article>* finalDocs = nullptr;
        if(authors.containsAuthor(author)){
            AUTHORProcessor(words, wordList, author, authors, finalDocs);
        }
        else
            cout << "Author doesn't exist" << endl;
    }

}

void AUTHORProcessor(AVLTree<Word>& words, list<Word>& wordVector, string& author, HashTable<string, Author*>& authors, list<Article>*& finalDocument){
    list<Article>* sortedList = new list<Article>();
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
            if(sortedList->size() == 0){
                sortedList->push_back(a);
                continue;
            }
            bool exist = false;
            for (list<Article>::iterator i = sortedList->begin();
                 i != sortedList->end();
                 i++){

                if(( a.getRatio() > (*i).getRatio())){
                    sortedList->insert(i, a);
                    exist = true;
                    break;
                }
            }
            if(!exist)
                sortedList->push_back(a);
        }
    }
    int size= 0;
    for (list<Article>::iterator i = sortedList->begin();
         i != sortedList->end();
         i++){
        size++;
        cout << (*i).getID() << endl;
        if(size == 15)
            break;
    }

    finalDocument = sortedList;
}

void NOTOperator(list<InnerDoc>& doc, list<Word>& wordVector){
    for(list<InnerDoc>::iterator i= doc.begin(); i!= doc.end() && doc.size() > 0; i++){
        for(Word& word : wordVector){
            if(word.hasDocument((*i).getID())){
                doc.erase(i);
                i= doc.begin();
                break;
            }
        }
    }
}
void NOTOperator( list<Article>& doc, list<Word>& wordVector){
    for(list<Article>::iterator i= doc.begin(); i!= doc.end() && doc.size() > 0; i++){
        Article* document = &(*(i));
        for(Word& word : wordVector){
            if(word.hasDocument(document->getID())){
                doc.erase(i);
                i= doc.begin();
                break;
            }
        }
    }
}

void primaryOperatorProcessor(AVLTree<Word>& words, HashTable<string, Author*>& authors){
    string line;
    getline(cin, line);
//    cin.clear();
    istringstream ss(line);
    list<Word> ands;
    list<Word> ors;
    list<Word> nots;
    string author = " ";
    int place = 1;
    string currentOperator = "and";
    do{
        string singleWord;
        ss >> singleWord;
        transform(singleWord.begin(), singleWord.end(), singleWord.begin(), ::tolower);
        if(singleWord == "author" || singleWord == "and" || singleWord == "or" || singleWord == "not"){
            currentOperator = singleWord;
            continue;
        }
        if( currentOperator == "author" && authors.containsAuthor(singleWord) && author == " "){
                author = singleWord;
                continue;
        }
        else if(currentOperator == "author" && !authors.containsAuthor(singleWord) && author == " "){
            cout << "Author doesn't exist" << endl;
            break;
        }
        Porter2Stemmer::stem(singleWord);
        if(words.contains(singleWord) && singleWord.size() > 1){
            Word currentWord = words.getValue(singleWord);
            if(currentOperator == "and" || currentOperator == "author")
                ands.push_back(currentWord);
            else if(currentOperator == "or")
                ors.push_back(currentWord);
            else if(currentOperator == "not")
                nots.push_back(currentWord);
        }

        place++;
    }while(ss);
    if(author != " "){
        list<Article>* finalDocs = nullptr;
        AUTHORProcessor(words, ands, author, authors, finalDocs);
        if(finalDocs != nullptr) {
            if (nots.size() > 0)
                NOTOperator(*finalDocs, nots);
            printArticles(*finalDocs, author);
            delete finalDocs;
        }
    }
    else if(ands.size() > 0){
        list<InnerDoc>* finalDocs = nullptr;
        ANDProcessor(words, ands, finalDocs);
        if(finalDocs != nullptr){
            if(nots.size() > 0) {
                NOTOperator(*finalDocs, nots);
                cout << "not" << endl;
            }
            printInnerDocs(*finalDocs);
            delete finalDocs;
        }
    }
    else if(ors.size() > 0){
        list<InnerDoc>* finalDocs = nullptr;
        ORProcessor(words, ors, finalDocs);
        if(finalDocs != nullptr) {
            if (nots.size() > 0)
                NOTOperator(*finalDocs, nots);
            printInnerDocs(*finalDocs);
            delete finalDocs;
        }
    }
}

void printArticles(list<Article>& articles, string& author){
    int size= 0;
    int listsize = articles.size();
    for (list<Article>::iterator i = articles.begin();
         i != articles.end();
         i++){
        size++;
        cout << endl << (size) << ". Title: " << ((*i).getTitle() != "" ? (*i).getTitle() : "No Title") << endl << "\tID: " << (*i).getID() << endl << "\tPrimary Author: " << author << endl << "\tPublication: N/A" << endl << "\tDate Published: N/A" << endl;
//        getPreview((*i).getID());
        if(size == 15)
            break;
    }
    cout << endl;
    string choice;
    bool loop = false;
    cout << "Which article would you like to print?" << endl;
    cout << "Integer value or NONE: ";
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
    while (!loop) {
        cin >> choice;
        cout << endl;

        if (choice == "none" || "0") {
            return;
        } else {
            int choiceint = stoi(choice);
            int temp = 0;
            if (choiceint > listsize) {
                cout << "Invalid number. Try again: ";
                loop = false;
            } else {
                for (list<Article>::iterator i = articles.begin();
                     i != articles.end(); i++) {
                    if (temp == choiceint - 1) {
                        getPreview((*i).getID());
                        return;
                    }
                    temp++;
                }

            }
        }
    }
}

void printInnerDocs(list<InnerDoc>& articles) {
    int size = 0;
    int listsize = articles.size();
    for (list<InnerDoc>::iterator i = articles.begin();
         i != articles.end();
         i++) {
        size++;

        cout << endl << (size) << ". Title" << ((*i).getTitle() != "" ? (*i).getTitle() : "No Title") << endl
             << "\tID: " << (*i).getID() << endl << "\tPrimary Author: "
             << ((*i).getAuthor().size() != 0 ? (*i).getAuthor() : "No Author") << endl << "\tPublication: N/A" << endl
             << "\tDate Published: N/A" << endl;
//        getPreview((*i).getID());
        if (size == 15)
            break;
    }
    cout << endl;
    string choice;
    cout << "Which article would you like to print?" << endl;
    cout << "Integer value or NONE: ";
    bool loop = false;
    while (!loop) {
        cin >> choice;
        cout << endl;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        if (choice == "none" || "0") {
            return;
        } else {
            int choiceint = stoi(choice);
            int temp = 0;
            if (choiceint > listsize) {
                cout << "Invalid number. Try again: ";
                loop = false;
            } else {
                for (list<InnerDoc>::iterator i = articles.begin();
                     i != articles.end(); i++) {
                    if (temp == choiceint - 1) {
                        getPreview((*i).getID());
                        return;
                    }
                    temp++;
                }
            }
        }
    }
}


using namespace rapidjson;
void getPreview(string docName){
    string path = "../Documents/cs2341_data/" + docName + ".json";
    std::ifstream ifs{path};
    if (!ifs.is_open()) {
        std::cerr << "Could not open file for reading!\n";
        return;
    }
    IStreamWrapper isw{ifs};
    Document d;
    d.ParseStream(isw);
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    int count = 0;
    string returningString = "";
    cout << "\tPreview: " << endl;
    for (int i = 0; i < d["abstract"].GetArray().Size(); i++) {
        string temp = d["abstract"].GetArray()[i]["text"].GetString();
        istringstream ss(temp);
        //reads through all words
        do{
            string tempString;
            ss >> tempString;
            count++;
        }while(ss);
        returningString += temp;
        if(count > 300){
            cout << "\t" <<returningString << endl;
            return;
        }
    }
    for (int i = 0; i < d["body_text"].GetArray().Size(); i++) {
        string temp = d["body_text"].GetArray()[i]["text"].GetString();
        istringstream ss(temp);
        //reads through all words
        do{
            string tempString;
            ss >> tempString;
            count++;
        }while(ss);
        returningString += temp;
        if(count > 300){
            cout << "\t" << returningString << endl;
            return;
        }
    }
    ifs.close();
}