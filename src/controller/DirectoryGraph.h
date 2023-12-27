#ifndef DIRECTORYGRAPH_H
#define DIRECTORYGRAPH_H

#include <filesystem>
#include <set>
#include <string>
#include <vector>
#include "../controller/DirectorySearch.h"
#include "../model/DirectoryNode.h"
#include<queue>
using namespace std;

class DirectoryGraph {
    long long p=0;
   public:
    DirectoryGraph(bool showHidden = false);
    DirectoryNode *BuildGraph(const string &directoryName, long long depth);

    void SearchDirectory(const string &directoryName, int searchDepth, const string &query);
    void PrintGraphDFS(DirectoryNode *node, long long depth);
    void PrintGraphBFS(DirectoryNode* node,long long depth);
    bool allFilesPermited;
    string permissionErrorString;

   private:
    bool isDirectory(const string &pathStr);
    void print_name(FILE* st,queue<DirectoryNode*>& q,long long depth);
    void print_char(FILE* st,const char* c);
    void print_line(FILE* st,queue<DirectoryNode*>& q,long long depth);
    void TraverseDirectoriesDFS(DirectoryNode *node, long long depth, long long currentDepth = 0);
    void PrintGraphDFS(DirectoryNode *node, long long depth, long long currentDepth, bool isLastChild, long long mask);
    void TraverseDirectoriesToSearch(DirectoryNode *node, long long depth, long long currentDepth, const string &query,vector<pair<int, DirectoryNode *>> &results);
    bool isExcluded(const string &dirStr);
    set<string> excludedDirectories;
    bool showHidden;
};

#endif