#include <string>
#include "property.h"
#include "academic.h"
using namespace std;

Academic::Academic(){
    setCanBeImproved(true);
    setIsMortgaged(false);
    setPropertyType("Academic");
}

Academic::~Academic(){}

int Academic::calculateFee(int n){
    int numImprove = getNumImprove();
    return tuition[numImprove];
}

void Academic::setTuition(int og, int one, int two, int three, int four, int five){
    tuition[0] = og;
    tuition[1] = one;
    tuition[2] = two;
    tuition[3] = three;
    tuition[4] = four;
    tuition[5] = five;
}

