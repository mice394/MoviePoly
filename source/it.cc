#include "it.h"
#include <string>
using namespace std;

IT::IT(){
    setPropPrice(180);
    setIsOwned(false);
    setPosition(16);
    setCanBeImproved(true);
    setImproveCost(100);
    setTicketPrice(14, 70, 200, 550, 750, 950);
    setName("IT");
}

IT::~IT() {}

