#include "board.h"
#include "cell.h"
#include "player.h"
#include "property.h"
#include "arts_1.h"
#include "arts_2.h"
#include "dc_tims_line.h"
#include "coop.h"
#include "al.h"
#include "b1.h"
#include "b2.h"
#include "c2.h"
#include "cif.h"
#include "cph.h"
#include "dwe.h"
#include "eit.h"
#include "dc.h"
#include "ech.h"
#include "eng.h"
#include "esc.h"
#include "ev1.h"
#include "ev2.h"
#include "ev3.h"
#include "goose_nesting.h"
#include "goToTims.h"
#include "gym.h"
#include "health.h"
#include "hh.h"
#include "bmh.h"
#include "lhi.h"
#include "math.h"
#include "mc.h"
#include "mkv.h"
#include "ml.h"
#include "needles_hall.h"
#include "osap.h"
#include "opt.h"
#include "pac.h"
#include "phys.h"
#include "rch.h"
#include "rev.h"
#include "sci_1.h"
#include "sci_2.h"
#include "slc.h"
#include "v1.h"
#include "uwp.h"
#include "tuition.h"
#include "pas.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Board::Board() {
    // in order shown in watoply pdf
    Cell * osap = new OSAP(); //0
    Cell * al = new AL(); // 1
    Cell * slc = new SLC{2}; //2
    Cell * ml = new ML{}; //3
    Cell * tuition = new Tuition{}; // 4
    Cell * mkv = new MKV{}; // 5
    Cell * ech = new ECH(); // 6
    Cell * needlesHall1 = new NeedlesHall{7}; // 7
    Cell * pas = new PAS{}; // 8
    Cell * hh = new HH{}; // 9
    Cell * timsLine = new DCTimsLine{}; //10
    Cell * rch = new RCH{}; //11
    Cell * pac = new PAC{}; //12
    Cell * dwe = new DWE{}; //13
    Cell * cph = new CPH{}; //14
    Cell * uwp = new UWP{}; //15
    Cell * lhi = new LHI{}; //16
    Cell * slc2 = new SLC{17}; //17
    Cell * bmh = new BMH{}; //18
    Cell * opt = new OPT{}; //19
    Cell * gooseNesting = new GooseNesting{}; //20
    Cell * ev1 = new EV1{}; //21
    Cell * needlesHall2 = new NeedlesHall{22}; //22
    Cell * ev2 = new EV2{}; //23
    Cell * ev3 = new EV3{}; //24
    Cell * v1 = new V1{}; //25
    Cell * phys = new PHYS(); //26
    Cell * b1 = new B1(); //27
    Cell * cif = new CIF{}; //28
    Cell * b2 = new B2{}; //29
    Cell * goToTims = new GoToTims{}; //30
    Cell * eit = new EIT{}; //31
    Cell * esc = new ESC{}; //32
    Cell * slc3 = new SLC{33}; //33
    Cell * c2 = new C2{}; //34
    Cell * rev = new REV{}; //35
    Cell * needlesHall3 = new NeedlesHall{36}; //36
    Cell * mc = new MC{}; //37
    Cell * coopFee = new Coop{}; //38
    Cell * dc = new DC{}; //39

    cellList.emplace_back(osap);
    cellList.emplace_back(al);
    cellList.emplace_back(slc);
    cellList.emplace_back(ml);
    cellList.emplace_back(tuition);
    cellList.emplace_back(mkv);
    cellList.emplace_back(ech);
    cellList.emplace_back(needlesHall1);
    cellList.emplace_back(pas);
    cellList.emplace_back(hh);
    cellList.emplace_back(timsLine);
    cellList.emplace_back(rch);
    cellList.emplace_back(pac);
    cellList.emplace_back(dwe);
    cellList.emplace_back(cph);
    cellList.emplace_back(uwp);
    cellList.emplace_back(lhi);
    cellList.emplace_back(slc2);
    cellList.emplace_back(bmh);
    cellList.emplace_back(opt);
    cellList.emplace_back(gooseNesting);
    cellList.emplace_back(ev1);
    cellList.emplace_back(needlesHall2);
    cellList.emplace_back(ev2);
    cellList.emplace_back(ev3);
    cellList.emplace_back(v1);
    cellList.emplace_back(phys);
    cellList.emplace_back(b1);
    cellList.emplace_back(cif);
    cellList.emplace_back(b2);
    cellList.emplace_back(goToTims);
    cellList.emplace_back(eit);
    cellList.emplace_back(esc);
    cellList.emplace_back(slc3);
    cellList.emplace_back(c2);
    cellList.emplace_back(rev);
    cellList.emplace_back(needlesHall3);
    cellList.emplace_back(mc);
    cellList.emplace_back(coopFee);
    cellList.emplace_back(dc);

    for (int i = 0; i < 40; i++) {
        attach(cellList[i]);
    }

}

