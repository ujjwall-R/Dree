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

    DirectoryNode(const string &name, const string &path);
};

#endif
