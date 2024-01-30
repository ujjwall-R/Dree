#ifndef DREEIGNOREI_H
#define DREEIGNOREI_H

using namespace std;
#include <string>

class DreeIgnoreI {
   public:
    virtual bool file_is_in_dree_ignore(string directoryString) = 0;
};

#endif