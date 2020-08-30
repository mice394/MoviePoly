#ifndef _HORROR_H_
#define _HORROR_H_
#include <string>
#include "movies.h"

class HORROR : public MOVIES{
    public:
        HORROR();
        ~HORROR();

    private:
        std::vector<std::string> properties{"IT", "PURGE", "CARRIE"};
};

#endif
