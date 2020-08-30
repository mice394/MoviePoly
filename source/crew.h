#ifndef _CREW_H_
#define _CREW_H_
#include <string>
#include "property.h"

class Player;

class CREW : public Property{
    public:
    CREW();
    ~CREW();
    int calculateFee(int n) override;
    std::string getPropertyType();


    private:
        std::string propertyType;
};

#endif
