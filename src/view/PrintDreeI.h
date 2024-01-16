#ifndef PRINTDREEI_H
#define PRINTDREEI_H

#include "../data_structures/DreeNode.h"

class PrintDreeI {
   public:
    virtual void depth_first_search(DreeNode* node) = 0;

    virtual void breadth_first_search(DreeNode* node) = 0;
};

#endif