#ifndef PRINTDREEI_H
#define PRINTDREEI_H

class PrintDreeI {
   public:
    virtual void depth_first_search() const = 0;

    virtual void breadth_first_search() const = 0;
};

#endif