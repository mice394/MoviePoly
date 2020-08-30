#include "burning.h"
#include <string>
using namespace std;

BURNING::BURNING(){
    setPropPrice(300);
    setIsOwned(false);
    setPosition(31);
    setCanBeImproved(true);
    setImproveCost(200);
    setTicketPrice(26, 130, 390, 900, 1100, 1275);
    setName("BURNING");
}

BURNING::~BURNING() {}

