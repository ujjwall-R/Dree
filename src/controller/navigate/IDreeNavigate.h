#ifndef IDREENAVIGATE_H
#define IDREENAVIGATE_H

#include <filesystem>
#include "../../data_structures/DreeNode.h"
#include "../../model/DreeLoaderI.h"
#include "../../view/navigate/IDreeNavigateView.h"

using namespace std;

class IDreeNavigate {
   public:
    virtual void display_dree(Args* args) = 0;
};

#endif