#include "avengers.h"
#include <string>
using namespace std;

AVENGERS::AVENGERS(){
    setPropPrice(260);
    setIsOwned(false);
    setPosition(26);
    setCanBeImproved(true);
    setImproveCost(150);
    setTicketPrice(22, 110, 330, 800, 975, 1150);
    setName("AVENGERS");
}

AVENGERS::~AVENGERS() {}

