#include "board.h"
#include "cell.h"
#include "player.h"
#include "property.h"
#include "stdghibili.h"
#include "comedy.h"
#include "time_out_zone.h"
#include "coop.h"
#include "ponyo.h"
#include "skyfall.h"
#include "nonstop.h"
#include "parasite.h"
#include "drive_in.h"
#include "grinch.h"
#include "klaus.h"
#include "burning.h"
#include "notebook.h"
#include "kingsmen.h"
#include "christmas.h"
#include "mother.h"
#include "frozen.h"
#include "mulan.h"
#include "aladdin.h"
#include "popcorn.h"
#include "caught_sneaking.h"
#include "viewing.h"
#include "horror.h"
#include "hangover.h"
#include "purge.h"
#include "it.h"
#include "romance.h"
#include "titanic.h"
#include "director.h"
#include "totoro.h"
#include "chance.h"
#include "ticket.h"
#include "carrie.h"
#include "theatre.h"
#include "avengers.h"
#include "elf.h"
#include "writer.h"
#include "action.h"
#include "thriller.h"
#include "raffle.h"
#include "producer.h"
#include "camera.h"
#include "fine.h"
#include "superbad.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Board::Board() {
    Cell * ticket = new TICKET(); //0
    Cell * ponyo = new PONYO(); // 1
    Cell * raffle1 = new RAFFLE{2}; //2
    Cell * totoro = new TOTORO{}; //3
    Cell * fine = new FINE{}; // 4
    Cell * director = new DIRECTOR{}; // 5
    Cell * kingsmen = new KINGSMEN(); // 6
    Cell * chance1 = new CHANCE{7}; // 7
    Cell * superbad = new SUPERBAD{}; // 8
    Cell * hangover = new HANGOVER{}; // 9
    Cell * timeoutzone = new TIMEOUTZONE{}; //10
    Cell * elf = new ELF{}; //11
    Cell * theatre = new THEATRE{}; //12
    Cell * klaus = new KLAUS{}; //13
    Cell * grinch = new GRINCH{}; //14
    Cell * camera = new CAMERA{}; //15
    Cell * itmovie = new IT{}; //16
    Cell * raffle2 = new RAFFLE{17}; //17
    Cell * purge = new PURGE{}; //18
    Cell * carrie = new CARRIE{}; //19
    Cell * popcorn = new POPCORN{}; //20
    Cell * frozen = new FROZEN{}; //21
    Cell * chance2 = new CHANCE{22}; //22
    Cell * mulan = new MULAN{}; //23
    Cell * aladdin = new ALADDIN{}; //24
    Cell * producer = new PRODUCER{}; //25
    Cell * avengers = new AVENGERS(); //26
    Cell * skyfall = new SKYFALL(); //27
    Cell * drive_in = new DRIVE_IN{}; //28
    Cell * nonstop = new NONSTOP{}; //29
    Cell * caughtsneaking = new CAUGHTSNEAKING{}; //30
    Cell * burning = new BURNING{}; //31
    Cell * mother = new MOTHER{}; //32
    Cell * raffle3 = new RAFFLE{33}; //33
    Cell * parasite = new PARASITE{}; //34
    Cell * writer = new WRITER{}; //35
    Cell * chance3 = new CHANCE{36}; //36
    Cell * titanic = new TITANIC{}; //37
    Cell * coopFee = new Coop{}; //38
    Cell * notebook = new NOTEBOOK{}; //39

    cellList.emplace_back(ticket);
    cellList.emplace_back(ponyo);
    cellList.emplace_back(raffle1);
    cellList.emplace_back(totoro);
    cellList.emplace_back(fine);
    cellList.emplace_back(director);
    cellList.emplace_back(kingsmen);
    cellList.emplace_back(chance1);
    cellList.emplace_back(superbad);
    cellList.emplace_back(hangover);
    cellList.emplace_back(timeoutzone);
    cellList.emplace_back(elf);
    cellList.emplace_back(theatre);
    cellList.emplace_back(klaus);
    cellList.emplace_back(grinch);
    cellList.emplace_back(camera);
    cellList.emplace_back(itmovie);
    cellList.emplace_back(raffle2);
    cellList.emplace_back(purge);
    cellList.emplace_back(carrie);
    cellList.emplace_back(popcorn);
    cellList.emplace_back(frozen);
    cellList.emplace_back(chance2);
    cellList.emplace_back(mulan);
    cellList.emplace_back(aladdin);
    cellList.emplace_back(producer);
    cellList.emplace_back(avengers);
    cellList.emplace_back(skyfall);
    cellList.emplace_back(drive_in);
    cellList.emplace_back(nonstop);
    cellList.emplace_back(caughtsneaking);
    cellList.emplace_back(burning);
    cellList.emplace_back(mother);
    cellList.emplace_back(raffle3);
    cellList.emplace_back(parasite);
    cellList.emplace_back(writer);
    cellList.emplace_back(chance3);
    cellList.emplace_back(titanic);
    cellList.emplace_back(coopFee);
    cellList.emplace_back(notebook);

    for (int i = 0; i < 40; i++) {
        attach(cellList[i]);
    }

}

