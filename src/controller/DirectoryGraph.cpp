#include "DirectoryGraph.h"
#include <iostream>

using namespace std;

DirectoryNode *DirectoryGraph::BuildGraph(const string &directoryName, int depth)
{
    DirectoryNode *graph = new DirectoryNode(directoryName, directoryName);
    TraverseDirectoriesDFS(graph, depth, 0);
    return graph;
}

void DirectoryGraph::TraverseDirectoriesDFS(DirectoryNode *node, int depth, int currentDepth)
{
    if (currentDepth > depth)
        return;

    // populate Children
    for (const auto &entry : filesystem::directory_iterator(node->path))
    {
        if (entry.is_directory())
        {
            string childDirectory = entry.path().string();
            DirectoryNode *child = new DirectoryNode(childDirectory, childDirectory);
            node->children.push_back(child);
        }
    }
    // Traverse and recursively go into children
    for (auto ch : node->children)
    {
        TraverseDirectoriesDFS(ch, depth, currentDepth + 1);
    }
}

void DirectoryGraph::PrintGraph(DirectoryNode *node, int depth, int currentDepth)
{
    if (currentDepth == depth)
        return;

    for (int i = 0; i < currentDepth * depth; ++i)
        cout << " ";
    cout << "└── ";

    cout << node->name << "\n";
    for (size_t i = 0; i < node->children.size(); ++i)
    {
        DirectoryNode *child = node->children[i];
        PrintGraph(child, depth, currentDepth + 1);
    }
}
