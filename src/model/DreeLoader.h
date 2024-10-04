#ifndef DREELOADER_H
#define DREELOADER_H

#include <filesystem>
#include "../data_structures/DreeNode.h"
#include "DreeHelpers.h"
#include "DreeIgnoreI.h"
#include "DreeLoaderI.h"

class DreeLoader : public DreeLoaderI {
private:
    DreeIgnoreI* dreeIgnoreInterface;
    DreeHelpersI* dreeHelpersInterface;

    void traverse_dfs_and_build_tree(DreeNode* node, long long depth, long long currentDepth);

public:
    DreeNode* load_dree(Args* args) override;
    DreeLoader(DreeIgnoreI* dreeIgnoreInterface, DreeHelpersI* dreeHelperInterface);
};

#endif
