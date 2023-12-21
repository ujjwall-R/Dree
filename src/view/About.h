#ifndef ABOUT_H
#define ABOUT_H

#include "AboutI.h"

class About : public AboutI {
   public:
    void print_help_instructions() override;
};

#endif
