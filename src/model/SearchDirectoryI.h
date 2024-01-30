#ifndef SEARCHDIRECTORYI_H
#define SEARCHDIRECTORYI_H

#include <filesystem>
#include <vector>
#include "../data_structures/DreeNode.h"
#include "../data_structures/SearchDirectoryResult.h"

using namespace std;

class SearchDirectoryI {
   public:
    virtual vector<pair<int, DreeNode*>> search(DreeNode* root, string& query, DreeHelpersI* dreeHelpers) = 0;
};

#endif