#ifndef SEARCHRESULTSI_H
#define SEARCHRESULTSI_H

#include <vector>

class SearchResultsI {
   public:
    virtual void print_search_results(std::vector<std::pair<int, std::pair<std::string, std::string>>> &searchResult) = 0;
};

#endif