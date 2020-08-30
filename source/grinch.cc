#include "grinch.h"
#include <string>
using namespace std;

GRINCH::GRINCH(){
    setPropPrice(160);
    setIsOwned(false);
    setPosition(14);
    setCanBeImproved(true);
    setImproveCost(100);
    setTicketPrice(12, 60, 180, 500, 700, 900);
    setName("GRINCH");
}

GRINCH::~GRINCH() {}

