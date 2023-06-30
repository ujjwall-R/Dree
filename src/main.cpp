#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "view/Dree.h"
#include <filesystem>

using namespace std;

int main()
{
    auto currentPath = filesystem::current_path();
    DirectoryGraph builder;
    auto root = builder.BuildGraph(currentPath, 4);
    builder.PrintGraph(root, 4);
    return 0;
}
