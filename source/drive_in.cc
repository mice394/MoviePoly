#include <string>
#include "drive_in.h"
using namespace std;

DRIVE_IN::DRIVE_IN(){
    setPropPrice(150);
    setPosition(28);
    setName("DRIVE-IN");
    setPropertyType("VIEWING");
}

DRIVE_IN::~DRIVE_IN(){}
