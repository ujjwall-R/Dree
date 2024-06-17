#include "SearchController.h"
#include <iostream>

SearchController::SearchController(DreeHelpersI* dreeHelpers, SearchResultsI* searchResulPrinter,
    SearchDirectoryI* searchModel, Args* args) {
    this->searchModel = searchModel;
    this->args = args;
    this->searchResulPrinter = searchResulPrinter;
    this->dreeHelpers = dreeHelpers;
}

void SearchController::search(string& query, Args* args) {
    DreeNode* root = new DreeNode(args->currentPath);
    auto searchResult = searchModel->search(root, query, dreeHelpers);
    searchResulPrinter->print_search_results(searchResult);
}