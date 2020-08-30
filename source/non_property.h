#ifndef _NON_PROPERTY_H_
#define _NON_PROPERTY_H_
#include <string>
#include "cell.h"

class NonProperty: public Cell{
    public:
        NonProperty();
        ~NonProperty();
        int timeOutPasses;
        std::string getCellType();
        void notify(Player * somePlayer) override;

    private:
        std::string cellType;

};

#endif
