#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "view/Dree.h"
#include <filesystem>

using namespace std;

int main()
{
    long long depth = 3; // should not be more than 60
    auto currentPath = filesystem::current_path();
    DirectoryGraph builder;
    auto root = builder.BuildGraph(currentPath, depth);
    builder.PrintGraph(root, depth);
    return 0;
}
