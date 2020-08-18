#ifndef _HEALTH_H_
#define _HEALTH_H_
#include <string>
#include "academic.h"

class Health : public Academic{
    public:
        Health();
        ~Health();

    private:
        std::vector<std::string> properties{"OPT", "LHI", "BMH"};
};

#endif
