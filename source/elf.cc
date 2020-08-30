#include "elf.h"
#include <string>
using namespace std;

ELF::ELF(){
    setPropPrice(140);
    setIsOwned(false);
    setPosition(11);
    setCanBeImproved(true);
    setImproveCost(100);
    setTicketPrice(10, 50, 150, 450, 625, 750);
    setName("ELF");
}

ELF::~ELF() {}

