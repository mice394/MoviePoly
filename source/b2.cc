#include "b2.h"
#include <string>
using namespace std;

B2::B2(){
    setPropPrice(280);
    setIsOwned(false);
    setPosition(29);
    setCanBeImproved(true);
    setImproveCost(150);
    setTuition(24, 120, 360, 850, 1025, 1200);
    setName("B2");
}

B2::~B2() {}

