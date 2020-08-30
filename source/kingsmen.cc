#include "kingsmen.h"
#include <string>
using namespace std;

KINGSMEN::KINGSMEN(){
    setPropPrice(100);
    setIsOwned(false);
    setPosition(6);
    setCanBeImproved(true);
    setImproveCost(50);
    setTicketPrice(6, 30, 90, 270, 400, 550);
    setName("KINGSMEN");
}

KINGSMEN::~KINGSMEN() {}

