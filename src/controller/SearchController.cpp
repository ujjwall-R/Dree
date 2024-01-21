#include "SearchController.h"
#include <iostream>

SearchController::SearchController(DreeHelpersI* dreeHelpers, SearchResultsI* searchResulPrinter,
                                   SearchDirectoryI* searchModel, Args* args) {
    this->searchModel = searchModel;
    this->args = args;
    this->searchResulPrinter = searchResulPrinter;
}

void SearchController::search(string& query) { std::cout << "Searching...\n"; }