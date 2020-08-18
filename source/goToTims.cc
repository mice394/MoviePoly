#include <string.h>
#include "goToTims.h"
#include "board.h"
#include "player.h"
using namespace std;

GoToTims::GoToTims(){
    setPosition(30);
    setName("GOTOTIMS");
}

GoToTims::~GoToTims(){}

void GoToTims::movePlayer(Player * somePlayer){

    somePlayer->setPositions(10);
    somePlayer->setTimeSpentInTims(0);
    // curr.setNumDoubles(0);
    somePlayer->setInTimsLine(true);
}

void GoToTims::notify(Player * somePlayer) {
    if (somePlayer->getCurrPosition() == getPosition()) {
        movePlayer(somePlayer);
    }
}

