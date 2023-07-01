#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H

#include <vector>
#include <string>

using namespace std;

class DirectoryNode
{
public:
    string name;
    string path;
    vector<DirectoryNode *> children;

    string getFileName(string path);

    DirectoryNode(const string &path);
};

#endif
