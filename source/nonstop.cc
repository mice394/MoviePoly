#include "nonstop.h"
#include <string>
using namespace std;

NONSTOP::NONSTOP(){
    setPropPrice(280);
    setIsOwned(false);
    setPosition(29);
    setCanBeImproved(true);
    setImproveCost(150);
    setTicketPrice(24, 120, 360, 850, 1025, 1200);
    setName("NONSTOP");
}

NONSTOP::~NONSTOP() {}

