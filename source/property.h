#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include <string>
#include "cell.h"

class Player;

class Property : public Cell {
    public:
        Property();
        ~Property();
        virtual int calculateFee(int n) = 0;
        bool getIsOwned();
        void setIsOwned(bool b);
        int getPropPrice();
        void setPropPrice(int n);
        bool getIsMonopoly();
        bool getCanBeImproved();
        void setCanBeImproved(bool b);
        int getNumImprove();
        void addNumImprove(int n);

        std::string getPropertyType();
        void setPropertyType(std::string newPropertyType);

        void setImproveCost(int n);
        int getImproveCost();

        void setIsMortgaged(bool b);
        bool getIsMortgaged();

        std::vector<std::string> getSetProperties();
        void setSetProperties(std::vector<std::string> v);

    private:
        int PropertyPrice;
        bool isOwned;
        bool isMonopoly;
        bool canBeImproved;
        int NumImprove; //number of times it has been improved
        bool isMortgaged;
        std::string propertyType;
        int improveCost;

        std::vector<std::string> setProperties;

};

#endif
