#include <string>
#include "ticket.h"
#include "board.h"
#include "player.h"
using namespace std;

TICKET::TICKET() {
    setPosition(0);
    setName("TICKET");
}

TICKET::~TICKET() {
    
}

void TICKET::notify(Player * somePlayer) {
    if (somePlayer->getCurrPosition() == getPosition()) {
        cout << "Congrats! You got money for a free ticket." << endl;

        int n = somePlayer->getCurrMoney() + 200;
        somePlayer->setCurrMoney(n);
    }
}
