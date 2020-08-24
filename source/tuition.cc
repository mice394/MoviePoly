#include <string>
#include <iostream>
#include "tuition.h"
#include "board.h"
#include "player.h"
using namespace std;

Tuition::Tuition(){
    setPosition(4);
    setName("TUITION");
}

Tuition::~Tuition() {}

void Tuition::pay(Player * p){
    //if b is true, then pay tuition
    string cmd;
    cout << "You must either pay [$300] or 10% of your total [net] worth for tuition." << endl;
    cout << ">";
    cin >> cmd;

    if (cmd == "$300"){
        int currMoney = p->getCurrMoney();
        if (currMoney < 300) {
            cout << "You are bankrupt!" << endl;
            p->setIsBankrupt(true);
        }
        else {
            p->setCurrMoney(currMoney - 300);
            cout << "You've had $300 deducted from your savings." << endl;
        }
    }
    if (cmd == "net"){
        int currMoney = p->getCurrMoney();
        if (currMoney < (p->getNetWorth() * 0.1)) {
            cout << "You are bankrupt!" << endl;
            p->setIsBankrupt(true);
        }
        else {
            cout << "You've had " << (p->getNetWorth() * 0.1) << " deducted from your savings." << endl;
            int n = p->getCurrMoney() - (p->getNetWorth() * 0.1);
            p->setCurrMoney(n);
        }
    }
    cout << "You currently have " << p->getCurrMoney() << " in your savings." << endl;
}

void Tuition::notify(Player * p) {
    if (p->getCurrPosition() == getPosition()) {
        pay(p);
    }
}

