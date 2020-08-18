#include "dice.h"
#include <iostream>
#include <ctime>
using namespace std;

Dice::Dice(){}
Dice::~Dice(){}

int Dice::getValue() {
    //referenced from stack overflow: https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run
    // since we were getting the same sequence of numbers, wanted diverse test
    int value = rand() % 6 + 1;
    return value;
}

