#include "frozen.h"
#include <string>
using namespace std;

FROZEN::FROZEN(){
    setPropPrice(220);
    setIsOwned(false);
    setPosition(21);
    setCanBeImproved(true);
    setImproveCost(150);
    setTicketPrice(18, 90, 250, 700, 875, 1050);
    setName("FROZEN");
}

FROZEN::~FROZEN() {}

