#ifndef _ENG_H_
#define _ENG_H_
#include <string>
#include "academic.h"

class Eng : public Academic{
    public:
        Eng();
        ~Eng();

    private:
        std::vector<std::string> properties{"CPH", "DWE", "RCH"};
};

#endif
