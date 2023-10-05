#include <iostream>
#include <fstream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
//#include "controller/DirectorySearch.h"
#include "view/Dree.h"
#include <filesystem>
#include <string>

using namespace std;

void search(int argc, char *argv[], set<string> &excludedDirectories)
{
    if (argc != 5)
    {
        cout << "Missing args"
             << "\n";
        return;
    }
    string flag = argv[3];
    if (flag != "-f")
    {
        cout << "Unknown args: " << argv[3] << "\n";
        return;
    }
    string query = argv[4];
    int depth = stoi(argv[2]);
    if (depth >= 60)
    {
        cout << "mask overflow!!";
        return;
    }
    DirectoryGraph builder(excludedDirectories);
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    builder.SearchDirectory(currentPath, depth, query);
}

void dree(int argc, char *argv[], set<string> &excludedDirectories)
{
    if (!(argc == 3 || argc == 4))
    {
        cout << "Missing args dree" << std::endl;
        return;
    }
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    int depth = stoi(argv[2]);

    // TODO:add check to prevent overflow
    if (depth >= 60)
    {
        cout << "mask overflow!!";
        return;
    }

    bool showHidden = false;
    if(argc == 4) {
        string flag = argv[3];
        if(flag == "-a") {
            showHidden = true;
        } else {
            cout << "Unknown flags specified.";
            return;
        }
    }

    DirectoryGraph builder(excludedDirectories, showHidden);
    auto root = builder.BuildGraph(currentPath, depth);
    builder.PrintGraphDFS(root, depth);

    if (!builder.allFilesPermited)
        cout << builder.permissionErrorString;
}

int main(int argc, char *argv[])
{
    set<string> excludedDirectories;
    
    ifstream file(".dreeignore");
    string line;
    
    while (getline(file, line)) {
        excludedDirectories.insert(line);
    }

    if (argc < 5)
        dree(argc, argv, excludedDirectories);
    else if (argc == 5)
        search(argc, argv, excludedDirectories);
    else
        cout << "Dree cannot execute the given command\n";
    return 0;
}
