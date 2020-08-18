#ifndef _SCI_1_H_
#define _SCI_1_H_
#include <string>
#include "academic.h"

class Sci1 : public Academic{
    public:
        Sci1();
        ~Sci1();

    private:
        std::vector<std::string> properties{"PHYS", "B1", "B2"};
};

#endif
