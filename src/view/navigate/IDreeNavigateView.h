#ifndef IDREENAVIGATEVIEW_H
#define IDREENAVIGATEVIEW_H

#include "../../data_structures/DreeNode.h"
#include "../../model/DreeHelpersI.h"

class IDreeNavigateView {
   public:
    virtual void navigate_dree(DreeNode* node, long long maxDepth) = 0;
};

#endif