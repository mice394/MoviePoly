#include "parasite.h"
#include <string>
using namespace std;

PARASITE::PARASITE(){
    setPropPrice(320);
    setIsOwned(false);
    setPosition(34);
    setCanBeImproved(true);
    setImproveCost(200);
    setTicketPrice(28, 150, 450, 1000, 1200, 1400);
    setName("PARASITE");
}

PARASITE::~PARASITE() {}

