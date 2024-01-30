#ifndef SEARCHCONTROLLERI_H
#define SEARCHCONTROLLERI_H

#include <filesystem>
#include <string>

using namespace std;

class SearchControllerI {
   public:
    virtual void search(string& query, Args* args) = 0;
};

#endif