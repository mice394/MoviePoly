#include "ech.h"
#include <string>
using namespace std;

ECH::ECH(){
    setPropPrice(100);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(6);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(50);
    setTuition(6, 30, 90, 270, 400, 550);
    setName("ECH");
}

ECH::~ECH() {}

