#include "DreeHelpers.h"

using namespace std;

bool DreeHelpers::string_is_a_directory(const string &pathString) {
    filesystem::path path(pathStr);
    return filesystem::is_directory(path);
}

string DreeHelpers::get_current_directory_path() {}