 //
// Created by Oluwaseun Suberu on 11/21/20.
//
#include "Functions.h"

void showBasicInputUI(){
    cout << "Brandon and Seun Search Engine" << endl;
    cout << "||========================================||" << endl;
    cout << "||                                        ||" << endl;
    cout << "Reparse/populate index : 1 " << endl;
    cout << "Open persistance file : 2 " << endl;
    cout << "Type 'clear' to clear the console" << endl;
    cout << "Or enter your query below: " << endl;
    cout << "||========================================||" << endl;
    cout << "||                                        ||" << endl;

    string input;
    cin >> input;
    if (input == "1") {
       cout <<  "Reparsing index...." << endl;
    }
    if (input == "2") { //this just prints out the entire persistantFile.txt, I don't know if this is what he wants but I added it lol
        cout << "Opening persistance file...." << endl;
        //printing just incase this is what he wants
        ifstream myfile;
        string output;
        myfile.open("persistentFile.txt");
        myfile >> output;
        cout << output;
        myfile.close();
    }
    // otherwise input word becomes search word with query BOOLs, AND OR AUTHOR NOT
    if(input == "clear")
        clearConsole();
}

 void startIndex(AVLTree<Word>& allWords, HashTable<string, Author*>& authors, char* directory, char* searchWord, int& argc){
     bool loop = true;
     while (loop) {
         cout << "Number of accessible authors : " << authors.getSize() << endl;
         //    cout << "number of words that are stops : " << stopWords.getSize() << endl;
         cout << "Available keywords: AND, OR, NOT, AUTHOR" << endl;
         cout << "Please enter your search query:" << endl;
         // 1) command line string
         //search documents for string
         //print documents ID
         // 1.5) author hash table
         // 2) search query, defining the AUTHOR word, the NOT word. user input handling
         // 3) wants we get that and it works, then we do user interface, allow them to reset console, reset search, etc etc
         // 4) index persistance
         // 5)
         if(argc == 3){
             treeContains(allWords, searchWord, directory);
         }
         else{
             //        getAuthor(authors);
             //        getANDFromConsole(allWords);
             primaryOperatorProcessor(allWords, authors);
             //        getORFromConsole(allWords);
             //        getAUTHORFromConsole(allWords, authors);

         }
         cout << "\nWould you like to search again?" << endl;
         cout << "Y / N or clear: " << endl;
         string decision;
         cin.ignore();

         bool loop2 = false;
         bool clear = false;
         while (loop2 == false) { //loop that waits for a Y/N/clear command. anything else returns invalid.
             getline(cin, decision);
             if (decision == "clear") {
                 clearConsole();
                 cout << "\nWould you like to search again?" << endl;
                 cout << "Y / N:" << endl;
                 cin >> decision;
                 clear = true;
             }
             if (decision == "N" || decision == "no" || decision == "No" || decision == "n") {
                 loop = false;
                 break;
             }
             if (decision == "Yes" || decision == "y" || decision == "yes" || decision == "YES" || decision == "Y"){
                 loop2 = true;
             }
             else if (!clear){
                 cout << "\nInvalid command. Please enter Y / N : \n";
             }
         }
     }
}

void clearConsole(){
    std::cout << "\x1B[2J\x1B[H";
    cout << "\033[0;0m";
//    for(int i = 0; i < 50; i++){
//        cout << endl;
//    }
//    #if defined _WIN32
//        system("cls");
//    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
//        system("clear");
//    #elif defined (__APPLE__)
//        system("clear");
//    #endif
}