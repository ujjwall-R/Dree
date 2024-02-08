#ifndef DREENAVIGATE_H
#define DREENAVIGATE_H

#include "IDreeNavigate.h"

using namespace std;

class DreeNavigate : public IDreeNavigate {
   private:
    DreeLoaderI* DreeLoaderInterface;
    IDreeNavigateView* DreePrinterInterface;

   public:
    void display_dree(Args* args) override;

    DreeNavigate(DreeLoaderI* DreeLoader, IDreeNavigateView* DreePrinter);
};

#endif