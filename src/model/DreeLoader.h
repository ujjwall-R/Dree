#ifndef DREELOADER_H
#define DREELOADER_H

#include <DreeLoaderI.h>
#include <filesystem>
#include "src/data_structures/DreeNode.h"

class DreeLoader : public DreeLoaderI {
   private:
   public:
    DreeNode* load_dree() override;
};

#endif
