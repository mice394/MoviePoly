#ifndef _ARTS_1_H_
#define _ARTS_1_H_
#include <string>
#include "academic.h"

class Arts1 : public Academic{
    public:
    Arts1();
    ~Arts1();
    
    private:
    std::vector<std::string> properties{"AL", "ML"};
};

#endif
