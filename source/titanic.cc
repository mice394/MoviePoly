#include "titanic.h"
#include <string>
using namespace std;

TITANIC::TITANIC(){
    setPropPrice(350);
    setIsOwned(false);
    setPosition(37);
    setCanBeImproved(true);
    setImproveCost(200);
    setTicketPrice(35, 175, 500, 1100, 1300, 1500);
    setName("TITANIC");
}

TITANIC::~TITANIC() {}

