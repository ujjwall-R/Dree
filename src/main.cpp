#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "controller/DreeController.h"
#include "controller/HelpController.h"
#include "controller/SearchController.h"
#include "controller/navigate/DreeNavigate.h"
#include "data_structures/Args.h"
#include "model/DreeIgnore.h"
#include "model/DreeLoader.h"
#include "model/SearchDirectory.h"
#include "view/AboutDree.h"
#include "view/PrintDree.h"
#include "view/SearchResults.h"
#include "view/navigate/DreeNavigateView.h"

#ifdef __linux__
#include <unistd.h>
#endif

using namespace std;

#ifdef __linux__
size_t getMemoryUsageKB() {
    size_t memoryUsage = 0;
    ifstream statusFile("/proc/self/status");
    string line;

    while (getline(statusFile, line)) {
        if (line.compare(0, 6, "VmRSS:") == 0) {
            istringstream iss(line.substr(7));
            iss >> memoryUsage;
            break;
        }
    }

    return memoryUsage;
}
#endif

int main(int argc, char* argv[]) {

    // initscr();
    // keypad(stdscr, TRUE);
    // raw();

    // #ifdef __linux__
    //     size_t initialMemory = getMemoryUsageKB();
    //     cout << "Initial memory usage: " << initialMemory << " KB" << endl;
    // #endif

    if (argc == 3 && strcmp(argv[2], "--help") == 0) {
        string flag = argv[2];
        AboutDree aboutView;
        HelpControllerI* controller = new HelpController(&aboutView);
        controller->help();
    }
    else if (argc == 3 || (argc == 4 && strcmp(argv[3], "-n") != 0)) {
        Args* arg = new Args(stoll(argv[2]), argv[1]);
        if (arg->MaxDepth > 60) {
            cout << "Depth overflow!!\nAre you serious?" << endl;
            return 0;
        }
        DreeHelpers dreeHelpers;

        PrintDree dreePrinter;
        bool dreeIgnoreIsActive = !((argc == 4) && (strcmp(argv[3], "-a") == 0));
        DreeIgnore* dreeIgnore = new DreeIgnore(dreeIgnoreIsActive);
        DreeLoader dreeLoader(dreeIgnore, &dreeHelpers);

        DreeControllerI* controller = new DreeController(&dreeLoader, &dreePrinter);
        controller->print_dree(arg);

        return 0;
    }
    else if (argc >= 3 && argc <= 5 && strcmp(argv[3], "-f") != 0) {
        if ((argc >= 4) && strcmp(argv[3], "-n") == 0) {
            Args* arg = new Args(stoll(argv[2]), argv[1]);
            if (arg->MaxDepth > 60) {
                cout << "Depth overflow!!\nAre you serious?" << endl;
                return 0;
            }

            DreeHelpers dreeHelpers;
            DreeNavigateView* dreeNavigateView = new DreeNavigateView(&dreeHelpers);
            bool dreeIgnoreIsActive = !((argc == 5) && (strcmp(argv[4], "-a") == 0));
            DreeIgnore* dreeIgnore = new DreeIgnore(dreeIgnoreIsActive);
            DreeLoader dreeLoader(dreeIgnore, &dreeHelpers);

            IDreeNavigate* controller = new DreeNavigate(&dreeLoader, dreeNavigateView);
            controller->display_dree(arg);

            return 0;
        }
    }
    else if (argc == 5 && strcmp(argv[3], "-f") == 0) {
        DreeHelpers dreeHelpers;
        SearchResults searchResulPrinter;
        Args* args = new Args(stoll(argv[2]), argv[1]);
        SearchDirectory searchModel(args);

        SearchControllerI* searchController =
            new SearchController(&dreeHelpers, &searchResulPrinter, &searchModel, args);
        string query = argv[4];
        searchController->search(query, args);

    }
    else {
        cout << "Command Not Found!\n Run: Dree --help to learn more\n";
    }
    // #ifdef __linux__
    //     size_t finalMemory = getMemoryUsageKB();
    //     cout << "Final memory usage: " << finalMemory << " KB" << endl;
    //     cout << "Memory change: " << finalMemory - initialMemory << " KB" << endl;
    // #endif

    // endwin();
    return 0;
}
