#include "b2.h"
#include <string>
using namespace std;

B2::B2(){
    setPropPrice(280);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(29);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(150);
    setTuition(24, 120, 360, 850, 1025, 1200);
    setName("B2");
}

B2::~B2() {}

