#ifndef DREENODE_H
#define DREENODE_H

#include <string>
#include <vector>

class DreeNode {
   private:
    std::string get_file_name_from_path(std::string &path);

   public:
    std::string name;
    std::string path;
    std::vector<DreeNode *> children;
    DreeNode *parent;
    DreeNode *left;
    DreeNode *right;

    DreeNode(std::string &str);

    ~DreeNode() {
        for (auto i : children) {
            delete i;
        }
    }
};

#endif