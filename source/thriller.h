#ifndef _THRILLER_H_
#define _THRILLER_H_
#include <string>
#include "movies.h"

class THRILLER : public MOVIES{
    public:
        THRILLER();
        ~THRILLER();

    private:
        std::vector<std::string> properties{"BURNING", "MOTHER", "PARASITE"};
};

#endif
