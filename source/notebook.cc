#include "notebook.h"
#include <string>
using namespace std;

NOTEBOOK::NOTEBOOK(){
    setPropPrice(400);
    setIsOwned(false);
    setPosition(39);
    setCanBeImproved(true);
    setImproveCost(200);
    setTicketPrice(50, 200, 600, 1400, 1700, 2000);
    setName("NOTEBOOK");
}

NOTEBOOK::~NOTEBOOK() {}

