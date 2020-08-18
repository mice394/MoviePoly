#include "phys.h"
#include <string>
using namespace std;

PHYS::PHYS(){
    setPropPrice(260);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(26);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(150);
    setTuition(22, 110, 330, 800, 975, 1150);
    setName("PHYS");
}

PHYS::~PHYS() {}

