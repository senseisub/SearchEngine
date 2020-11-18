//
// Created by seuns on 11/17/2020.
//
#include "Functions.h"
#include <dirent.h>
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filereadstream.h"
#include <ctype.h>
#include "rapidjson/include/rapidjson/istreamwrapper.h"

void loadStopWords(ifstream& stops, unordered_set<string>& stopWords){ //Unordered set of stop words of O(1)
    std::string str;
    while(stops.peek()!=EOF) {
        //puts each line in the line variable
        std::getline(stops, str);
        if(str.size() > 0){
            stopWords.insert(str);
        }
    }
}

void fileParser(){

}