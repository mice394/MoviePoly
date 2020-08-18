#include "bmh.h"
#include <string>
using namespace std;

BMH::BMH(){
    setPropPrice(180);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(18);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(100);
    setTuition(14, 70, 200, 550, 750, 950);
    setName("BMH");
}

BMH::~BMH() {}

