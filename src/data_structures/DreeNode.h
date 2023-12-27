#ifndef DREENODE_H
#define DREENODE_H

#include <vector>

using namespace std;

class DreeNode {
   private:
    string get_file_name_from_path(string &path);

   public:
    string name;
    string path;
    vector<DreeNode *> children;

    DreeNode(string &str);
};

#endif