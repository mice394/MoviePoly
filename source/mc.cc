#include "mc.h"
#include <string>
using namespace std;

MC::MC(){
    setPropPrice(350);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(37);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(200);
    setTuition(35, 175, 500, 1100, 1300, 1500);
    setName("MC");
}

MC::~MC() {}

