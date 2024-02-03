#ifndef DREENAVIGATEVIEW_H
#define DREENAVIGATEVIEW_H

#include <iostream>
#include "IDreeNavigateView.h"

using namespace std;

class DreeNavigateView : public IDreeNavigateView {

   private:
    void dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask);

   public:
    void depth_first_search(DreeNode* node, long long maxDepth) override;
    void breadth_first_search(DreeNode* node, long long maxDepth) override;
};

#endif