Board::~Board() {
    for (int i = 0; i < 40; i++) {
        detach(cellList[i]);
    }
    // for (int i = 0; i < 40; i++) {
    //     delete cellList[i];
    // }
    // for (int i = 0; i < listPlayers.size(); i++) {
    //     delete listPlayers[i];
    // }
    // listPlayers.clear();
    cellList.clear();
   
}


void Board::deleteMe() {
    for (int i = 0; i < 40; i++) {
        detach(cellList[i]);
    }
    for (int i = 0; i < 40; i++) {
        delete cellList[i];
    }
    // for (int i = 0; i < listPlayers.size(); i++) {
    //     delete listPlayers[i];
    // }
    // listPlayers.clear();
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
    int timscups, money, position, timsLine, duration;

    for (int i = 0; i < playerNum; i++) {
        in >> name >> charName >> timscups >> money >> position;
        
        Player * newPlayer = new Player();
        newPlayer->init(charName, name, position);
        newPlayer->setCurrMoney(money);
        for(int t = 0; t < timscups; ++t){
            newPlayer->addCup();
        }

        if(position == 10) {
			int timsLine;
			in >> timsLine;
			if (timsLine == 1) {
                in >> duration;
                newPlayer->setInTimsLine(true);
                newPlayer->setTimeSpentInTims(duration);
            }
		}
		else {
			newPlayer->setInTimsLine(false);
		}
        listPlayers.emplace_back(newPlayer);
    }
    setNumPlayers(playerNum);

    // cell setup: 
    // MC owner improvements
    // DC owner improvements

    // we don't actually know how many buildings are saved so..

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

// trade Rob DC MC
void Board::trade(Player * currPlayer, Player * requestedPlayer, Cell *offeredCell, Cell *requestedCell) {
    cout << "Hello " << requestedPlayer->getPlayerType() << "!" << endl;
    cout << currPlayer->getPlayerType() << " would like to offer you " + offeredCell->getName() + " for " + requestedCell->getName() << endl;
    cout << "Do you accept? (Y/N)" << endl;
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

//trade Brad 500 DC indicates that the current player is willing to give 
// Brad $500 in exchange for the DC building
void Board::trade(Player * currPlayer, Player * requestedPlayer, int money, Cell *requestedCell) {
    cout << "Hello " << requestedPlayer->getPlayerType() << "!" << endl;
    cout << currPlayer->getPlayerType() << " would like to offer you " + to_string(money) + " for " + requestedCell->getName() << endl;
    cout << "Do you accept? (Y/N)" << endl;
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

// trade Kevin MC 500
void Board::trade(Player * currPlayer, Player * requestedPlayer, Cell *offeredCell, int money) {
    cout << "Hello " << requestedPlayer->getPlayerType() << "!" << endl;
    cout << currPlayer->getPlayerType() << " would like to offer you " + offeredCell->getName() + " for " + to_string(money) << endl;
    cout << "Do you accept? (Y/N)" << endl;
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

int Board::getTotalCups() {
    return activeCups;
}
void Board::addCup() {
    activeCups += 1;
}

void Board::subCup(){
    activeCups -= 1;
}

// Player Board::getWinner() {

// }
// Player Board::getCurrentPlayer() {
//     return currentPlayer;
// }
void Board::next() {

}

// 08/11 + 08/12 changes
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
		// properties with the following features are gyms
        cout << (*i)->getName() << " has: " << endl;
        //cout << "\t Money: " << to_string((*i)->getCurrMoney()) << endl;
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
        out << (*i)->getName() << " " << (*i)->getCups() << " ";
        out << (*i)->getCurrMoney() << " ";
        out << (*i)->getCurrPosition();
        if ((*i)->getCurrPosition() == 10) {
            if ((*i)->getInTimsLine()) {
                out << " 1 " << (*i)->getTimeSpentInTims() << endl;
            } else {
                out << "0" << endl;
            }
        }
        cout << endl;
    }

    for (auto i = cellList.begin(); i != cellList.end(); ++i) {
        if ((*i)->getOwned()) {
            out << (*i)->getName() << " ";
            Player * newPlayer = (*i)->getOwnedBy();
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

void Board::middleHousesFills(char c, string s, int firstProp, int secondProp){
    for (int i = 20; i < 32; i++) { 
        if (i == 20) {
            cout << "|";
            cout.fill(c);
            if (firstProp == 0){ cout << setw(8) << left <<  s; }
            else {
                string improvements;
                for(int i = 0; i < firstProp; ++i){
                    improvements += "I";
                }
                cout << setw(8) << left << improvements;
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
             if (secondProp == 0){ cout << setw(8) << left <<  s; }
            else {
                string improvements;
                for(int i = 0; i < secondProp; ++i){
                    improvements += "I";
                }
                cout << setw(8) << left << improvements;
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
             cout << setw(8) << left <<  cellList[firstProp]->getName();
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

void Board::topBottomImprove(string propName){
    int improve = static_cast<Property*>(findCell(propName))->getNumImprove();
    string improvements;
    for(int i = 0; i < improve; ++i){
        improvements += "I";
    }
    cout << setw(8) << left << improvements;
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
            cout << setw(8) << left << "GOOSE";
        }
        else if (i == 21) {
            topBottomImprove("EV1");
        }
        else if(i == 22) {
            cout << setw(8) << left << "NEEDLES";
        }
        else if (i == 23) {
            topBottomImprove("EV2");
        }
        else if (i == 24) {
            topBottomImprove("EV3");
        }
        else if(i == 25) {
            cout << setw(8) << left << "V1"; 
        }
        else if (i == 26) {
            topBottomImprove("PHYS");
        }
        else if (i == 27) {
            topBottomImprove("B1");
        }
        else if(i == 28) {
            cout << setw(8) << left <<  "CIF";
        }
        else if (i == 29) {
            topBottomImprove("B2");
        }
        else if(i == 30) {
            cout << setw(8) << left << "GO TO";
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
             cout << setw(8) << left << "NESTING";
         }
         else if(i == 22) {
             cout << setw(8) << left << "HALL";
         }
         else if ((i == 25) || (i == 28)) {
             cout << setw(8) << left << " "; 
         }
         else if(i == 30) {
             cout << setw(8) << left << "TIMS";
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
             cout << setw(8) << left << cellList[i]->getName();
         }
     }

    cout << "|" << endl;
    topBottomFills(20, 30, true); //Goose nesting to Tims
    //FIRST ROW IS DONE HERE

    //second row OPT EIT
    int OptImprove = static_cast<Property*>(findCell("OPT"))->getNumImprove();
    int EitImprove = static_cast<Property*>(findCell("EIT"))->getNumImprove();
    middleHousesFills(' ', " ", OptImprove, EitImprove);
    middleHousesFills('-', "-", 0, 0);
    middlePropNames(19, 31);
    middleFills(' ', " ", 19, 31);
    middleFills('_', "_", -1, -1);

    //third row BMH ESC
    int BmhImprove = static_cast<Property*>(findCell("BMH"))->getNumImprove();
    int EscImprove = static_cast<Property*>(findCell("ESC"))->getNumImprove();
    middleHousesFills(' ', " ", BmhImprove, EscImprove);
    middleHousesFills('-', "-", 0, 0);
    middlePropNames(18, 32);
    middleFills(' ', " ", 18, 32);
    middleFills('_', "_", -1, -1);

    //fourth row SLC SLC
    middlePropNames(17, 33);
    middleFills(' ', " ", -1, -1);
    middleFills(' ', " ", 17, 33);
    middleFills(' ', " ", -1, -1);
    middleFills('_', "_", -1, -1);

    //fifth row LHI C2
    int LhiImprove = static_cast<Property*>(findCell("LHI"))->getNumImprove();
    int C2Improve = static_cast<Property*>(findCell("C2"))->getNumImprove();
    middleHousesFills(' ', " ", LhiImprove, C2Improve);
    middleHousesFills('-', "-", 0, 0);
    middlePropNames(16, 34);
    //starting WATOPOLY logo section
    cout << "|"; //property LHI
    cout.fill(' ');
    string LHIPlayer = findPlayer(16);
    if (LHIPlayer.empty()) { LHIPlayer = " "; }
    cout << setw(8) << left <<  LHIPlayer;
    cout << "|";
        
    cout.fill(' '); //Logo
    cout << setw(16) << left <<  " ";
    cout.fill('_');
    cout << setw(48) << left << "_";
    cout.fill(' ');
    cout << setw(16) << left <<  " ";

    cout << "|"; // Property C2
    cout.fill(' ');
    string C2Player = findPlayer(34);
    if (C2Player.empty()) { C2Player = " "; }
    cout << setw(8) << left <<  C2Player;
    cout << "|";
    cout << endl;

    cout << "|"; // Property LHI bottom boarder
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|";

    cout.fill(' '); //Logo
    cout << setw(15) << left <<  " ";
    cout << "|";
    cout << setw(48) << left << " ";
    cout << "|";
    cout.fill(' ');
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property C2 bottom boarder
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|";
    cout << endl;

    //sixth row UWP REV
    cout << "|"; // Property Label UWP
    cout.fill(' ');
    cout << setw(8) << left <<  cellList[15]->getName();
    cout << "|";

    cout.fill(' '); //Logo first row
    cout << setw(15) << left <<  " ";
    cout << "|  #   #  ##  #####  ###  ###   ###  #   #   #   |"; //cushion with 1 space on left, 2 on right
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property Label REV
    cout.fill(' ');
    cout << setw(8) << left <<  cellList[35]->getName();
    cout << "|";
    cout << endl;

    cout << "|"; // Property UWP
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|";

    cout.fill(' '); //Logo 2nd row
    cout << setw(15) << left <<  " ";
    cout << "|  #   # #  #   #   #   # #  # #   # #   #   #   |";
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property REV
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    cout << "|"; // Property UWP
    cout.fill(' ');
    string UWPPlayer = findPlayer(15);
    if (UWPPlayer.empty()) { UWPPlayer = " "; }
    cout << setw(8) << left <<  UWPPlayer;
    cout << "|";

    cout.fill(' '); //Logo 3rd row
    cout << setw(15) << left <<  " ";
    cout << "|  # # # ####   #   #   # ###  #   # #    # #    |";
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property REV
    cout.fill(' ');
    string REVPlayer = findPlayer(35);
    if (REVPlayer.empty()) { REVPlayer = " "; }
    cout << setw(8) << left <<  REVPlayer;
    cout << "|" << endl;

    cout << "|"; // Property UWP
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|";

    cout.fill(' '); //Logo 4th row
    cout << setw(15) << left <<  " ";
    cout << "|  # # # #  #   #   #   # #    #   # #     #     |";
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property REV
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    cout << "|"; // Property UWP
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|";

    cout.fill(' '); //Logo 5th row
    cout << setw(15) << left <<  " ";
    cout << "|  ##### #  #   #    ###  #     ###  ## #  #     |";
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property REV
    cout.fill('_');
    cout << setw(8) << left <<  "_";
    cout << "|" << endl;

    int CphImprove = static_cast<Property*>(findCell("CPH"))->getNumImprove();
    cout << "|"; // Property CPH (house area)
    cout.fill(' ');
    if (CphImprove != 0){
        topBottomImprove("CPH");
    } else {
        cout << setw(8) << left <<  " ";
    }
    cout << "|";

    cout.fill(' '); //Logo
    cout << setw(15) << left <<  " ";
    cout << "|";
    cout.fill('_');
    cout << setw(48) << left << "_";
    cout << "|";
    cout.fill(' ');
    cout << setw(15) << left <<  " ";

    cout << "|"; // Property NEEDLES HALL (needles part)
    cout.fill(' ');
    cout << setw(8) << left <<  "NEEDLES |";
    cout << endl;

    cout << "|"; // Property CPH (house area end)
    cout.fill('-');
    cout << setw(8) << left <<  "-";
    cout << "|";

    cout.fill(' '); //middle
    cout << setw(80) << left <<  " ";

    cout << "|"; // Property NEEDLES HALL (hall part)
    cout.fill(' ');
    cout << setw(8) << left <<  "HALL    |";
    cout << endl;

    cout << "|"; // Property Label CPH
    cout.fill(' ');
    cout << setw(8) << left <<  cellList[14]->getName();
    cout << "|";

    cout.fill(' '); //middle
    cout << setw(80) << left <<  " ";

    cout << "|"; // Property NEEDLES HALL (house area)
    cout.fill(' ');
    cout << setw(8) << left <<  " ";
    cout << "|" << endl;

    middleFills(' ', " ", 14, 36);
    middleFills('_', "_", -1, -1);

    //seventh row DWE MC
    int DweImprove = static_cast<Property*>(findCell("DWE"))->getNumImprove();
    int McImprove = static_cast<Property*>(findCell("MC"))->getNumImprove();
    middleHousesFills(' ', " ", DweImprove, McImprove);
    middleHousesFills('-', "-", 0, 0);
    middlePropNames(13, 37);
    middleFills(' ', " ", 13, 37);
    middleFills('_', "_", -1, -1);

    //eight row PAC COOPFEE
    middlePropNames(12, 38);
    middleFills(' ', " ", -1, -1);
    middleFills(' ', " ", 12, 38);
    middleFills(' ', " ", -1, -1);
    middleFills('_', "_", -1, -1);

    //ninth row RCH DC
    int RchImprove = static_cast<Property*>(findCell("RCH"))->getNumImprove();
    int DcImprove = static_cast<Property*>(findCell("DC"))->getNumImprove();
    middleHousesFills(' ', " ", RchImprove, DcImprove);
    middleHousesFills('-', "-", 0, 0);
    middlePropNames(11, 39);
    middleFills(' ', " ", 11, 39);
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
            cout << setw(8) << left << "DC Tims";
        }
        else if (i == 21) {
            topBottomImprove("HH");
        }
        else if (i == 22) {
            topBottomImprove("PAS");
        }
        else if(i == 23) {
            cout << setw(8) << left << "NEEDLES";
        }
        else if (i == 24) {
            topBottomImprove("ECH");
        }
        else if(i == 25) {
            cout << setw(8) << left << "MKV"; 
        }
        else if(i == 26) {
            cout << setw(8) << left <<  "TUITION";
        }
        else if (i == 27) {
            topBottomImprove("ML");
        }
        else if(i == 28) {
            cout << setw(8) << left << "SLC";
        }
        else if (i == 29) {
            topBottomImprove("AL");
        }
        else if(i == 30) {
            cout << setw(8) << left << "COLLECT";
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
             cout << setw(8) << left << "Line";
         }
         else if(i == 23) {
             cout << setw(8) << left << "HALL";
         }
         else if ((i == 25) ||(i == 26) || (i == 28)) {
             cout << setw(8) << left << " "; 
         }
         else if(i == 30) {
            cout << setw(8) << left << "OSAP";
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



