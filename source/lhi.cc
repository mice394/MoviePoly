#include "lhi.h"
#include <string>
using namespace std;

LHI::LHI(){
    setPropPrice(180);
    setIsOwned(false);
    setPosition(16);
    setCanBeImproved(true);
    setImproveCost(100);
    setTuition(14, 70, 200, 550, 750, 950);
    setName("LHI");
}

LHI::~LHI() {}

