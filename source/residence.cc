#include <string>
#include "residence.h"
#include "player.h"
#include "property.h"
using namespace std;

Residence::Residence() {
	setPropPrice(200);
	setCanBeImproved(false);
	setIsMortgaged(false);
	setPropertyType("Residence");
}

Residence::~Residence() {}


int Residence::calculateFee(int n) {
	Player * owner = getOwnedBy();
	vector<Property*> propertyList = owner->getProperty();
	int numResidencesOwned = 0;

	for(const auto& p : propertyList){
        if ((p->getPropPrice() == 200) && (p->getCanBeImproved() == false)) {
			++numResidencesOwned;
		}
    }

	switch (numResidencesOwned) {
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
