#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "view/Dree.h"

using namespace std;

int main()
{
    DirectoryGraph builder;
    auto root = builder.BuildGraph("/home/ujjwal/Desktop/crawlir", 4);
    builder.PrintGraph(root, 4);

    return 0;
}
