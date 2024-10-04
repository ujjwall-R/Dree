#include "SearchDirectory.h"
#include <iostream>
vector<pair<int, DreeNode *>> SearchDirectory::search(DreeNode *root, string &query, DreeHelpersI *dreeHelpers) {
    vector<pair<int, DreeNode *>> searchResult;
    traverse_directories(root, args->MaxDepth, 0, query, searchResult, dreeHelpers);
    return searchResult;
}

void SearchDirectory::traverse_directories(DreeNode *node, long long depth, long long currentDepth, const string &query,
                                           vector<pair<int, DreeNode *>> &results, DreeHelpersI *dreehelpers) {
    if (currentDepth > depth) {
        return;
    }
    int score1 = dreehelpers->levenshtein_distance_between_strings(node->name, query);
    int score2 = dreehelpers->levenshtein_distance_between_strings(node->path, query);

    if (score1 * 100 <= (50 * query.length()) || score2 * 100 <= (50 * query.length())) {
        results.push_back({min(score1, score2), node});
    }

    if (!dreehelpers->string_is_a_directory(node->path)) {
        return;
    }

    try {
        for (const auto &entry : filesystem::directory_iterator(node->path)) {
            string childDirectory = entry.path().string();
            DreeNode *child = new DreeNode(childDirectory);
            node->children.push_back(child);
            traverse_directories(child, depth, currentDepth + 1, query, results, dreehelpers);
        }
    } catch (const std::exception &e) {
    }
}

SearchDirectory::SearchDirectory(Args *args) { this->args = args; }