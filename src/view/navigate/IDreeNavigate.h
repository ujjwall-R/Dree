#ifndef IDREENAVIGATE_H
#define IDREENAVIGATE_H

#include "../../data_structures/DreeNode.h"

class IDreeNavigate {
   public:
    virtual void depth_first_search(DreeNode* node, long long maxDepth) = 0;

    virtual void breadth_first_search(DreeNode* node, long long maxDepth) = 0;
};

#endif