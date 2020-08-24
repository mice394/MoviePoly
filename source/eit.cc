#include "eit.h"
#include <string>
using namespace std;

EIT::EIT(){
    setPropPrice(300);
    setIsOwned(false);
    setPosition(31);
    setCanBeImproved(true);
    setImproveCost(200);
    setTuition(26, 130, 390, 900, 1100, 1275);
    setName("EIT");
}

EIT::~EIT() {}

