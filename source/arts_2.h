#ifndef _ARTS_2_H_
#define _ARTS_2_H_
#include <string>
#include "academic.h"

class Arts2 : public Academic{
    public:
        Arts2();
        ~Arts2();

    private:
        std::vector<std::string> properties{"ECH", "PAS", "HH"};
};

#endif
