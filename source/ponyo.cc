#include "ponyo.h"
#include <string>
using namespace std;

PONYO::PONYO(){
    setPropPrice(40);
    setIsOwned(false);
    setPosition(1);
    setCanBeImproved(true);
    setImproveCost(50);
    setTicketPrice(2, 10, 30, 90, 160, 250);
    setName("PONYO");
}

PONYO::~PONYO() {}

