#include "DreeNavigateView.h"

void DreeNavigateView::navigate_dree(DreeNode* root, long long maxDepth) {
    initscr();
    keypad(stdscr, TRUE);
    raw();

    int ch;
    selectedDepth = 0;
    selectedStringIndex = 0;  // Added to track the selected string within the depth
    depth_first_search(root, maxDepth);

    while ((ch = getch()) != 10)  // 10 is the ASCII code for Enter key
    {
        switch (ch) {
            case KEY_UP:
                selectedDepth = max(0ll, selectedDepth - 1);
                break;
            case KEY_DOWN:
                selectedDepth = min(maxDepth, selectedDepth + 1);
                break;
            case KEY_RIGHT:
                selectedStringIndex = min((long long)nodeStrings[selectedDepth].size() - 1ll, selectedStringIndex + 1);
                break;
            case KEY_LEFT:
                selectedStringIndex = max(0ll, selectedStringIndex - 1);
                break;
        }
        clear();
        depth_first_search(root, maxDepth);
    }

    endwin();
}

void DreeNavigateView::dfs(DreeNode* node, long long depth, long long currentDepth, long long currentIndex,
                           bool isLastChild, long long mask) {
    for (long long i = 0; i < currentDepth; i++) {
        if (((mask >> i) & 1ll) == 0ll) {
            // cout << "│    ";
            addch(ACS_VLINE);  // '│'
            printw("    ");
        } else
            // cout << "     ";
            printw("     ");
    }
    // isLastChild ? cout << "└── " : cout << "├── ";

    if (isLastChild)
        addch(ACS_LLCORNER);  // '└'
    else
        addch(ACS_LTEE);  // '├'

    addch(ACS_HLINE);  // '─'
    addch(ACS_HLINE);  // '─'
    printw(" ");

    // cout << node->name << "\n";

    if (currentDepth < nodeStrings.size()) {
        nodeStrings[currentDepth].push_back(node->name);
    } else {
        std::vector<std::string> newDepthStrings = {node->name};
        nodeStrings.push_back(newDepthStrings);
    }

    if (currentIndex == selectedStringIndex && currentDepth == selectedDepth)
        attron(A_STANDOUT);  // Highlight the selected depth
    addstr(node->name.c_str());
    if (currentIndex == selectedStringIndex && currentDepth == selectedDepth) attroff(A_STANDOUT);

    printw("\n");

    for (size_t i = 0; i < node->children.size(); i++) {
        DreeNode* child = node->children[i];
        if (i == node->children.size() - 1) {
            mask = mask | (1ll << (currentDepth + 1));
        }
        dfs(child, depth, currentDepth + 1, i, i == node->children.size() - 1, mask);
    }
}

void DreeNavigateView::depth_first_search(DreeNode* node, long long maxDepth) {
    nodeStrings.clear();
    dfs(node, maxDepth, 0ll, 0ll, true, 1ll);
    refresh();
};
