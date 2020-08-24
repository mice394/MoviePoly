#include "cph.h"
#include <string>
using namespace std;

CPH::CPH(){
    setPropPrice(160);
    setIsOwned(false);
    setPosition(14);
    setCanBeImproved(true);
    setImproveCost(100);
    setTuition(12, 60, 180, 500, 700, 900);
    setName("CPH");
}

CPH::~CPH() {}

