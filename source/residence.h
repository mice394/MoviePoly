#ifndef _RESIDENCE_H_
#define _RESIDENCE_H_
#include <string>
#include "property.h"

class Player;

class Residence : public Property{
    public:
    Residence();
    ~Residence();
    int calculateFee(int n) override;
    std::string getPropertyType();


    private:
        std::string propertyType;
};

#endif
