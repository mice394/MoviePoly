#include "rch.h"
#include <string>
using namespace std;

RCH::RCH(){
    setPropPrice(140);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(11);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(100);
    setTuition(10, 50, 150, 450, 625, 750);
    setName("RCH");
}

RCH::~RCH() {}

