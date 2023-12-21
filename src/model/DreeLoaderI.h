#ifndef ABOUTI_H
#define ABOUTI_H

#include <filesystem>

using namespace std;

class DreeLoaderI {
   public:
    virtual void load_dree() = 0;
};

#endif