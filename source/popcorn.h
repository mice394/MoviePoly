#ifndef _POPCORN_H_
#define _POPCORN_H_
#include <string>
#include "non_property.h"

class POPCORN : public NonProperty{
    public:
    POPCORN();
    ~POPCORN();
    void attack();
    void notify(Player * somePlayer) override;

    private:
    
};

#endif
