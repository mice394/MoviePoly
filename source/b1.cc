#include "b1.h"
#include <string>
using namespace std;

B1::B1() {
    setPropPrice(260);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(27);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(150);
    setTuition(22, 110, 330, 800, 975, 1150);
    setName("B1");
}

B1::~B1() {}
