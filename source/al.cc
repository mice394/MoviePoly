#include "al.h"
#include <string>
using namespace std;

AL::AL(){
    setPropPrice(40);
    setIsOwned(false);
    setPosition(1);
    setCanBeImproved(true);
    setImproveCost(50);
    setTuition(2, 10, 30, 90, 160, 250);
    setName("AL");
}

AL::~AL() {}

