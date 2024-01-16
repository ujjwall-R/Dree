#include <iostream>
#include "controller/DreeController.h"
#include "data_structures/Args.h"
#include "model/DreeLoader.h"
#include "view/PrintDree.h"

using namespace std;

void solve() {}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        // dree(argc, argv);
        PrintDree dreePrinter;
        DreeLoader dreeLoader;

        Args* arg = new Args(stoll(argv[2]), argv[1]);
        DreeControllerI* controller = new DreeController(&dreeLoader, &dreePrinter);
        controller->print_dree(arg);
    }
    //  else if (argc == 5)
    //     search(argc, argv);
    // else
    //     cout << "Dree cannot execute the given command\n";
    return 0;
}