Board::~Board() {
    for (int i = 0; i < 40; i++) {
        detach(cellList[i]);
    }
    cellList.clear();
   
}


void Board::deleteMe() {
    for (int i = 0; i < 40; i++) {
        detach(cellList[i]);
    }
    for (int i = 0; i < 40; i++) {
        delete cellList[i];
    }
    cellList.clear();
   
}

std::vector<Player *> Board::getListPlayers() {
    return listPlayers;
}

int Board::getNumPlayers() {
    return numPlayers;
}

void Board::setNumPlayers(int players) {
    numPlayers = players;
}


void Board::loadBoard(ifstream& in) {
    string line;

    int playerNum;
    in >> playerNum;

    string name;
    char charName;
    int timscups, money, position, duration;

    for (int i = 0; i < playerNum; i++) {
        in >> name >> charName >> timscups >> money >> position;
        
        Player * newPlayer = new Player();
        newPlayer->init(charName, name, position);
        newPlayer->setCurrMoney(money);
        for(int t = 0; t < timscups; ++t){
            newPlayer->addPass();
        }

        if(position == 10) {
			int timeOut;
			in >> timeOut;
			if (timeOut == 1) {
                in >> duration;
                newPlayer->setInTimeOut(true);
                newPlayer->setTimeSpentInTimeOut(duration);
            }
		}
		else {
			newPlayer->setInTimeOut(false);
		}
        listPlayers.emplace_back(newPlayer);
    }
    setNumPlayers(playerNum);

    while(getline(in,line)){
        string buildingName;
        string ownerName;
        char ownerNameCharacter;
        int improving;
		in >> buildingName >> ownerName >> improving;

        // Cell currentCell;
        int cellIndex = -1;
        int playerIndex = -1;
        for (int i = 0; i < 40; i++) {
            if (cellList[i]->getName() == buildingName) {
    
                cellIndex = i;
            }
        }
        if (cellIndex != -1) {
            for (int i = 0; i < playerNum; i++) {
                if (ownerName != "BANK") {
                    ownerNameCharacter = ownerName[0];
                    if (listPlayers[i]->getName() == ownerNameCharacter) {
                        listPlayers[i]->addProperty(static_cast<Property*>(cellList[cellIndex]));
                        playerIndex = i;
                    }
                }
            }
            if (playerIndex != -1) {
                cellList[cellIndex]->setOwnedBy(listPlayers[playerIndex]);
                static_cast<Property*>(cellList[cellIndex])->addNumImprove(improving);
                static_cast<Property*>(cellList[cellIndex])->setOwned(true);
            }
            if (improving == -1) {
                cellList[cellIndex]->setIsMortgaged(true);
            }
        }
        cellIndex = -1;
        playerIndex = -1;
    }
}

