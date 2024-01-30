#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include "../data_structures/Args.h"
#include "../model/DreeHelpersI.h"
#include "../model/SearchDirectoryI.h"
#include "../view/SearchResultsI.h"
#include "SearchControllerI.h"

using namespace std;

class SearchController : public SearchControllerI {
   private:
    Args* args;
    SearchDirectoryI* searchModel;
    SearchResultsI* searchResulPrinter;
    DreeHelpersI* dreeHelpers;

   public:
    void search(string& query, Args* args) override;

    SearchController(DreeHelpersI* dreeHelpers, SearchResultsI* searchResulPrinter, SearchDirectoryI* searchModel,
                     Args* args);
};

#endif