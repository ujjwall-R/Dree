#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H

#include <vector>
#include <string>

class DirectoryNode
{
public:
    std::string name;
    std::string path;
    std::vector<DirectoryNode> children;

    DirectoryNode(const std::string &name, const std::string &path);
};

#endif