// trade Rob NOTEBOOK TITANIC
void Board::trade(Player * currPlayer, Player * requestedPlayer, Cell *offeredCell, Cell *requestedCell) {
    cout << "Hello " << requestedPlayer->getPlayerType() << "!" << endl;
    cout << currPlayer->getPlayerType() << " would like to offer you " + offeredCell->getName() + " for " + requestedCell->getName() << endl;
    cout << "Do you accept? (Y/N)" << endl;
    cout << ">";
    char c;
    cin >> c;
    if(c == 'Y'){
        offeredCell->setOwnedBy(requestedPlayer);
        requestedPlayer->addProperty(static_cast<Property*>(offeredCell));
        currPlayer->removeProperty(static_cast<Property*>(offeredCell));
        requestedCell->setOwnedBy(currPlayer);
        currPlayer->addProperty(static_cast<Property*>(requestedCell));
        requestedPlayer->removeProperty(static_cast<Property*>(requestedCell));
        cout << "The trade is successful." << endl;
    }else{
        cout << "The trade has been declined." << endl;
    }
}

//trade Brad 500 NOTEBOOK indicates that the current player is willing to give 
// Brad $500 in exchange for the NOTEBOOK building
void Board::trade(Player * currPlayer, Player * requestedPlayer, int money, Cell *requestedCell) {
    cout << "Hello " << requestedPlayer->getPlayerType() << "!" << endl;
    cout << currPlayer->getPlayerType() << " would like to offer you " + to_string(money) + " for " + requestedCell->getName() << endl;
    cout << "Do you accept? (Y/N)" << endl;
    cout << ">";
    char c;
    cin >> c;
    if (c == 'Y') {
        int currMoney = currPlayer->getCurrMoney();
        int reqMoney = requestedPlayer->getCurrMoney();
        currPlayer->setCurrMoney(currMoney - money);
        requestedPlayer->setCurrMoney(reqMoney + money);
        currPlayer->addProperty(static_cast<Property*>(requestedCell));
        requestedPlayer->removeProperty(static_cast<Property*>(requestedCell));
        requestedCell->setOwnedBy(currPlayer);
        cout << "The trade is successful." << endl;
    }else{
        cout << "The trade has been declined." << endl;
    }
}

// trade Kevin TITANIC 500
void Board::trade(Player * currPlayer, Player * requestedPlayer, Cell *offeredCell, int money) {
    cout << "Hello " << requestedPlayer->getPlayerType() << "!" << endl;
    cout << currPlayer->getPlayerType() << " would like to offer you " + offeredCell->getName() + " for " + to_string(money) << endl;
    cout << "Do you accept? (Y/N)" << endl;
    cout << ">";
    char c;
    cin >> c;
    if (c == 'Y') {
        int currMoney = currPlayer->getCurrMoney();
        int reqMoney = requestedPlayer->getCurrMoney();
        currPlayer->setCurrMoney(currMoney + money);
        requestedPlayer->setCurrMoney(reqMoney - money);
        requestedPlayer->addProperty(static_cast<Property*>(offeredCell));
        currPlayer->removeProperty(static_cast<Property*>(offeredCell));
        offeredCell->setOwnedBy(requestedPlayer);

        cout << "The trade is successful." << endl;
    }else{
        cout << "The trade has been declined." << endl;
    }
}

Cell* Board::findCell(string cellName) {
    for (int i = 0; i < 40; i++) {
        if (cellList[i]->getName() == cellName) {
            return cellList[i];
        }
    }
    return nullptr;
}

int Board::getTotalPasses() {
    return activePasses;
}
void Board::addPass() {
    activePasses += 1;
}

void Board::subPass(){
    activePasses -= 1;
}

void Board::next() {}

