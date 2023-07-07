#ifndef DIRECTORYSEARCH_H
#define DIRECTORYSEARCH_H

#include <vector>
#include <string>
#include <filesystem>
#include "../model/DirectoryNode.h"

using namespace std;

class DirectorySearch
{
public:
    vector<pair<int, DirectoryNode *>> results;
    int searchDepth;
    DirectorySearch(int searchDepth = 60);
    static int LevenshteinDistance(const string &s1, const string &s2);
};

#endif
