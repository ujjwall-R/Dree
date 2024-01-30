#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H

#include <vector>
#include "../data_structures/DreeNode.h"
#include "SearchResultsI.h"

using namespace std;

class SearchResults : public SearchResultsI {
   public:
    void print_search_results(vector<pair<int, DreeNode *>> &searchResult) override;
};

#endif