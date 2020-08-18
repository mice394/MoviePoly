#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <memory>

#include <iostream>
#include <fstream>

#include "subject.h"
#include "board.h"
#include "player.h"

class Cell;
class Property;

class Board: public Subject {
  std::vector<Cell *> cellList;
  int activeCups;
  std::vector<Player *> listPlayers;
  int numPlayers;

  public:
    Board();
    ~Board();
    void deleteMe();
    void trade(Player * currPlayer, Player *requestedPlayer, Cell *offeredCell, Cell *requestedCell);
    void trade(Player * currPlayer, Player *requestedPlayer, int money, Cell * requestedCell);
    void trade(Player * currPlayer, Player *requestedPlayer, Cell *offeredCell, int money);
    int getTotalCups();
    void addCup();
    void subCup();
    std::vector<Player *> getListPlayers();
    Player getWinner();
    Player getCurrentPlayer();
    void next();
    void auction(Property *p);
    void unmortgage(Property * p);
    int mortgage(Property * p);
    void all();
    void save();
    std::vector<Cell*> getCells();
    Cell* findCell(std::string cellName);
    void loadBoard(std::ifstream& in);

    void setNumPlayers(int players);
    int getNumPlayers();
    void addPlayer(Player * newPlayer);
    void save(std::ostream& out);
    void print();

  private:
    void topBottomFills(int n, int m, bool b);
    void middleHousesFills(char c, std::string s, int n, int m); //|  III  | and |________|
    void middlePropNames(int n, int m); //|NAME   |             |Name    |
    void middleFills(char c, std::string s, int n, int m); //|       | and |________|
    void topBottomImprove(std::string propName);
    std::string findPlayer(int pos);

};

#endif
