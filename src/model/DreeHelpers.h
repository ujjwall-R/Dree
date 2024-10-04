#ifndef DREEHELPERS_H
#define DREEHELPERS_H

#include <filesystem>
#include <string>
#include "DreeHelpersI.h"

using namespace std;

class DreeHelpers : public DreeHelpersI {
   public:
    bool string_is_a_directory(const string &pathString) override;

    int levenshtein_distance_between_strings(const string &s1, const string &s2) override;
};

#endif