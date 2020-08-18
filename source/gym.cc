#include <string>
#include "gym.h"
#include "player.h"
#include "property.h"
#include "dice.h"
#include <iostream>
using namespace std;

Gym::Gym(){
    setName("GYM");
    setCanBeImproved(false);
	setIsMortgaged(false);
    propertyType = "Gym";
}

Gym::~Gym(){}

std::string Gym::getPropertyType() {
    return propertyType;
}


int Gym::calculateFee(int n){
    Dice dice1;
    Dice dice2;
    int firstValue = dice1.getValue();
    int secondValue = dice2.getValue();

    cout << "The first dice that was rolled gave a: " << to_string(firstValue) << endl;
    cout << "The second dice that was rolled gave a: " << to_string(secondValue) << endl;
    int sum = firstValue + secondValue;
    int numGymsOwned = 0;

    Player * owner = getOwnedBy();
    vector<Property*> propertyList = owner->getProperty();

    for(const auto& p : propertyList){
        if ((p->getPropPrice() == 150) && (p->getCanBeImproved() == false)) {
			++numGymsOwned;
		}
    }

    if (numGymsOwned == 1){
        return sum * 4;
    }
    else {
        return sum * 10;
    }
}
