#ifndef CELL_H
#define CELL_H

#include "observer.h"
#include "player.h"
#include <string>

class Player;

class Cell: public Observer {
  public:
    Cell();
    virtual ~Cell() = 0;
    Player * getOwnedBy();
    void setOwnedBy(Player * p);
    int getPosition();
    void setPosition(int n);
    void notify(Player * p);
    void setOwned(bool b);
    bool getOwned();
    void setIsMortgaged(bool b);

    bool getIsMortgaged();
    std::string getName();
    void setName(std::string newName);
    std::string getCellType();
    void setCellType(std::string newCellType);

  private:
    int position;
    std::string name;
    bool isOwned;
    bool isMortgaged;
    std::string cellType;
    Player * ownedBy;
};

#endif
