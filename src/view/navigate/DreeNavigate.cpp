#include "DreeNavigate.h"

void DreeNavigate::dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask) {
    for (long long i = 0; i < currentDepth; i++) {
        if (((mask >> i) & 1ll) == 0ll)
            cout << "│    ";
        else
            cout << "     ";
    }
    isLastChild ? cout << "└── " : cout << "├── ";

    cout << node->name << "\n";
    for (size_t i = 0; i < node->children.size(); i++) {
        DreeNode* child = node->children[i];
        if (i == node->children.size() - 1) {
            mask = mask | (1ll << (currentDepth + 1));
        }
        dfs(child, depth, currentDepth + 1, i == node->children.size() - 1, mask);
    }
    node->children.clear();
    delete node;
}

void DreeNavigate::depth_first_search(DreeNode* node, long long maxDepth) {
    dfs(node, maxDepth, 0ll, true, 1ll);
    //
};

void DreeNavigate::breadth_first_search(DreeNode* node, long long maxDepth){};
