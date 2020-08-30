#ifndef _CHANCE_H_
#define _CHANCE_H_
#include <string>
#include "non_property.h"

class Player;

class CHANCE : public NonProperty{
    public:
    CHANCE(int n);
    ~CHANCE();
    void amountChange(Player * currentPlayer);
    void notify(Player * p) override;

    private:
};

#endif
