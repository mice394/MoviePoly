#include "skyfall.h"
#include <string>
using namespace std;

SKYFALL::SKYFALL() {
    setPropPrice(260);
    setIsOwned(false);
    setPosition(27);
    setCanBeImproved(true);
    setImproveCost(150);
    setTicketPrice(22, 110, 330, 800, 975, 1150);
    setName("SKYFALL");
}

SKYFALL::~SKYFALL() {}

