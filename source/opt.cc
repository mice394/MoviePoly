#include "opt.h"
#include <string>
using namespace std;

OPT::OPT(){
    setPropPrice(200);
    setIsOwned(false);
    setPosition(19);
    setCanBeImproved(true);
    setImproveCost(100);
    setTuition(16, 80, 220, 600, 800, 1000);
    setName("OPT");
}

OPT::~OPT() {}

