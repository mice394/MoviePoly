#include "hangover.h"
#include <string>
using namespace std;

HANGOVER::HANGOVER(){
    setPropPrice(120);
    setIsOwned(false);
    setPosition(9);
    setCanBeImproved(true);
    setImproveCost(50);
    setTicketPrice(8, 40, 100, 300, 450, 600);
    setName("HANGOVER");
}

HANGOVER::~HANGOVER() {}

