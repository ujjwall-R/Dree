#include "SearchDirectory.h"
#include <iostream>
vector<pair<int, pair<string, string>>> SearchDirectory::search(DreeNode *root, string &query, DreeHelpersI *dreeHelpers) {
    vector<pair<int, pair<string, string>>> searchResult;
    traverse_directories(root, args->MaxDepth, 0, query, searchResult, dreeHelpers);
    return searchResult;
}

void SearchDirectory::traverse_directories(DreeNode *node, long long depth, long long currentDepth, const string &query,
                                           vector<pair<int, pair<string, string>>> &results, DreeHelpersI *dreehelpers) {
    if (currentDepth > depth) {
        return;
    }
    int score1 = dreehelpers->levenshtein_distance_between_strings(node->name, query);
    int score2 = dreehelpers->levenshtein_distance_between_strings(node->path, query);

    if (score1 * 100 <= (50 * query.length()) || score2 * 100 <= (50 * query.length())) {
        results.push_back({min(score1, score2), {node->name, node->path}});
    }

    if (!dreehelpers->string_is_a_directory(node->path)) {
        return;
    }

    DreeNode *child;

    try {
        
        for (const auto &entry : filesystem::directory_iterator(node->path)) {
            string childDirectory = entry.path().string();
            child = new DreeNode(childDirectory);
            node->children.push_back(child);
            traverse_directories(child, depth, currentDepth + 1, query, results, dreehelpers);

            delete child;
            child = nullptr;
            node->children.pop_back();
        }
    } catch (const std::exception &e) {
        delete child; 
        child = nullptr; 
    } 
}

SearchDirectory::SearchDirectory(Args *args) { this->args = args; }