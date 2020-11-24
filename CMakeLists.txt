cmake_minimum_required(VERSION 3.16)
project(SearchEngineTemplates)

set(CMAKE_CXX_FLAGS_DEBUG "-O3")

set(CMAKE_CXX_STANDARD 14)

add_executable(SearchEngineTemplates main.cpp AVLTree.h Author.cpp Author.h Article.cpp Article.h Word.cpp Word.h HashTable.h InnerDoc.cpp InnerDoc.h Functions.h fileParser.cpp porter2_stemmer.cpp porter2_stemmer.h StopWordAssociation.cpp StopWordAssociation.h PersistentIndexCreator.cpp UserInterface.cpp HashSet.h searchMods.cpp)
