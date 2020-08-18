#ifndef SLC_H
#define SLC_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include "non_property.h"

class SLC : public NonProperty{
    public:
        SLC(int n);
        ~SLC();
        void whichMovement(Player * somePlayer);
        void notify(Player * somePlayer) override;
        //pos =3, 18, 34

    private:
    
};

#endif

