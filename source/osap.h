#ifndef _OSAP_H_
#define _OSAP_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class OSAP : public NonProperty {
    public:
        OSAP();
        ~OSAP();
        void receiveMoney();
        void notify(Player * somePlayer) override;

    private:
    
};

#endif
