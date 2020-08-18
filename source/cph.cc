#include "cph.h"
#include <string>
using namespace std;

CPH::CPH(){
    setPropPrice(160);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(14);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(100);
    setTuition(12, 60, 180, 500, 700, 900);
    setName("CPH");
}

CPH::~CPH() {}

