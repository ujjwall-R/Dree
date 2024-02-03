#ifndef DREENAVIGATE_H
#define DREENAVIGATE_H

#include "IDreeNavigate.h"

using namespace std;

class DreeNavigate : public IDreeavigate {
   private:
    DreeLoaderI* DreeLoaderInterface;
    PrintDreeI* DreePrinterInterface;

   public:
    void print_dree(Args* args) override;

    DreeNavigate(DreeLoaderI* DreeLoader, PrintDreeI* DreePrinter);
};

#endif