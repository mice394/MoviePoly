#ifndef _SCI_2_H_
#define _SCI_2_H_
#include <string>
#include "academic.h"

class Sci2 : public Academic{
    public:
        Sci2();
        ~Sci2();

    private:
        std::vector<std::string> properties{"EIT", "ESC", "C2"};
};

#endif
