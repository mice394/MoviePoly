#include "player.h"
#include "property.h"
#include "dice.h"

#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

Player::Player() {
}

Player::~Player() {
}


void Player::init(char nameChar, std::string newPlayerType, int newCurrPosition) {
    name = nameChar;
    playerType = newPlayerType;
    currPosition = newCurrPosition;
    timeSpentInTims = 0;
    lastRollSum = 0;

    money = 1500;
    isBankrupt = false;
    isPlaying = true;
    numCups = 0;
    numDoubles = 0;
    bool inTimsLine = false;
}

bool Player::getIsBankrupt(){
    return isBankrupt;
}

void Player::setIsBankrupt(bool b){
    isBankrupt = b;
}

string Player::assets() {
    string outputAsset;
    outputAsset += "\tCash: ";
    outputAsset += to_string(getCurrMoney());
    outputAsset += "\n\tProperties Owned: ";
    bool hasProp = false;

    for(auto i = properties.begin(); i != properties.end(); ++i){
        outputAsset += (*i)->getName();
        outputAsset += ", ";
        hasProp = true;
    }
    if (hasProp){
        outputAsset.pop_back();
        outputAsset.pop_back();
    }
    return outputAsset;
}

int Player::roll() {
    Dice dice;
    int value = dice.getValue();
    return value;
}

int Player::getCups() {
    return numCups;
}

void Player::addCup() {
    numCups += 1;
}

void Player::subCup() {
    numCups -= 1;
}

char Player::getName() {
    return name;
}

string Player::getPlayerType() {
    return playerType;
}

int Player::getCurrPosition() {
    return currPosition;
}

void Player::setPositions(int newPosition) {
    currPosition = newPosition;
}


void Player::setPrevPositions(int newPosition) {
    prevPosition = newPosition;
}
    
int Player::getPrevPosition() {
    return prevPosition;
}

int Player::getCurrMoney() {
    return money;
}

void Player::setCurrMoney(int newMoney) {
    money = newMoney;
}

int Player::getNumDoubles() {
    return numDoubles;
}

void Player::addNumDoubles() {
    numDoubles += 1;
}

void Player::restartNumDoubles(){
    numDoubles = 0;
}

bool Player::getInTimsLine(){
    return inTimsLine;
}

void Player::setInTimsLine(bool timsLine){
    inTimsLine = timsLine;
}

int Player::getNetWorth(){
    int netWorth = money;
    //add up all properties and their improvements
    int propertyWorth = 0;
    int improvementWorth = 0;
    for(auto i = properties.begin(); i != properties.end(); ++i){
        propertyWorth += (*i)->getPropPrice();
        if ((*i)->getCanBeImproved() == true){
            int improvementCost = (*i)->getNumImprove() * (*i)->getImproveCost();
            improvementWorth += improvementCost;
        }
    }
    netWorth += (propertyWorth + improvementWorth);
    return netWorth;
}

void Player::setIsPlaying(bool b){
    isPlaying = b;
}

bool Player::getIsPlaying(){
    return isPlaying;
}


int Player::getTimeSpentInTims(){
    return timeSpentInTims;
}

void Player::setTimeSpentInTims(int n){
    timeSpentInTims = n;
}

int Player::getLastRollSum(){
    return lastRollSum;
}

void Player::setLastRollSum(int n){
    lastRollSum = n;
}

vector<Property *> Player::getProperty() {
    return properties;
}

void Player::addProperty(Property * newProperty) {
    properties.emplace_back(newProperty);
}

void Player::removeProperty(Property * oldProperty) {
    vector <Property *> temp = getProperty();
    properties.clear();

    for(auto i = temp.begin(); i != temp.end(); ++i){
        if ((*i)->getName() != oldProperty->getName()) {
            addProperty((*i));
        }
    }
}


bool Player::isOwner(Property * p){

    for(auto i = properties.begin(); i != properties.end(); ++i){
        if ((*i)->getName() == p->getName()) {
            return true;
        }
    }
    return false;
}
