#include <string>
#include "crew.h"
#include "player.h"
#include "property.h"
using namespace std;

CREW::CREW() {
	setPropPrice(200);
	setCanBeImproved(false);
	setIsMortgaged(false);
	setPropertyType("CREW");
}

CREW::~CREW() {}


int CREW::calculateFee(int n) {
	Player * owner = getOwnedBy();
	vector<Property*> propertyList = owner->getProperty();
	int numCrewOwned = 0;

	for(const auto& p : propertyList){
        if ((p->getPropPrice() == 200) && (p->getCanBeImproved() == false)) {
			++numCrewOwned;
		}
    }

	switch (numCrewOwned) {
		case 1:
			return 25;
		case 2:
			return 50;
		case 3:
			return 100;
		default:
            return 200;
	}
}
