#ifndef _TUITION_H_
#define _TUITION_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class Tuition : public NonProperty{
    public:
    Tuition();
    ~Tuition();
    void pay(Player * p);
    void notify(Player * p) override;

    private:
    
};

#endif
