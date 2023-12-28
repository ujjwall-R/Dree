#ifndef DREELOADER_H
#define DREELOADER_H

#include <filesystem>
#include "DreeHelpers.h"
#include "DreeIgnoreI.h"
#include "DreeLoaderI.h"
#include "src/data_structures/DreeNode.h"

class DreeLoader : public DreeLoaderI {
   private:
    DreeNode* traverse_dfs_and_build_tree(DreeNode* node, long long depth, long long currentDepth,
                                          DreeIgnoreI* dreeIgnore, DreeHelpersI* dreeHelpers);

   public:
    DreeNode* load_dree(Args* args, DreeIgnoreI* dreeIgnore, DreeHelpersI* dreeHelpers) override;
};

#endif
