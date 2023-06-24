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
    vector<DirectoryNode> BuildGraph(const string &directoryName, int depth);

private:
    void TraverseDirectories(const string &directoryName, int depth, vector<DirectoryNode> &graph, int currentDepth = 0);
};

#endif
