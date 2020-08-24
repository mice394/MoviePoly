#include "mc.h"
#include <string>
using namespace std;

MC::MC(){
    setPropPrice(350);
    setIsOwned(false);
    setPosition(37);
    setCanBeImproved(true);
    setImproveCost(200);
    setTuition(35, 175, 500, 1100, 1300, 1500);
    setName("MC");
}

MC::~MC() {}

