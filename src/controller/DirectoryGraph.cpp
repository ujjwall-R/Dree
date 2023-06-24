#include "DirectoryGraph.h"

using namespace std;

vector<DirectoryNode> DirectoryGraph::BuildGraph(const string &directoryName, int depth)
{
    vector<DirectoryNode> graph;
    TraverseDirectories(directoryName, depth, graph);
    return graph;
}

void DirectoryGraph::TraverseDirectories(const string &directoryName, int depth, vector<DirectoryNode> &graph, int currentDepth)
{
    if (currentDepth > depth)
        return;

    DirectoryNode node(directoryName, directoryName);
    graph.push_back(node);

    for (const auto &entry : filesystem::directory_iterator(directoryName))
    {
        if (entry.is_directory())
        {
            string childDirectory = entry.path().string();
            TraverseDirectories(childDirectory, depth, graph, currentDepth + 1);
        }
    }
}
