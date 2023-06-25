#include "DirectoryGraph.h"
#include <iostream>

using namespace std;

vector<vector<DirectoryNode>> DirectoryGraph::BuildGraph(const string &directoryName, int depth)
{
    vector<vector<DirectoryNode>> graph;
    graph.resize(depth + 2);
    TraverseDirectoriesDFS(directoryName, depth, graph);
    return graph;
}

void DirectoryGraph::TraverseDirectoriesDFS(const string &directoryName, int depth, vector<vector<DirectoryNode>> &graph, int currentDepth)
{
    if (currentDepth > depth)
        return;

    DirectoryNode node(directoryName, directoryName);
    graph[currentDepth].push_back(node);

    for (int j = 0; j < currentDepth; j++)
    {
        cout << "   ";
    }
    cout << "└── ";
    cout << node.name << "\n";

    for (const auto &entry : filesystem::directory_iterator(directoryName))
    {
        if (entry.is_directory())
        {
            string childDirectory = entry.path().string();
            TraverseDirectoriesDFS(childDirectory, depth, graph, currentDepth + 1);
        }
    }
}
