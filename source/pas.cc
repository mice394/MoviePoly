#include "pas.h"
#include <string>
using namespace std;

PAS::PAS(){
    setPropPrice(100);
    setIsOwned(false);
    setPosition(8);
    setCanBeImproved(true);
    setImproveCost(50);
    setTuition(6, 30, 90, 270, 400, 550);
    setName("PAS");
}

PAS::~PAS() {}

