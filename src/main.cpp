#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "controller/DirectoryGraph.h"
#include "model/DirectoryNode.h"
#include "view/Dree.h"

using namespace std;

void search(int argc, char *argv[]) {
    if (argc != 5) {
        cout << "Missing args"
             << "\n";
        return;
    }
    string flag = argv[3];
    if (flag != "-f") {
        cout << "Unknown args: " << argv[3] << "\n";
        return;
    }
    string query = argv[4];
    int depth = stoi(argv[2]);
    if (depth >= 60) {
        cout << "mask overflow!!";
        return;
    }
    DirectoryGraph builder;
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    builder.SearchDirectory(currentPath, depth, query);
}

void dree(int argc, char *argv[]) {
    if (!(argc == 3 || argc == 4)) {
        cout << "Missing args" << std::endl;
        return;
    }
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    int depth = stoi(argv[2]);

    // TODO:add check to prevent overflow
    if (depth >= 60) {
        cout << "mask overflow!!";
        return;
    }

    bool showHidden = false;
    if (argc == 4) {
        string flag = argv[3];
        if (flag == "-a") {
            showHidden = true;
        } else {
            cout << "Unknown flags specified.";
            return;
        }
    }

    DirectoryGraph builder(showHidden);
    auto root = builder.BuildGraph(currentPath, depth);
    builder.PrintGraphDFS(root, depth);

    if (!builder.allFilesPermited) cout << builder.permissionErrorString;
}

int main(int argc, char *argv[]) {
    if (argc < 5)
        dree(argc, argv);
    else if (argc == 5)
        search(argc, argv);
    else
        cout << "Dree cannot execute the given command\n";
    return 0;
}
