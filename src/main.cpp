#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "controller/DreeController.h"
#include "data_structures/Args.h"
#include "model/DreeIgnore.h"
#include "model/DreeLoader.h"
#include "view/PrintDree.h"

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
    // ... (your existing code)

#ifdef __linux__
    size_t initialMemory = getMemoryUsageKB();
    cout << "Initial memory usage: " << initialMemory << " KB" << endl;
#endif

    if (argc < 5) {
        PrintDree dreePrinter;
        DreeIgnore dreeIgnore;
        DreeLoader dreeLoader(&dreeIgnore);

        Args* arg = new Args(stoll(argv[2]), argv[1]);
        DreeControllerI* controller = new DreeController(&dreeLoader, &dreePrinter);
        controller->print_dree(arg);

        delete arg;
        delete controller;
    }

#ifdef __linux__
    size_t finalMemory = getMemoryUsageKB();
    cout << "Final memory usage: " << finalMemory << " KB" << endl;
    cout << "Memory change: " << finalMemory - initialMemory << " KB" << endl;
#endif

    return 0;
}
