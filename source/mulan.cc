#include "mulan.h"
#include <string>
using namespace std;

MULAN::MULAN(){
    setPropPrice(220);
    setIsOwned(false);
    setPosition(23);
    setCanBeImproved(true);
    setImproveCost(150);
    setTicketPrice(18, 90, 250, 700, 875, 1050);
    setName("MULAN");
}

MULAN::~MULAN() {}

