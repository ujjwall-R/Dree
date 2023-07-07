#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "controller/DirectorySearch.h"
#include "view/Dree.h"
#include <filesystem>

using namespace std;

void search(int argc, char *argv[])
{
    if (argc != 5)
    {
        cout << "Missing args" << std::endl;
        return;
    }
    string flag = argv[3];
    if (flag != "-f")
    {
        cout << "Unknown args: " << argv[3] << "\n"
             << std::endl;
        return;
    }
    string query = argv[4];
    int depth = stoi(argv[2]);
    if (depth >= 60)
    {
        cout << "mask overflow!!\n";
        return;
    }
    DirectoryGraph builder;
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    // cout << "here: " << currentPath << " " << depth << " " << query << "\n";
    builder.SearchDirectory(currentPath, depth, query);
}

void dree(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Missing args" << std::endl;
        return;
    }
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    int depth = stoi(argv[2]);

    // TODO:add check to prevent overflow
    if (depth >= 60)
    {
        cout << "mask overflow!!\n";
        return;
    }

    DirectoryGraph builder;
    auto root = builder.BuildGraph(currentPath, depth);
    builder.PrintGraphDFS(root, depth);

    if (!builder.allFilesPermited)
        cout << builder.permissionErrorString << "\n";
}

int main(int argc, char *argv[])
{

    // cout << DirectorySearch::LevenshteinDistance("hello1123", "hello") << " : sim\n";

    if (argc == 3)
        dree(argc, argv);
    else if (argc == 5)
        search(argc, argv);
    else
        cout << "Dree cannot execute the given command\n";
    return 0;
}
