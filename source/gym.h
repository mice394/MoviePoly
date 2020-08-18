#ifndef _GYM_H_
#define _GYM_H_
#include <string>
#include "property.h"

class Dice;
class Player;

class Gym : public Property{
    public:
    Gym();
    ~Gym();
    int calculateFee(int n) override;
    std::string getPropertyType();

    private:
    std::string propertyType;
};


#endif
