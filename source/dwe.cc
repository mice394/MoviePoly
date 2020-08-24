#include "dwe.h"
#include <string>
using namespace std;

DWE::DWE(){
    setPropPrice(140);
    setIsOwned(false);
    setPosition(13);
    setCanBeImproved(true);
    setImproveCost(100);
    setTuition(10, 50, 150, 450, 625, 750);
    setName("DWE");
}

DWE::~DWE() {}

