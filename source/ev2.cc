#include "ev2.h"
#include <string>
using namespace std;

EV2::EV2(){
    setPropPrice(220);
    setIsOwned(false);
    setPosition(23);
    setCanBeImproved(true);
    setImproveCost(150);
    setTuition(18, 90, 250, 700, 875, 1050);
    setName("EV2");
}

EV2::~EV2() {}

