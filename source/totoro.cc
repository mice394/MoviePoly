#include "totoro.h"
#include <string>
using namespace std;

TOTORO::TOTORO(){
    setPropPrice(60);
    setIsOwned(false);
    setPosition(3);
    setCanBeImproved(true);
    setImproveCost(50);
    setTicketPrice(4, 20, 60, 180, 320, 450);
    setName("TOTORO");
}

TOTORO::~TOTORO(){}

