#ifndef DREECONTROLLERI_H
#define DREECONTROLLERI_H

#include <filesystem>
#include "../data_structures/DreeNode.h"
#include "../model/DreeLoaderI.h"
#include "../view/PrintDreeI.h"

using namespace std;

class DreeControllerI {
   public:
    virtual void print_dree(Args* args) = 0;
};

#endif