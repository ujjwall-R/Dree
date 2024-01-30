#ifndef ABOUTI_H
#define ABOUTI_H

#include <filesystem>
#include "../data_structures/Args.h"

using namespace std;

class DreeLoaderI {
   public:
    virtual DreeNode *load_dree(Args *args) = 0;
};

#endif