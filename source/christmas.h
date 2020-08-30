#ifndef _CHRISTMAS_H_
#define _CHRISTMAS_H_
#include <string>
#include "movies.h"

class CHRISTMAS : public MOVIES{
    public:
        CHRISTMAS();
        ~CHRISTMAS();

    private:
        std::vector<std::string> properties{"ELF", "KLAUS", "GRINCH"};
};

#endif