void Board::auction(Property * p) {
    cout << "Auction start: " << endl;
    cout << p->getName() << " is being auctioned." << endl;
    int highest_bid = 0; //tracking the highest bid amount
    vector<bool> bidders; //tracks the list of bidders still bidding
    bidders.resize(numPlayers);
    //populate who is bidding
    for(int i=0; i<numPlayers; ++i){
       if(listPlayers[i]->getCurrMoney() < 0){
            bidders[i] = false;
        }else{
            //they are eligible to bid as long as they have 0 or more money
            bidders[i] = true; 
        }
    }
    int numbidders = numPlayers;
    int tempwinner = -1; //storing the index of the leader in the auction, if its -1 at the end, then noone gets the property
    bool won = false;
    while(!won){
        for(int i=0; i<numPlayers; ++i){
            if(bidders[i] == true){
                cout << "It is " << listPlayers[i]->getPlayerType() << "'s turn to bid." << endl;
                cout << "Currently, the highest bid is at: " << highest_bid << endl;
                cout << "Would you like to raise? (Answer Y/N):" << endl;
                char c;
                cin >> c;
                if(c == 'N'){
                    --numbidders; //remove 1 from the number of active bidders
                    bidders[i] = false; //set the player at i as not actively bidding
                    cout << listPlayers.at(i)->getPlayerType() << " has withdrawn from the auction." << endl;
                }else{
                    cout << "How much would you like to bid? (Answer an integer):" << endl;
                    int n;
                    cin >> n; //input the amount the player wants to bid
                    if(n <= highest_bid){ //check if the amount they want to bid isn't enough
                        cout << "That bid is not higher than the current highest bid of " << highest_bid << ", you will be removed from the auction." << endl;
                        --numbidders;
                        bidders[i] = false;
                        cout << listPlayers.at(i)->getPlayerType() << " has withdrawn from the auction." << endl;
                    }else{
                        if(n > listPlayers.at(i)->getCurrMoney()){ //check if the amount that they want to bid is more than what they have
                            cout << "You don't have enough money to make a bid of " << to_string(n) << ", you will be removed from the auction." << endl;
                            --numbidders;
                            bidders[i] = false;
                            cout << listPlayers.at(i)->getPlayerType() << " has withdrawn from the auction." << endl;
                        }else{ //if it reaches here, their bid is higher than all current ones, and the player becomes the leader or "tempwinner"
                            cout << listPlayers.at(i)->getPlayerType() << " now holds the highest bid of: " << n << endl;
                            highest_bid = n;
                            tempwinner = i;
                        }
                    }
                }
            }
        }
        if((numbidders == 1 && tempwinner != -1) || (numbidders == 0 && tempwinner != -1)){ //there is only 1 bidder left aka the winner
                won = true;
                cout << listPlayers.at(tempwinner)->getPlayerType() << " paid " << highest_bid << " to win the auction for " << p->getName() << "." << endl;
                int oldMoney = listPlayers[tempwinner]->getCurrMoney();
                int newMoney = oldMoney - highest_bid;
                listPlayers[tempwinner]->setCurrMoney(newMoney); //subtract bid amount from current ownings
                listPlayers[tempwinner]->addProperty(p); // add property to list of properties owned by player
                p->setOwnedBy(listPlayers[tempwinner]); //set ownership of the won property to the winner
                break;
        }else if((numbidders == 1 && tempwinner == -1) || numbidders == 0){
            cout << "There is no winner of the auction." << endl;
            break;
        }
    }

}

vector<Cell *> Board::getCells() {
    return cellList;
}


void Board::unmortgage(Property * p){
    if (p->getIsMortgaged() == false){
        cout << "This property is not mortgaged." << endl;
        return;
    }
    cout << "You have successfully unmortgaged!" << endl;
    p->setIsMortgaged(false);
}

int Board::mortgage(Property * p){
    if (p->getIsMortgaged() == true){
        cout << "This property has already been mortgaged." << endl;
        return 0;
    }
    if (p->getNumImprove() != 0){
        cout << "You must sell all your improvements before mortgaging." << endl;
        return 0;
    }
    cout << "You have successfully mortgaged!" << endl;
    p->setIsMortgaged(true);
    return p->getPropPrice();
}

void Board::all() {
    for (auto i = listPlayers.begin(); i != listPlayers.end(); ++i) {
		// properties with the following features are viewing
        cout << (*i)->getPlayerType() << " has: " << endl;
        cout << (*i)->assets() << endl;
	}
}

