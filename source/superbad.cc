#include "superbad.h"
#include <string>
using namespace std;

SUPERBAD::SUPERBAD(){
    setPropPrice(100);
    setIsOwned(false);
    setPosition(8);
    setCanBeImproved(true);
    setImproveCost(50);
    setTicketPrice(6, 30, 90, 270, 400, 550);
    setName("SUPERBAD");
}

SUPERBAD::~SUPERBAD() {}

