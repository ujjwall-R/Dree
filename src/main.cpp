using namespace std;

void solve() {}

int main(int argc, char* argv[]) {
    if (argc < 5)
        dree(argc, argv);
    else if (argc == 5)
        search(argc, argv);
    else
        cout << "Dree cannot execute the given command\n";
    return 0;
}
