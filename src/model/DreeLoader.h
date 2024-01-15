#ifndef DREELOADER_H
#define DREELOADER_H

#include <filesystem>
#include "DreeHelpers.h"
#include "DreeIgnoreI.h"
#include "DreeLoaderI.h"
#include "src/data_structures/DreeNode.h"

class DreeLoader : public DreeLoaderI {
   private:
    DreeIgnoreI* dreeIgnoreInterface;
    DreeHelpersI* dreeHelpersInterface;

    DreeNode* traverse_dfs_and_build_tree(DreeNode* node, long long depth, long long currentDepth);

   public:
    DreeNode* load_dree(Args* args) override;
};

#endif
