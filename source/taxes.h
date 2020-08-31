#ifndef _TAXES_H_
#define _TAXES_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class TAXES : public NonProperty{
    public:
    TAXES();
    ~TAXES();
    void pay(Player * p);
    void notify(Player * p) override;

    private:
    
};

#endif
