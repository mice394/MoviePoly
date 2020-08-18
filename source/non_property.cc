#include <string>
#include "non_property.h"
#include "cell.h"
using namespace std;

NonProperty::NonProperty(){
    activeRims = 0;
    cellType = "Non-property";
}

NonProperty::~NonProperty(){}

void NonProperty::notify(Player * somePlayer) {

}