void Board::addPlayer(Player * newPlayer) {
    listPlayers.emplace_back(newPlayer);
}

void Board::save(ostream& out) {
    out << listPlayers.size() << endl;
    for (auto i = listPlayers.begin(); i != listPlayers.end(); ++i) {
        out << (*i)->getPlayerType() << " ";
        out << (*i)->getName() << " " << (*i)->getPasses() << " ";
        out << (*i)->getCurrMoney() << " ";
        out << (*i)->getCurrPosition();
        if ((*i)->getCurrPosition() == 10) {
            if ((*i)->getInTimeOut()) {
                out << " 1 " << (*i)->getTimeSpentInTimeOut() << endl;
            } else {
                out << "0" << endl;
            }
        }
        cout << endl;
    }

    for (auto i = cellList.begin(); i != cellList.end(); ++i) {
        if ((*i)->getOwned()) {
            out << (*i)->getName() << " ";
            out << ((*i)->getOwnedBy())->getName() << " ";
            if ((*i)->getIsMortgaged()) {
                out << "-1" << endl;
            } else {
                out << static_cast<Property*>((*i))->getNumImprove() << endl;
            }
        }
        else {
            out << (*i)->getName() << " ";
            out << "BANK ";
            if ((*i)->getIsMortgaged()) {
                out << "-1" << endl;
            } else {
                out << static_cast<Property*>((*i))->getNumImprove() << endl;
            }
        }
    }
}

string Board::findPlayer(int pos){
    string players;
    for(auto i = listPlayers.begin(); i != listPlayers.end(); ++i){
        int playerPos = (*i)->getCurrPosition();
        if (playerPos == pos){
            players += (*i)->getName();
        }
    }
    if (players.empty()){ return " "; }
    return players;
}

void Board::topBottomFills(int leftSquare, int rightSquare, bool isClockwise){
    int from = 20;
    int to = 31;
    if ((leftSquare != 0) && (rightSquare != 0)) {
        from = leftSquare;
        to = rightSquare + 1;
    }
    //where player goes
    if (isClockwise){
        for(int i = from; i < to; i++){
            cout << "|";
            cout.fill(' ');
            string player = findPlayer(i);
            cout << setw(8) << left <<  player;
        }
    } else { //(10, 0, false);
        for(int i = 10; i >= 0; i--){
            cout << "|";
            cout.fill(' ');
            string player = findPlayer(i);
            cout << setw(8) << left <<  player;
        }
    }
     //property bottom boarder
     cout << "|" << endl;
     for (int i = from; i < to; i++) {
         cout << "|";
         cout.fill('_');
         cout << setw(8) << left <<  "_";
     }
    cout << "|" << endl;
}

void Board::middleHousesFills(char c, string s, int firstProp, int secondProp, string colour1, string colour2){
    for (int i = 20; i < 32; i++) { 
        if (i == 20) {
            cout << "|";
            cout.fill(c);
            if (firstProp == 0){ cout << colour1 << setw(8) << left <<  s << RESET; }
            else {
                string improvements;
                for(int i = 0; i < firstProp; ++i){
                    improvements += "I";
                }
                cout << colour1 << setw(8) << left << improvements << RESET;
            }
         }
         else if ((i == 21) || (i == 32)) {
             cout << "|";
            cout.fill(' ');
            cout << setw(8) << left <<  " ";
         }
         else if (i == 31) {
             cout << "|";
             cout.fill(c);
             if (secondProp == 0){ cout << colour2 << setw(8) << left <<  s << RESET; }
            else {
                string improvements;
                for(int i = 0; i < secondProp; ++i){
                    improvements += "I";
                }
                cout << colour2 << setw(8) << left << improvements << RESET;
            }
         }
         else {
             cout.fill(' ');
             cout << setw(8) << left <<  " ";
         }
    }
    cout << "|" << endl;
}

