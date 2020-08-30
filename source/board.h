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

#define RESET   "\033[0m"
#define LOGOBLUE "\033[1;34m"

#define BACKRED     "\033[0;101m"
#define BACKLIGHTGREEN   "\033[0;102m"
#define BACKLIGHTYELLOW  "\033[0;103m"
#define BACKBLUE    "\033[0;104m"
#define BACKPURPLE "\033[45m"
#define BACKCYAN    "\033[0;106m"
#define BACKDARKYELLOW "\033[43m"
#define BACKDARKGREEN "\033[42m"
#define WHITE "\033[47m"

class Cell;
class Property;

class Board: public Subject {
  std::vector<Cell *> cellList;
  int activePasses;
  std::vector<Player *> listPlayers;
  int numPlayers;

  public:
    Board();
    ~Board();
    void deleteMe();
    void trade(Player * currPlayer, Player *requestedPlayer, Cell *offeredCell, Cell *requestedCell);
    void trade(Player * currPlayer, Player *requestedPlayer, int money, Cell * requestedCell);
    void trade(Player * currPlayer, Player *requestedPlayer, Cell *offeredCell, int money);
    int getTotalPasses();
    void addPass();
    void subPass();
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
    void middleHousesFills(char c, std::string s, int n, int m, std::string colour1, std::string colour2); //|  III  | and |________|
    void middlePropNames(int n, int m);                          //|NAME   |     |Name    |
    void middleFills(char c, std::string s, int n, int m);       //|       | and |________|
    void topBottomImprove(std::string propName, std::string colour);
    void normalPrinting(std::string name1, std::string name2, std::string colour1, std::string colour2, int pos1, int pos2, bool b);
    std::string findPlayer(int pos);

};

#endif
