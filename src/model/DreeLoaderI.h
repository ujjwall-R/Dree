#ifndef ABOUTI_H
#define ABOUTI_H

#include <filesystem>
#include "src/data_structures/Args.h"

using namespace std;

class DreeLoaderI {
   public:
    virtual DreeNode *load_dree(Args *args, DreeIgnoreI *dreeIgnore, DreeHelpersI *dreeHelpers) = 0;
};

#endif