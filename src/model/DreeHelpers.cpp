#include "DreeHelpers.h"

using namespace std;

bool DreeHelpers::string_is_a_directory(const string &pathString) {
    filesystem::path path(pathString);
    return filesystem::is_directory(path);
}
