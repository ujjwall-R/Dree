#include <DreeNode.h>
#include <string>

string DreeNode::get_file_name_from_path(string &path) {
    size_t lastSlash = path.find_last_of('/');
    if (lastSlash != std::string::npos) {
        return path.substr(lastSlash + 1);
    }
    return path;
}

DreeNode::DreeNode(string &str) {
    this->path = str;
    this->name = get_file_name_from_path(path);
}