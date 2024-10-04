#ifndef PRINTDREE_H
#define PRINTDREE_H

#include <iostream>
#include "PrintDreeI.h"
using namespace std;

class PrintDree : public PrintDreeI {

   private:
    void dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask);

   public:
    void depth_first_search(DreeNode* node, long long maxDepth) override;
    void breadth_first_search(DreeNode* node, long long maxDepth) override;
};

#endif