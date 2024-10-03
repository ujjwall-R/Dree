#include <fstream>
#include <set>
#include "DreeIgnoreI.h"

using namespace std;

class DreeIgnore : public DreeIgnoreI {
   private:
    set<string> excludedDirectories;
    bool active;

   public:
    bool file_is_in_dree_ignore(string directoryString) override;

    explicit DreeIgnore(bool active);
};