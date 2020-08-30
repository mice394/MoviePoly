#include "purge.h"
#include <string>
using namespace std;

PURGE::PURGE(){
    setPropPrice(180);
    setIsOwned(false);
    setPosition(18);
    setCanBeImproved(true);
    setImproveCost(100);
    setTicketPrice(14, 70, 200, 550, 750, 950);
    setName("PURGE");
}

PURGE::~PURGE() {}

