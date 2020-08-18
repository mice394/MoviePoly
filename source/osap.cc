#include <string>
#include "osap.h"
#include "board.h"
#include "player.h"
using namespace std;

OSAP::OSAP() {
    setPosition(0);
    setName("OSAP");
}

OSAP::~OSAP() {
    
}

void OSAP::notify(Player * somePlayer) {
    if (somePlayer->getCurrPosition() == getPosition()) {
        cout << "Congrats! You got OSAP." << endl;

        int n = somePlayer->getCurrMoney() + 200;
        somePlayer->setCurrMoney(n);
    }
}
