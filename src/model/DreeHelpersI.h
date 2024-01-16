#ifndef DREEHELPERSI_H
#define DREEHELPERSI_H

#include <filesystem>
#include <string>

using namespace std;

class DreeHelpersI {
   public:
    virtual bool string_is_a_directory(const string &pathString) = 0;
};

#endif