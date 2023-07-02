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
    DirectoryGraph();
    DirectoryNode *BuildGraph(const string &directoryName, long long depth);
    void PrintGraphDFS(DirectoryNode *node, long long depth);
    bool allFilesPermited;
    string permissionErrorString;

private:
    bool isDirectory(const std::string &pathStr);
    void TraverseDirectoriesDFS(DirectoryNode *node, long long depth, long long currentDepth = 0);
    void PrintGraphDFS(DirectoryNode *node, long long depth, long long currentDepth, bool isLastChild, long long mask);
};

#endif
