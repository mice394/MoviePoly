#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include "property.h"

class MOVIES : public Property{
    public:
    MOVIES();
    ~MOVIES();

    int calculateFee(int n);
    void setTicketPrice(int a, int s, int d, int f, int g, int h);
    std::string getPropertyType();

    private:
    int ticketPrice[6];
};

#endif
