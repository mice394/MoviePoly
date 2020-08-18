#include "esc.h"
#include <string>
using namespace std;

ESC::ESC(){
    setPropPrice(300);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(32);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(200);
    setTuition(26, 130, 390, 900, 1100, 1275);
    setName("ESC");
}

ESC::~ESC() {}

