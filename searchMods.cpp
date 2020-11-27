//
// Created by Brandon Herman on 11/24/2020.
//
#include "Functions.h"


void defineMods(string searchQuery) { //excludes author
    bool NOT = false;
    bool AND = false;
    bool OR = false;
    string notMod = "NOT";
    string andMod = "AND";
    string orMod = "OR";
    if (searchQuery.find(notMod) != string::npos) {
        NOT = true;
    } if (searchQuery.find(andMod) != string::npos) {
        AND = true;
    } if (searchQuery.find(orMod) != string::npos) {
        OR = true;
    }

    //and used both other words and search terms. must include both
    // or searches for one that contains one or the other
    // not searches for articles without that word

}
