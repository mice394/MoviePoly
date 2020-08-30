#include "carrie.h"
#include <string>
using namespace std;

CARRIE::CARRIE(){
    setPropPrice(200);
    setIsOwned(false);
    setPosition(19);
    setCanBeImproved(true);
    setImproveCost(100);
    setTicketPrice(16, 80, 220, 600, 800, 1000);
    setName("CARRIE");
}

CARRIE::~CARRIE() {}

