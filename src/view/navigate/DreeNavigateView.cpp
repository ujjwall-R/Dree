#include "DreeNavigateView.h"

#include <fstream>

DreeNavigateView::DreeNavigateView(DreeHelpersI* dreehelper) { dreeHelpersInterface = dreehelper; }

void DreeNavigateView::navigate_dree(DreeNode* root, long long maxDepth) {
    initscr();
    keypad(stdscr, TRUE);
    raw();

    int ch;
    selectedNode = root;
    depth_first_search(root, maxDepth);

    while ((ch = getch()) != 10)  // 10 is the ASCII code for Enter key
    {
        switch (ch) {
            case KEY_UP:
                if (selectedNode->left != nullptr) selectedNode = selectedNode->left;
                break;
            case KEY_DOWN:
                if (selectedNode->right != nullptr) selectedNode = selectedNode->right;
                break;
            case KEY_RIGHT:
                if (!selectedNode->children.empty()) selectedNode = selectedNode->children[0];
                break;
            case KEY_LEFT:
                if (selectedNode->parent != nullptr) selectedNode = selectedNode->parent;
                break;
        }
        clear();
        depth_first_search(root, maxDepth);
    }

    if (!dreeHelpersInterface->string_is_a_directory(selectedNode->path)) selectedNode = selectedNode->parent;

    std::ofstream outFile(".navigate", std::ios::out);
    if (outFile.is_open()) {
        outFile << selectedNode->path;
        outFile.close();
    } else {
        std::ofstream newFile(".navigate");
        if (newFile.is_open()) {
            newFile << selectedNode->path;
            newFile.close();
        } else {
            // Handle error creating or opening the file
            // You can print an error message or take appropriate action
        }
    }

    endwin();
}

void DreeNavigateView::dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask) {
    for (long long i = 0; i < currentDepth; i++) {
        if (((mask >> i) & 1ll) == 0ll) {
            addch(ACS_VLINE);  // '│'
            printw("    ");
        } else
            printw("     ");
    }

    if (isLastChild)
        addch(ACS_LLCORNER);  // '└'
    else
        addch(ACS_LTEE);  // '├'

    addch(ACS_HLINE);  // '─'
    addch(ACS_HLINE);  // '─'
    printw(" ");

    if (node == selectedNode) attron(A_STANDOUT);  // Highlight the selected depth
    addstr(node->name.c_str());
    if (node == selectedNode) attroff(A_STANDOUT);

    printw("\n");

    for (size_t i = 0; i < node->children.size(); i++) {
        DreeNode* child = node->children[i];
        if (i == node->children.size() - 1) {
            mask = mask | (1ll << (currentDepth + 1));
        }
        dfs(child, depth, currentDepth + 1, i == node->children.size() - 1, mask);
    }
}

void DreeNavigateView::depth_first_search(DreeNode* node, long long maxDepth) {
    dfs(node, maxDepth, 0ll, true, 1ll);
    refresh();
};
