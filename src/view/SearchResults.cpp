#include "SearchResults.h"
#include <algorithm>
#include <iostream>

void SearchResults::print_search_results(vector<pair<int, DreeNode *>> &searchResult) {
    sort(searchResult.begin(), searchResult.end());
    if (searchResult.empty()) {
        cout << "No results found\n";
    } else {
        if (searchResult[0].first == 0) {
            cout << "Search Results:\n";
            int cnt = 0;
            for (auto res : searchResult) {
                if (res.first > 0) break;

                cout << cnt + 1 << ".\t";
                cout << res.second->name << "\t\t" << res.second->path << "\n";
                cnt++;
            }
        } else {
            cout << "Couldn't find results. Did you mean?:\n";
            int cnt = 0;
            for (auto res : searchResult) {
                cout << cnt + 1 << ".\t";
                cout << res.second->name << "\t\t" << res.second->path << "\n";
                cnt++;
            }
        }
    }
}
