#ifndef _COOP_H_
#define _COOP_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class Coop : public NonProperty{
    public:
    Coop();
    ~Coop();
    void pay(Player * p);
    void notify(Player * p) override;

    private:
    
};

#endif
