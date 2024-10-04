#include "Args.h"

Args::Args(long long dep, const string& path) {
    MaxDepth = dep;
    currentPath = path;
}