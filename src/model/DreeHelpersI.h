#ifndef DREEHELPERSI_H
#define DREEHELPERSI_H

#include <filesystem>
#include <string>

using namespace std;

class DreeHelpersI {
   public:
    virtual bool string_is_a_directory(const string &pathString) = 0;

    virtual int levenshtein_distance_between_strings(const string &s1, const string &s2) = 0;
};

#endif