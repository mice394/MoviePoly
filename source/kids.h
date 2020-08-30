#ifndef _KIDS_H_
#define _KIDS_H_
#include <string>
#include "movies.h"

class KIDS : public MOVIES{
    public:
        KIDS();
        ~KIDS();
    
    private:
        std::vector<std::string> properties{"FROZEN", "MULAN", "ALADDIN"};
};

#endif
