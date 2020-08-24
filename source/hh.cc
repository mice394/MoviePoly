#include "hh.h"
#include <string>
using namespace std;

HH::HH(){
    setPropPrice(120);
    setIsOwned(false);
    setPosition(9);
    setCanBeImproved(true);
    setImproveCost(50);
    setTuition(8, 40, 100, 300, 450, 600);
    setName("HH");
}

HH::~HH() {}

