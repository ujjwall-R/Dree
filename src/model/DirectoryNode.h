#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H

#include <string>
#include <vector>

using namespace std;

class DirectoryNode {
   public:
    string name;
    string path;
    long long pos;
    vector<DirectoryNode *> children;

    string getFileName(string path);

    DirectoryNode(const string &path);
};

#endif
