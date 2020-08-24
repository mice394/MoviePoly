#include "ml.h"
#include <string>
using namespace std;

ML::ML(){
    setPropPrice(60);
    setIsOwned(false);
    setPosition(3);
    setCanBeImproved(true);
    setImproveCost(50);
    setTuition(4, 20, 60, 180, 320, 450);
    setName("ML");
}

ML::~ML(){}

