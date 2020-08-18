#ifndef _GOOSE_NESTING_H_
#define _GOOSE_NESTING_H_
#include <string>
#include "non_property.h"

class GooseNesting : public NonProperty{
    public:
    GooseNesting();
    ~GooseNesting();
    void attack();
    void notify(Player * somePlayer) override;

    private:
    
};

#endif
