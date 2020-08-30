#include "aladdin.h"
#include <string>
using namespace std;

ALADDIN::ALADDIN(){
    setPropPrice(240);
    setIsOwned(false);
    setPosition(24);
    setCanBeImproved(true);
    setImproveCost(150);
    setTicketPrice(20, 100, 300, 750, 925, 1100);
    setName("ALADDIN");
}

ALADDIN::~ALADDIN() {}

