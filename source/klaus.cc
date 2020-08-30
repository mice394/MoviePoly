#include "klaus.h"
#include <string>
using namespace std;

KLAUS::KLAUS(){
    setPropPrice(140);
    setIsOwned(false);
    setPosition(13);
    setCanBeImproved(true);
    setImproveCost(100);
    setTicketPrice(10, 50, 150, 450, 625, 750);
    setName("KLAUS");
}

KLAUS::~KLAUS() {}

