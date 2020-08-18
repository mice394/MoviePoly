#ifndef _ACADEMIC_H_
#define _ACADEMIC_H_
#include <string>
#include "property.h"

class Academic : public Property{
    public:
    Academic();
    ~Academic();

    int calculateFee(int n);
    void setTuition(int a, int s, int d, int f, int g, int h);
    std::string getPropertyType();

    private:
    int tuition[6];
};

#endif
