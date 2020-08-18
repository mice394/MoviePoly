#include "c2.h"
#include <string>
using namespace std;

C2::C2(){
    setPropPrice(320);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(34);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(200);
    setTuition(28, 150, 450, 1000, 1200, 1400);
    setName("C2");
}

C2::~C2() {}

