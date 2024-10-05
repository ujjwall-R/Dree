#include "DreeController.h"

void DreeController::print_dree(Args* args) {
    DreeNode* rootNode = DreeLoaderInterface->load_dree(args);
    DreePrinterInterface->depth_first_search(rootNode, args->MaxDepth);
    
    delete rootNode;
    rootNode = nullptr;
}

DreeController::DreeController(DreeLoaderI* DreeLoader, PrintDreeI* DreePrinter) {
    DreeLoaderInterface = DreeLoader;
    DreePrinterInterface = DreePrinter;
}