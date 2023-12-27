#include "DreeIgnoreI.h"

using namespace std;

class DreeIgnore : public DreeIgnoreI {
   private:
    DreeIgnore* dree_ignored_files;

   public:
    bool file_is_in_dree_ignore(string& directoryString) override;
};