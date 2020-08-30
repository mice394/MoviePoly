#include "mother.h"
#include <string>
using namespace std;

MOTHER::MOTHER(){
    setPropPrice(300);
    setIsOwned(false);
    setPosition(32);
    setCanBeImproved(true);
    setImproveCost(200);
    setTicketPrice(26, 130, 390, 900, 1100, 1275);
    setName("MOTHER");
}

MOTHER::~MOTHER() {}

