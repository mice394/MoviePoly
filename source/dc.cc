#include "dc.h"
#include <string>
using namespace std;

DC::DC(){
    setPropPrice(400);
    setIsOwned(false);
    setPosition(39);
    setCanBeImproved(true);
    setImproveCost(200);
    setTuition(50, 200, 600, 1400, 1700, 2000);
    setName("DC");
}

DC::~DC() {}

