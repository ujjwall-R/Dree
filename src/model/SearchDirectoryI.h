#ifndef SEARCHDIRECTORYI_H
#define SEARCHDIRECTORYI_H

#include <filesystem>
#include "../data_structures/SearchDirectoryResult.h"

using namespace std;

class SearchDirectoryI {
   public:
    virtual SearchDirectoryResult* search() = 0;
};

#endif