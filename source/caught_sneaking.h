#ifndef _CAUGHT_SNEAKING_H_
#define _CAUGHT_SNEAKING_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class CAUGHTSNEAKING : public NonProperty{
    public:
    CAUGHTSNEAKING();
    ~CAUGHTSNEAKING();
    void movePlayer(Player * somePlayer);
    void notify(Player * somePlayer) override;

    private:
    
};

#endif
