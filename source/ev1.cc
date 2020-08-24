#include "ev1.h"
#include <string>
using namespace std;

EV1::EV1(){
    setPropPrice(220);
    setIsOwned(false);
    setPosition(21);
    setCanBeImproved(true);
    setImproveCost(150);
    setTuition(18, 90, 250, 700, 875, 1050);
    setName("EV1");
}

EV1::~EV1() {}

