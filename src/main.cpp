#include <controller/DreeController.h>
#include <model/DreeLoader.h>

using namespace std;

void solve() {}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        // dree(argc, argv);
        DreeControllerI* controller = new DreeController();
        controller->print_dree(argc, argv);
    } else if (argc == 5)
        search(argc, argv);
    else
        cout << "Dree cannot execute the given command\n";
    return 0;
}
