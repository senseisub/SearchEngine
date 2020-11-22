//
// Created by Oluwaseun Suberu on 11/21/20.
//
#include "Functions.h"

void showBasicInputUI(){
    cout << "Brandon and Seun Search Engine" << endl;
    cout << "||========================================||" << endl;
    cout << "||                                        ||" << endl;
    string input;
    cin >> input;
    if(input == "clear")
        clearConsole();
}
void clearConsole(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}