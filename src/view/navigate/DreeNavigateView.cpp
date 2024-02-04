#include "DreeNavigateView.h"

void DreeNavigateView::navigate_dree(DreeNode* root, long long maxDepth) {

    initscr();
    keypad(stdscr, TRUE);
    raw();

    int ch;
    selectedDepth = 0;
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
        }
        clear();
        depth_first_search(root, maxDepth);
    }

    endwin();
}

void DreeNavigateView::dfs(DreeNode* node, long long depth, long long currentDepth, bool isLastChild, long long mask) {
    for (long long i = 0; i < currentDepth; i++) {
        if (((mask >> i) & 1ll) == 0ll)
            // cout << "│    ";
            addch(ACS_VLINE);  // '│'
        else
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

    if (currentDepth == selectedDepth) attron(A_STANDOUT);  // Highlight the selected depth
    addstr(node->name.c_str());
    if (currentDepth == selectedDepth) attroff(A_STANDOUT);

    printw("\n");

    cout << node->name << "\n";
    for (size_t i = 0; i < node->children.size(); i++) {
        DreeNode* child = node->children[i];
        if (i == node->children.size() - 1) {
            mask = mask | (1ll << (currentDepth + 1));
        }
        dfs(child, depth, currentDepth + 1, i == node->children.size() - 1, mask);
    }
    // node->children.clear();
}

void DreeNavigateView::depth_first_search(DreeNode* node, long long maxDepth) {
    // initscr();
    // keypad(stdscr, TRUE);
    // raw();
    dfs(node, maxDepth, 0ll, true, 1ll);
    refresh();
    // endwin();
    //
};

void DreeNavigateView::breadth_first_search(DreeNode* node, long long maxDepth){};