void Board::middlePropNames(int firstProp, int secondProp){
    for (int i = firstProp; i < (firstProp+12); ++i) {
        if (i == firstProp) { //First Property
             cout << "|";
             cout.fill(' ');
             cout << setw(8) << left << cellList[firstProp]->getName();
         }
         else if (i == firstProp+1) {
             cout << "|";
         }
         else {
             cout.fill(' ');
             cout << setw(8) << left <<  " ";
         }
     }
     cout << "|"; //Second Property
     cout << setw(8) << left <<  cellList[secondProp]->getName();
     cout << "|" << endl;
}

void Board::middleFills(char c, string s, int leftSquare, int rightSquare){
    for (int i = 20; i < 32; i++) { 
        if (i == 20) {
            string leftS = findPlayer(leftSquare);
            cout << "|";
            cout.fill(c);
            if (leftSquare == -1) { leftS = s; }
            cout << setw(8) << left << leftS;
         }
         else if ((i == 21) || (i == 32)) {
             cout << "|";
           cout.fill(' ');
             cout << setw(8) << left <<  " ";
         }
         else if (i == 31) {
            string rightS = findPlayer(rightSquare);
             cout << "|";
             cout.fill(c);
             if (rightSquare == -1) { rightS = s; }
             cout << setw(8) << left << rightS;
         }
         else {
             cout.fill(' ');
             cout << setw(8) << left <<  " ";
         }
    }
    cout << "|" << endl;
}

void Board::topBottomImprove(string propName, string colour){
    int improve = static_cast<Property*>(findCell(propName))->getNumImprove();
    string improvements;
    for(int i = 0; i < improve; ++i){
        improvements += "I";
    }
    cout << colour << setw(8) << left << improvements << RESET;
}

void Board::normalPrinting(string propName1, string propName2, string propColour1, string propColour2, int propPos1, int propPos2, bool needBottom){
    int propImprove1 = static_cast<Property*>(findCell(propName1))->getNumImprove();
    int propImprove2 = static_cast<Property*>(findCell(propName2))->getNumImprove();
    middleHousesFills(' ', " ", propImprove1, propImprove2, propColour1, propColour2);
    middleHousesFills('-', "-", 0, 0, "", "");
    middlePropNames(propPos1, propPos2);
    middleFills(' ', " ", propPos1, propPos2);
    if (needBottom) { middleFills('_', "_", -1, -1); }
}
      
