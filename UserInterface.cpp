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



void clearConsole(){
    std::cout << "\x1B[2J\x1B[H";
//    for(int i = 0; i < 50; i++){
//        cout << endl;
//    }
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}