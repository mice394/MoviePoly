#include "ev3.h"
#include <string>
using namespace std;

EV3::EV3(){
    setPropPrice(240);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(24);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(150);
    setTuition(20, 100, 300, 750, 925, 1100);
    setName("EV3");
}

EV3::~EV3() {}

