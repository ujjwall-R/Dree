#include "DreeNode.h"

std::string DreeNode::get_file_name_from_path(std::string &path) {
    size_t lastSlash = path.find_last_of('/');
    if (lastSlash != std::string::npos) {
        return path.substr(lastSlash + 1);
    }
    return path;
}

DreeNode::DreeNode(std::string &str) {
    path = str;
    name = get_file_name_from_path(path);
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}