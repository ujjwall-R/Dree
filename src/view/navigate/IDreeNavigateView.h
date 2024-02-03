#ifndef IDREENAVIGATEVIEW_H
#define IDREENAVIGATEVIEW_H

#include "../../data_structures/DreeNode.h"

class IDreeNavigateView {
   public:
    virtual void depth_first_search(DreeNode* node, long long maxDepth) = 0;

    virtual void breadth_first_search(DreeNode* node, long long maxDepth) = 0;
};

#endif