#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_
#include <string>
#include "non_property.h"

class Board;
class Player;

class GoToTims : public NonProperty{
    public:
    GoToTims();
    ~GoToTims();
    void movePlayer(Player * somePlayer);
    void notify(Player * somePlayer) override;

    private:
    
};

#endif
