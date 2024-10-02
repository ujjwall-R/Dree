#ifndef ARGS_H
#define ARGS_H

#include <string>
using namespace std;

class Args {
   private:
   public:
    long long MaxDepth;
    string currentPath;
    Args(long long dep, const string& path);
};

#endif