#ifndef _STDGHIBILI_H_
#define _STDGHIBILI_H_
#include <string>
#include "movies.h"

class STDGHIBILI : public MOVIES{
    public:
    STDGHIBILI();
    ~STDGHIBILI();
    
    private:
    std::vector<std::string> properties{"PONYO", "TOTORO"};
};

#endif