void Board::print() {
    for (int i = 0; i < 100; i++) {
        cout << "_";
    }
    cout << endl;
    for(int i = 20; i < 31; i++){
        cout << "|";
        cout.fill(' ');

        if(i == 20) { 
            cout << setw(8) << left << "POPCORN";
        }
        else if (i == 21) {
            topBottomImprove("FROZEN", BACKRED);
        }
        else if(i == 22) {
            cout << setw(8) << left << "CHANCE";
        }
        else if (i == 23) {
            topBottomImprove("MULAN", BACKRED);
        }
        else if (i == 24) {
            topBottomImprove("ALADDIN", BACKRED);
        }
        else if(i == 25) {
            cout << setw(8) << left << "PRODUCER"; 
        }
        else if (i == 26) {
            topBottomImprove("AVENGERS", BACKLIGHTYELLOW);
        }
        else if (i == 27) {
            topBottomImprove("SKYFALL", BACKLIGHTYELLOW);
        }
        else if(i == 28) {
            cout << setw(8) << left <<  "DRIVE-IN";
        }
        else if (i == 29) {
            topBottomImprove("NONSTOP", BACKLIGHTYELLOW);
        }
        else if(i == 30) {
            cout << setw(8) << left << "CAUGHT";
        }
        else {
            cout << setw(8) << left << "";
        }
    }
     cout << "|" << endl;
     for(int i = 20; i < 31; i++){
         cout << "|";
         cout.fill(' ');

         if(i == 20) { 
             cout << setw(8) << left << "STATION";
         }
         else if ((i == 22) || (i == 25) || (i == 28)) {
             cout << setw(8) << left << " "; 
         }
         else if(i == 30) {
             cout << setw(8) << left << "SNEAKING";
         }
         else {
             for (int i = 0; i < 8; i++) {
                 cout << "-";
             }
         }
     }
     cout << "|" << endl;
     for(int i = 20; i < 31; i++){
         cout << "|";
         cout.fill(' ');
        if ((i == 20) || (i == 22) || (i == 25) || (i == 28) || (i == 30)) { 
             cout << setw(8) << left <<  " ";
         }
         else {
             cout << setw(8) << left <<cellList[i]->getName();
         }
     }

    cout << "|" << endl;
    topBottomFills(20, 30, true); //Popcorn to CAUGHTSNEAKING
    //FIRST ROW IS DONE HERE

    //second row CARRIE BURNING
    normalPrinting("CARRIE", "BURNING", BACKLIGHTGREEN, BACKDARKGREEN, 19, 31, true);

    //third row PURGE MOTHER
    normalPrinting("PURGE", "MOTHER", BACKLIGHTGREEN, BACKDARKGREEN, 18, 32, true);

    //fourth row RAFFLE RAFFLE
    middlePropNames(17, 33);
    middleFills(' ', " ", -1, -1);
    middleFills(' ', " ", 17, 33);
    middleFills(' ', " ", -1, -1);
    middleFills('_', "_", -1, -1);

    //fifth row IT PARASITE
    normalPrinting("IT", "PARASITE", BACKLIGHTGREEN, BACKDARKGREEN, 16, 34, false);

    //starting WATOPOLY logo section
    cout << "|"; // Property IT bottom boarder
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|";

    cout.fill(' '); //Logo
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE <<setw(48) << " __  __            _      _____      _             " << RESET;
    cout.fill(' ');
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property PARASITE bottom boarder
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|";
    cout << endl;

    //sixth row CAMERA WRITER
    cout << "|"; // Property Label CAMERA
    cout.fill(' ');
    cout << setw(8) << left <<  cellList[15]->getName();
    cout << "|";

    cout.fill(' '); //Logo first row
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "|  \\/  |          (_)    |  __ \\    | |            " << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property Label WRITER
    cout.fill(' ');
    cout << setw(8) << left <<  cellList[35]->getName();
    cout << "|";
    cout << endl;

    cout << "|"; // Property CAMERA
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|";

    cout.fill(' '); //Logo 2nd row
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "| \\  / | _____   ___  ___| |__) |__ | | ___  _   _ " << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property WRITER
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    cout << "|"; // Property CAMERA
    cout.fill(' ');
    string CAMERAPlayer = findPlayer(15);
    if (CAMERAPlayer.empty()) { CAMERAPlayer = " "; }
    cout << setw(8) << left <<  CAMERAPlayer;
    cout << "|";

    cout.fill(' '); //Logo 3rd row
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "| |\\/| |/ _ \\ \\ / / |/ _ \\  ___/ _ \\| |/ _ \\| | | |" << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property WRITER
    cout.fill(' ');
    string WRITERPlayer = findPlayer(35);
    if (WRITERPlayer.empty()) { WRITERPlayer = " "; }
    cout << setw(8) << left <<  WRITERPlayer;
    cout << "|" << endl;

    cout << "|"; // Property CAMERA
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|";

    cout.fill(' '); //Logo 4th row
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "| |  | | (_) \\ V /| |  __/ |  | (_) | | (_) | |_| |" << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property WRITER
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    cout << "|"; // Property CAMERA
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|";

    cout.fill(' '); //Logo 5th row
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "|_|  |_|\\___/ \\_/ |_|\\___|_|   \\___/|_|\\___/ \\__, |" << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property WRITER
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|" << endl;

    int GrinchImprove = static_cast<Property*>(findCell("GRINCH"))->getNumImprove();
    cout << "|"; // Property GRINCH (house area)
    cout.fill(' ');
    if (GrinchImprove != 0){
        topBottomImprove("GRINCH", BACKPURPLE);
    } else {
        cout << BACKPURPLE << setw(8) << left <<  " " << RESET;
    }
    cout << "|";

    cout.fill(' '); //Logo
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "                                              __/ |" << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property CHANCE (chance part)
    cout.fill(' ');
    cout << setw(8) << left <<  "CHANCE  |";
    cout << endl;

    cout << "|"; // Property GRINCH (house area end)
    cout.fill('-');
    cout << setw(8) << left <<  "-";
    cout << "|";

    cout.fill(' '); //Logo
    cout << setw(14) << left <<  " ";
    cout << LOGOBLUE << setw(48) << "                                             |___/ " << RESET;
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property CHANCE (house area)
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    cout << "|"; // Property Label GRINCH
    cout.fill(' ');
    cout << setw(8) << left <<  cellList[14]->getName();
    cout << "|";

    cout.fill(' '); //logo
    cout << setw(80) << left <<  " ";

    cout << "|"; // Property CHANCE (house area)
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    middleFills(' ', " ", 14, 36);
    middleFills('_', "_", -1, -1);

    //seventh row KLAUS TITANIC
    normalPrinting("KLAUS", "TITANIC", BACKPURPLE, BACKBLUE, 13, 37, true);

    //eight row THEATRE COOPFEE
    middlePropNames(12, 38);
    middleFills(' ', " ", -1, -1);
    middleFills(' ', " ", 12, 38);
    middleFills(' ', " ", -1, -1);
    middleFills('_', "_", -1, -1);

    //ninth row ELF NOTEBOOK
    normalPrinting("ELF", "NOTEBOOK", BACKPURPLE, BACKBLUE, 11, 39, false);
    for (int i = 20; i < 32; i++) { 
        bool divider = ((i == 20) || (i == 21) || (i == 31) || (i == 32));
        if (divider) { cout << "|"; }
        cout.fill('_');
        cout << setw(8) << left <<  "_";
    }
    cout << "|" << endl;

    //tenth/last row
    for(int i = 20; i < 31; i++){
        cout << "|";
        cout.fill(' ');

        if(i == 20) { 
            cout << setw(8) << left << "TIME OUT";
        }
        else if (i == 21) {
            topBottomImprove("HANGOVER", BACKCYAN);
        }
        else if (i == 22) {
            topBottomImprove("SUPERBAD", BACKCYAN);
        }
        else if(i == 23) {
            cout << setw(8) << left << "CHANCE";
        }
        else if (i == 24) {
            topBottomImprove("KINGSMEN", BACKCYAN);
        }
        else if(i == 25) {
            cout << setw(8) << left << "DIRECTOR"; 
        }
        else if(i == 26) {
            cout << setw(8) << left <<  "FINE";
        }
        else if (i == 27) {
            topBottomImprove("TOTORO", BACKDARKYELLOW);
        }
        else if(i == 28) {
            cout << setw(8) << left << "RAFFLE";
        }
        else if (i == 29) {
            topBottomImprove("PONYO", BACKDARKYELLOW);
        }
        else if(i == 30) {
            cout << setw(8) << left << "GET FREE";
        }
        else {
            cout << setw(8) << left << "";
        }
    }
    cout << "|" << endl;
     for(int i = 20; i < 31; i++){
         cout << "|";
         cout.fill(' ');

         if(i == 20) { 
             cout << setw(8) << left << "ZONE";
         }
         else if ((i == 23) || (i == 25) ||(i == 26) || (i == 28)) {
             cout << setw(8) << left << " "; 
         }
         else if(i == 30) {
            cout << setw(8) << left << "TICKET";
        }
         else {
             for (int i = 0; i < 8; i++) {
                 cout << "-";
             }
         }
     }
    cout << "|" << endl;
    for(int i = 10; i >= 0; --i){
         cout << "|";
         cout.fill(' ');
        if((i == 10) || (i == 7) || (i == 5) || (i == 4) || (i == 2) || (i == 0)) { 
             cout << setw(8) << left <<  " ";
         }
         else {
             cout << setw(8) << left << cellList[i]->getName();
         }
     }
     cout << "|" << endl;
     topBottomFills(10, 0, false);
}



