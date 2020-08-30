#ifndef _FINE_H_
#define _FINE_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class FINE : public NonProperty{
    public:
    FINE();
    ~FINE();
    void pay(Player * p);
    void notify(Player * p) override;

    private:
    
};

#endif
