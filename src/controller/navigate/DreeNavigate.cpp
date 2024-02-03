#include "DreeNavigate.h"

void DreeNavigate::print_dree(Args* args) {
    DreeNode* rootNode = DreeLoaderInterface->load_dree(args);
    DreePrinterInterface->depth_first_search(rootNode, args->MaxDepth);
}

DreeNavigate::DreeNavigate(DreeLoaderI* DreeLoader, PrintDreeI* DreePrinter) {
    DreeLoaderInterface = DreeLoader;
    DreePrinterInterface = DreePrinter;
}