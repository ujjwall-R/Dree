#ifndef DIRECTORYGRAPH_H
#define DIRECTORYGRAPH_H

#include <vector>
#include <string>
#include <filesystem>
#include "../model/DirectoryNode.h"

using namespace std;

class DirectoryGraph
{
public:
    vector<vector<DirectoryNode>> BuildGraph(const string &directoryName, int depth);

private:
    void TraverseDirectoriesDFS(const string &directoryName, int depth, vector<vector<DirectoryNode>> &graph, int currentDepth = 0);

    void PrintDirectoriesDFS(int depth, int currentDepth = 0);
};

#endif
