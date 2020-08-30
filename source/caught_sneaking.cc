#include <string.h>
#include "caught_sneaking.h"
#include "board.h"
#include "player.h"
using namespace std;

CAUGHTSNEAKING::CAUGHTSNEAKING(){
    setPosition(30);
    setName("CAUGHTSNEAKING");
}

CAUGHTSNEAKING::~CAUGHTSNEAKING(){}

void CAUGHTSNEAKING::movePlayer(Player * somePlayer){

    somePlayer->setPositions(10);
    somePlayer->setTimeSpentInTimeOut(0);
    somePlayer->setInTimeOut(true);
}

void CAUGHTSNEAKING::notify(Player * somePlayer) {
    if (somePlayer->getCurrPosition() == getPosition()) {
        movePlayer(somePlayer);
    }
}

