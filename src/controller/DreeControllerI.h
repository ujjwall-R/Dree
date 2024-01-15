#ifndef DREECONTROLLERI_H
#define DREECONTROLLERI_H

#include <../data_structures/DreeNode.h>
#include <../model/DreeLoaderI.h>
#include <filesystem>

using namespace std;

class DreeControllerI {
   public:
    virtual void print_dree(Args* args) = 0;
};

#endif