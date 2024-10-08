#ifndef DREENAVIGATEVIEW_H
#define DREENAVIGATEVIEW_H

#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <map>
#include "IDreeNavigateView.h"

using namespace std;

class DreeNavigateView : public IDreeNavigateView {

   private:
    DreeNode* selectedNode;
    DreeHelpersI* dreeHelpersInterface;

    void dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask);
    void depth_first_search(DreeNode* node, long long maxDepth);

   public:
    void navigate_dree(DreeNode* node, long long maxDepth) override;

    explicit DreeNavigateView(DreeHelpersI* dreehelper);
};

#endif