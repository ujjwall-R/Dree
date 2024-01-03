#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "controller/DirectoryGraph.h"
#include "model/DirectoryNode.h"
#include "view/Dree.h"

using namespace std;
void help() {
    cout << "\tdree: "
         << "dree "
         << "[dep] [-f [dir|file]][-a][-w][-r]"
         << "\n";
    cout << "\tVisualize directories until certain depth"
         << "\n";
    cout << "\n";
    cout << "\trun dree followed by the number of levels you want to visualize"
         << "\n";
    cout << "\n";
    cout << "\tOptions:"
         << "\n";
    cout << "\t   -f   \t"
         << "search for a directory or file upto the specified depth"
         << "\n";
    cout << "\t   -a   \t"
         << "Show hidden files"
         << "\n";
    cout << "\t   -w   \t"
         << "Add files to .dreeignore file"
         << "\n";
    cout << "\t   -r   \t"
         << "Remove files from .dreeignore file"
         << "\n";
}
bool isNumber(string line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

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
void update_dreeignore(string file_name){
    ifstream in("./.dreeignore");
    ofstream out("./temp.txt");
    if(!in.is_open()){
        cout<<"Error opening dreeignore file.\n";
    }
    string line;
    while(getline(in,line)){
        if(line==file_name){
            cout<<"Successfully added.\n";
            return ;
        }
    }
    in.close();
    in.open("./.dreeignore");
    while(getline(in,line)){
        out<<line+'\n';
    }
    out<<file_name;
    cout<<"Successfully added.\n";
    remove("./.dreeignore");
    rename("./temp.txt","./.dreeignore");
    out.close();
    in.close();
    return ;
}
void remove_file(string file_name){
    string line;
    ifstream in("./.dreeignore");
    if(!in.is_open()){
        cout<<"Error opening dreeignore file.\n";
    }
    ofstream out("./temp.txt");
    bool sw=true;;
    while(getline(in,line)){
        if(line!=file_name){
            if(sw){
                sw=false;
            }
            else{
                out<<'\n';
            }
            out<<line;
        }
    }
    in.close();
    out.close();
    remove("./.dreeignore");
    rename("./temp.txt","./.dreeignore");
    cout<<"Removed successfully.\n";
    return ;
}
void dree(int argc, char *argv[]) {
    if (!(argc == 3 || argc == 4)) {
        cout << "Missing args" << std::endl;
        return;
    }
    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    bool showHidden = false;
    int depth = -1;
    if (argc == 4 || (argc == 3 && isNumber(argv[2]))) {
        // TODO:add check to prevent overflow
        if (depth >= 60) {
            cout << "mask overflow!!";
            return;
        }
        showHidden = false;
        if (argc == 4) {
            if (string(argv[3])== "-a") {
                depth = stoi(argv[2]);
                showHidden = true;
            }
            else if(string(argv[2]) ==  "-w"){
                update_dreeignore(argv[3]);
                return ;
            } 
            else if(string(argv[2]) ==  "-r"){
                remove_file(argv[3]);
                return ;
            } 
            else {
                cout << "Unknown flags specified.";
                return;
            }
        }
    } else if (argc == 3) {
        if (string(argv[2]) == "--help") {
            help();
            return;
        }
    }
    depth = stoi(argv[2]);

    // TODO:add check to prevent overflow
    if (depth >= 60) {
        cout << "mask overflow!!" << endl;
        return;
    }

    showHidden = false;
    if (argc == 4) {
        string flag = argv[3];
        if (flag == "-a") {
            showHidden = true;
        } else {
            cout << "Unknown flags specified" << endl;
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
