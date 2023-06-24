#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"

using namespace std;

int main()
{
    DirectoryGraph builder;
    vector<DirectoryNode> graph = builder.BuildGraph("/home", 2);

    for (const auto &node : graph)
    {
        cout << node.name << " (" << node.path << ")" << endl;
        for (const auto &child : node.children)
        {
            cout << "  - " << child.name << " (" << child.path << ")" << endl;
        }
        cout << endl;
    }

    return 0;
}
