#ifndef _NEEDLES_HALL_H_
#define _NEEDLES_HALL_H_
#include <string>
#include "non_property.h"

class Player;

class NeedlesHall : public NonProperty{
    public:
    NeedlesHall(int n);
    ~NeedlesHall();
    void amountChange(Player * currentPlayer);
    void notify(Player * p) override;

    private:
};

#endif
