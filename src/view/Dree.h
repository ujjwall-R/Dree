#ifndef DREE_H
#define DREE_H

#include <iostream>
#include <vector>
#include <string>
#include "../model/DirectoryNode.h"

using namespace std;

class Dree
{
private:
    vector<vector<DirectoryNode>> graph;
    int depth;

public:
    Dree(const vector<vector<DirectoryNode>> &graph)
        : graph(graph) {}

    void PrintGraph();

private:
    void PrintChildren(const vector<vector<DirectoryNode>> &children, int level);
};

#endif
