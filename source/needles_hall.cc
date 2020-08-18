#include "needles_hall.h"
#include <string>
#include "player.h"
#include <iostream>
using namespace std;

NeedlesHall::NeedlesHall(int n){
    setPosition(n);
    setName("NEEDLESHALL");
}

NeedlesHall::~NeedlesHall(){}

/*
-200 = 1/18
-100 = 1/9
-50 = 1/6
25 = 1/3
50 = 1/6
100 = 1/9
200 = 1/18
*/

void NeedlesHall::amountChange(Player* currPlayer){
    string result;
    int currMoney = currPlayer->getCurrMoney();
    int randomNum = rand() % 18 + 1;
    if (randomNum == 1){
        cout << "You have had $200 deducted from your savings.";
        currPlayer->setCurrMoney(currMoney - 200);
    }
    else if (randomNum == 2){
        cout << "You have had $200 added to your savings.";
        currPlayer->setCurrMoney(currMoney + 200);
    }
    else if ((randomNum == 3) || (randomNum == 4)){
        cout << "You have had $100 deducted from your savings.";
        currPlayer->setCurrMoney(currMoney - 100);
    }
    else if ((randomNum == 5) || (randomNum == 6)){
        cout << "You have had $100 added to your savings.";
        currPlayer->setCurrMoney(currMoney + 100);
    }
    else if ((randomNum >= 7) && (randomNum <= 9)){
        cout << "You have had $50 deducted from your savings.";
        currPlayer->setCurrMoney(currMoney - 50);
    }
    else if ((randomNum >= 10) && (randomNum <= 12)){
        cout << "You have had $50 added to your savings.";
        currPlayer->setCurrMoney(currMoney + 50);
    } 
    else {
        cout << "You have had $25 added to your savings.";
        currPlayer->setCurrMoney(currMoney + 25);
    }
}

void NeedlesHall::notify(Player * p) {
    if (p->getCurrPosition() == getPosition()) {
        amountChange(p);
    }
}

