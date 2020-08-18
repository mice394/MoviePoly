#include "eit.h"
#include <string>
using namespace std;

EIT::EIT(){
    setPropPrice(300);
    setIsOwned(false);
    //Owner
    //isMonopoly?
    setPosition(31);
    setCanBeImproved(true);
    // setNumImprove(0);
    setImproveCost(200);
    setTuition(26, 130, 390, 900, 1100, 1275);
    setName("EIT");
}

EIT::~EIT() {}

