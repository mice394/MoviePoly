#include <string>
#include "cell.h"
#include "player.h"
#include "property.h"
using namespace std;

Property::Property(){
    PropertyPrice = 0;
    isOwned = false;
    isMonopoly = false;
    canBeImproved = false;
    NumImprove = 0;
    isMortgaged = false;
    improveCost = 0;
    setCellType("Property");
}

Property::~Property(){}

int Property::calculateFee(int n){}

bool Property::getIsOwned(){
    return isOwned;
}

void Property::setIsOwned(bool b){
    isOwned = b;
}

void Property::setIsMortgaged(bool b) {
    isMortgaged = b;
}

bool Property::getIsMortgaged() {
    return isMortgaged;
}

int Property::getPropPrice(){
    return PropertyPrice;
}

void Property::setPropPrice(int n){
    PropertyPrice = n;
}

bool Property::getIsMonopoly(){
    return isMonopoly;
}

bool Property::getCanBeImproved(){
    return canBeImproved;
}

void Property::setCanBeImproved(bool b){
    canBeImproved = b;
}

int Property::getNumImprove(){
    if (isMortgaged) {
        return -1;
    }
    return NumImprove;
}

void Property::addNumImprove(int n){ //error if NumImprove > 5
    NumImprove += n;
}

int Property::getImproveCost(){
    return improveCost;
}

void Property::setImproveCost(int n){
    improveCost = n;
}

std::string Property::getPropertyType() {
    return propertyType;
}

void Property::setPropertyType(std::string newPropertyType) {
    propertyType = newPropertyType;
}

vector<std::string> Property::getSetProperties(){
    return setProperties;
}

void Property::setSetProperties(vector<std::string> v){
    setProperties = v;
}

