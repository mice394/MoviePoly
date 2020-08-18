#ifndef _MATH_H_
#define _MATH_H_
#include <string>
#include "academic.h"

class Math : public Academic{
    public:
        Math();
        ~Math();
    
    private:
        std::vector<std::string> properties{"DC", "MC"};
};

#endif
