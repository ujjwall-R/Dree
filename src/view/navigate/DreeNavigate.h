#ifndef DREENAVIGATE_H
#define DREENAVIGATE_H

#include <iostream>
#include "IDreeNavigate.h"

using namespace std;

class DreeNavigate : public IDreeNavigate {

   private:
    void dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask);

   public:
    void depth_first_search(DreeNode* node, long long maxDepth) override;
    void breadth_first_search(DreeNode* node, long long maxDepth) override;
};

#endif