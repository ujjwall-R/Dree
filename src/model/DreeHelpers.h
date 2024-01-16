#ifndef DREEHELPERS_H
#define DREEHELPERS_H

#include <filesystem>
#include <string>
#include "DreeHelpersI.h"

using namespace std;

class DreeHelpers : DreeHelpersI {
   public:
    bool string_is_a_directory(const string &pathString) override;
};

#endif