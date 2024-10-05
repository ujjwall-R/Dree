#include "DreeNavigate.h"

void DreeNavigate::display_dree(Args* args) {
    DreeNode* rootNode = DreeLoaderInterface->load_dree(args);
    DreePrinterInterface->navigate_dree(rootNode, args->MaxDepth);

    delete rootNode;
    rootNode = nullptr;
}

DreeNavigate::DreeNavigate(DreeLoaderI* DreeLoader, IDreeNavigateView* DreePrinter) {
    DreeLoaderInterface = DreeLoader;
    DreePrinterInterface = DreePrinter;
}