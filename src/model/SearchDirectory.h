
#ifndef SEARCHDIRECTORY_H
#define SEARCHDIRECTORY_H

#include <filesystem>
#include <string>
#include <vector>
#include "../data_structures/Args.h"
#include "../data_structures/DreeNode.h"
#include "../model/DreeHelpersI.h"
#include "SearchDirectoryI.h"

class SearchDirectory : public SearchDirectoryI {

   private:
    Args *args;

    void traverse_directories(DreeNode *node, long long depth, long long currentDepth, const string &query,
                              vector<pair<int, DreeNode *>> &results, DreeHelpersI *dreehelpers);

   public:
    vector<pair<int, DreeNode *>> search(DreeNode *root, string &query, DreeHelpersI *dreeHelpers) override;

    explicit SearchDirectory(Args *args);
};

#endif
