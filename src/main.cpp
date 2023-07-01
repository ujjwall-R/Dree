#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "view/Dree.h"
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    int depth = stoi(argv[2]);

    // TODO:add check to prevent overflow
    // long long depth = 3; // should not be more than 60
    DirectoryGraph builder;
    auto root = builder.BuildGraph(currentPath, depth);
    builder.PrintGraphDFS(root, depth);
    return 0;
}
