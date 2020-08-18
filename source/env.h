#ifndef _ENV_H_
#define _ENV_H_
#include <string>
#include "academic.h"

class Env : public Academic{
    public:
        Env();
        ~Env();
    
    private:
        std::vector<std::string> properties{"EV1", "EV2", "EV3"};
};

#endif
