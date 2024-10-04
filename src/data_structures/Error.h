#ifndef ERROR_H
#define ERROR_H

#include <string>

class Error {
   private:
    std::string message;

   public:
    Error(const std::string& message);
};

#endif
