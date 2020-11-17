//
// Created by seuns on 11/17/2020.
//

#include "Functions.h"
#include<dirent.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <ctype.h>
#include <rapidjson/istreamwrapper.h>

void loadStopWords(ifstream& stops, unordered_set<string>& stopWords){
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