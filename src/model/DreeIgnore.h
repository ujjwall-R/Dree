#include "DreeIgnoreI.h"

using namespace std;

class DreeIgnore : public DreeIgnoreI {
   public:
    bool file_is_in_dree_ignore(string directoryString) override;
};