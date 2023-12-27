#ifndef DREEHELPERS_H
#define DREEHELPERS_H

#include <filesystem>
#include <string>

using namespace std;

class DreeHelpers {
   public:
    bool static string_is_a_directory(const string &pathString);

    string static get_current_directory_path();
};

#endif