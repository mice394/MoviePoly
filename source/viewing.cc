#include <string>
#include "viewing.h"
#include "player.h"
#include "property.h"
#include "dice.h"
#include <iostream>
using namespace std;

VIEWING::VIEWING(){
    setName("VIEWING");
    setCanBeImproved(false);
	setIsMortgaged(false);
    propertyType = "VIEWING";
}

VIEWING::~VIEWING(){}

std::string VIEWING::getPropertyType() {
    return propertyType;
}


int VIEWING::calculateFee(int n){
    Dice dice1;
    Dice dice2;
    int firstValue = dice1.getValue();
    int secondValue = dice2.getValue();

    cout << "The first dice that was rolled gave a: " << to_string(firstValue) << endl;
    cout << "The second dice that was rolled gave a: " << to_string(secondValue) << endl;
    int sum = firstValue + secondValue;
    int numViewingOwned = 0;

    Player * owner = getOwnedBy();
    vector<Property*> propertyList = owner->getProperty();

    for(const auto& p : propertyList){
        if ((p->getPropPrice() == 150) && (p->getCanBeImproved() == false)) {
			++numViewingOwned;
		}
    }

    if (numViewingOwned == 1){
        return sum * 4;
    }
    else {
        return sum * 10;
    }
}
