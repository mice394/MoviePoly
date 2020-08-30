#ifndef _ACTION_H_
#define _ACTION_H_
#include <string>
#include "movies.h"

class ACTION : public MOVIES{
    public:
        ACTION();
        ~ACTION();

    private:
        std::vector<std::string> properties{"AVENGERS", "SKYFALL", "NONSTOP"};
};

#endif
