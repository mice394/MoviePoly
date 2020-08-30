#ifndef _VIEWING_H_
#define _VIEWING_H_
#include <string>
#include "property.h"

class Dice;
class Player;

class VIEWING : public Property{
    public:
    VIEWING();
    ~VIEWING();
    int calculateFee(int n) override;
    std::string getPropertyType();

    private:
    std::string propertyType;
};


#endif
