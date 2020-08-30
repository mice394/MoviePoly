#include <string>
#include "non_property.h"
#include "cell.h"
using namespace std;

NonProperty::NonProperty(){
    timeOutPasses = 0;
    cellType = "NON-PROPERTY";
}

NonProperty::~NonProperty(){}

void NonProperty::notify(Player * somePlayer) {

}
