#ifndef _ROMANCE_H_
#define _ROMANCE_H_
#include <string>
#include "movies.h"

class ROMANCE : public MOVIES{
    public:
        ROMANCE();
        ~ROMANCE();
    
    private:
        std::vector<std::string> properties{"TITANIC", "NOTEBOOK"};
};

#endif
