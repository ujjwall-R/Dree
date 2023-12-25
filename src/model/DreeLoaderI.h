#ifndef ABOUTI_H
#define ABOUTI_H

#include <filesystem>
#include "src/data_structures/DreeNode.h"

using namespace std;

class DreeLoaderI {
   public:
    virtual DreeNode* load_dree() = 0;
};

#endif