#include "DirectoryNode.h"

using namespace std;

string DirectoryNode::getFileName(string path)
{
    size_t lastSlash = path.find_last_of('/');
    if (lastSlash != std::string::npos)
    {
        return path.substr(lastSlash + 1);
    }
    return path;
}

DirectoryNode::DirectoryNode(const string &path)
    : path(path)
{
    this->name = this->getFileName(path);
}
