#ifndef HELPCONTROLLERI_H
#define HELPCONTROLLERI_H

class HelpControllerI {
   public:
    virtual void help() = 0;
    virtual ~HelpControllerI() = default;
};

#endif