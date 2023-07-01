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
    DirectoryNode *BuildGraph(const string &directoryName, int depth);

    void PrintGraph(DirectoryNode *node, int depth, int currentDepth = 0);

private:
    bool isDirectory(const std::string &pathStr);

    void TraverseDirectoriesDFS(DirectoryNode *node, int depth, int currentDepth = 0);
};

#endif
