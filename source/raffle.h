#ifndef _RAFFLE_H
#define _RAFFLE_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include "non_property.h"

class RAFFLE : public NonProperty{
    public:
        RAFFLE(int n);
        ~RAFFLE();
        void whichMovement(Player * somePlayer);
        void notify(Player * somePlayer) override;
        //pos =3, 18, 34

    private:
    
};

#endif

