#include "al.h"
#include <string>
using namespace std;

AL::AL(){
    setPropPrice(40);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(1);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(50);
    setTuition(2, 10, 30, 90, 160, 250);
    setName("AL");

    //setPosition()
}

AL::~AL() {}

