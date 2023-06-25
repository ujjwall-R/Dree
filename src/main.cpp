#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "view/Dree.h"

using namespace std;

int main()
{
    DirectoryGraph builder;
    builder.BuildGraph("/home/ujjwal/Desktop/crawlir", 4);
    // dree.PrintGraph();

    return 0;
}
