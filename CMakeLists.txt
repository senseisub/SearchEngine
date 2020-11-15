cmake_minimum_required(VERSION 3.16)
project(SearchEngineTemplates)

set(CMAKE_CXX_STANDARD 14)

add_executable(SearchEngineTemplates main.cpp AVLTree.cpp AVLTree.h Author.cpp Author.h Article.cpp Article.h)