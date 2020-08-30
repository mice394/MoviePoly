#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <map>
#include <memory>

class Dice;
class Property;

class Player {
  public:
    Player();
    ~Player();
    void init(char nameChar, std::string newPlayerType, int newCurrPosition);
    std::string assets();
    int roll();
    void addPass();
    void subPass();

    char getName();
    int getPasses();
    std::string getPlayerType();
    bool getIsBankrupt();
    void setIsBankrupt(bool b);
    int getCurrPosition();
    void setPositions(int n);
    int getPrevPosition();
    void setPrevPositions(int n);
    int getCurrMoney();
    void setCurrMoney(int newMoney);

    int getNumDoubles();
    int getNetWorth();
    void setIsPlaying(bool b);
    bool getIsPlaying();
    void addNumDoubles();
    void restartNumDoubles();

    //DC Tims line data
    int getTimeSpentInTimeOut();
    void setTimeSpentInTimeOut(int n);
    bool getInTimeOut();
    void setInTimeOut(bool b);
    int getLastRollSum();
    void setLastRollSum(int n);


    std::vector<Property*> getProperty();
    void addProperty(Property * newProperty);
    void removeProperty(Property * oldProperty);
    bool isOwner(Property * p);

  private:
    int numPasses;
    int timeSpentInTimeOut;
    bool inTimeOut;
    int lastRollSum;

    char name;
    std::string playerType;
    int currPosition;
    int prevPosition;
    int money;
    bool isBankrupt;
    bool isPlaying;
    int numDoubles;
    std::vector<Property*> properties;

};

#endif
