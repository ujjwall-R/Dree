#ifndef IDREENAVIGATE_H
#define IDREENAVIGATE_H

#include <filesystem>
#include "../../data_structures/DreeNode.h"
#include "../../model/DreeLoaderI.h"
#include "../../view/PrintDreeI.h"

using namespace std;

class IDreeavigate {
   public:
    virtual void print_dree(Args* args) = 0;
};

#endif