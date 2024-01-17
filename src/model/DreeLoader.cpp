#include "DreeLoader.h"
#include <iostream>

void DreeLoader::traverse_dfs_and_build_tree(DreeNode *node, long long depth, long long currentDepth) {
    if (currentDepth > depth) return;
    try {
        for (const auto &entry : filesystem::directory_iterator(node->path)) {
            // if (!dreeIgnoreInterface->file_is_in_dree_ignore(entry.path().filename().string())) continue;

            string childDirectory = entry.path().string();
            DreeNode *child = new DreeNode(childDirectory);
            node->children.push_back(child);
        }
    } catch (const std::exception &e) {
        // this->allFilesPermited = false;
    }

    for (auto ch : node->children) {
        if (dreeHelpersInterface->string_is_a_directory(ch->path)) {
            traverse_dfs_and_build_tree(ch, depth, currentDepth + 1);
        }
    }
}

DreeNode *DreeLoader::load_dree(Args *args) {
    DreeNode *root = new DreeNode(args->currentPath);
    traverse_dfs_and_build_tree(root, args->MaxDepth, 0);
    return root;
}
