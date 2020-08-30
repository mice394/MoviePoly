#include <string>
#include "property.h"
#include "movies.h"
using namespace std;

MOVIES::MOVIES(){
    setCanBeImproved(true);
    setIsMortgaged(false);
    setPropertyType("MOVIES");
}

MOVIES::~MOVIES(){}

int MOVIES::calculateFee(int n){
    int numImprove = getNumImprove();
    return ticketPrice[numImprove];
}

void MOVIES::setTicketPrice(int og, int one, int two, int three, int four, int five){
    ticketPrice[0] = og;
    ticketPrice[1] = one;
    ticketPrice[2] = two;
    ticketPrice[3] = three;
    ticketPrice[4] = four;
    ticketPrice[5] = five;
}

