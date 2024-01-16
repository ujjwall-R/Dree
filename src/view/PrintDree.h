#include <iostream>
#include "PrintDreeI.h"
using namespace std;

class PrintDree : public PrintDreeI {
   public:
    void depth_first_search(DreeNode* node);
    void breadth_first_search(DreeNode* node);
};