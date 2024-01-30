#include "DreeIgnore.h"
#include <iostream>

bool DreeIgnore::file_is_in_dree_ignore(string directoryString) {
    return false;
    // if (!active) return false;
    // return (directoryString.front() == '.' || excludedDirectories.find(directoryString) != excludedDirectories.end());
}

// DreeIgnore::DreeIgnore(bool active) {
//     this->active = active;
//     excludedDirectories.clear();
//     ifstream file(".dreeignore");
//     string line;

//     while (getline(file, line)) {
//         this->excludedDirectories.insert(line);
//     }
// }