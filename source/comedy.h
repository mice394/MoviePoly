#ifndef _COMEDY_H_
#define _COMEDY_H_
#include <string>
#include "movies.h"

class COMEDY : public MOVIES{
    public:
        COMEDY();
        ~COMEDY();

    private:
        std::vector<std::string> properties{"HANGOVER", "SUPERBAD", "KINGSMEN"};
};

#endif
