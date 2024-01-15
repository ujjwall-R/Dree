#ifndef DREECONTROLLER_H
#define DREECONTROLLER_H

#include <DreeControllerI.h>

using namespace std;

class DreeController : public DreeControllerI {
   private:
    DreeLoaderI* DreeLoaderInterface;

   public:
    void print_dree(Args* args) override;
};

#endif