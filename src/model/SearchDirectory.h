
#ifndef SEARCHDIRECTORY_H
#define SEARCHDIRECTORY_H

#include "SearchDirectoryI.h"

class SearchDirectory : public SearchDirectoryI {
   public:
    SearchDirectoryResult* search() override;
};

#endif
