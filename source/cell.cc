#include "cell.h"
#include "player.h"
#include <string>
using namespace std;

Cell::Cell(){
    isOwned = false;
}

Cell::~Cell(){
}

Player * Cell::getOwnedBy(){
    return ownedBy;
}

void Cell::setOwnedBy(Player * p){
    ownedBy = p;
}

void Cell::setOwned(bool b){
    isOwned = b;
}
bool Cell::getOwned(){
    return isOwned;
}

void Cell::setIsMortgaged(bool b){
    isMortgaged = b;
}

bool Cell::getIsMortgaged(){
    return isMortgaged;
}

int Cell::getPosition(){
   return position;
}

void Cell::setPosition(int n){
    position = n;
}


void Cell::notify(Player * somePlayer){

}

string Cell::getName() {
    return name;
}

void Cell::setName(string newName) {
    name = newName;
};

void Cell::setCellType(string newCellType) {
    cellType = newCellType;
}

string Cell::getCellType() {
    return cellType;
}

