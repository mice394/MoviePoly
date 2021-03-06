#include <iostream>
#include <sstream>
#include <fstream>

#include <string>
#include <vector>
#include <memory>
#include "board.h"
#include "player.h"
#include "dice.h"
#include "cell.h"
#include "property.h"
#include <algorithm>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    srand((unsigned) time(0));
    string cmd;

    //tracking player
    int curr_player = 0; 
    Board board;
    bool loadedGame = false;
    bool game = true;
    int NUM_PLAYERS;
    vector<Player *> players;

    bool testing = false;
    string fileName;

    // introduction to game
    cout << "╦ ╦┌─┐┬  ┌─┐┌─┐┌┬┐┌─┐  ┌┬┐┌─┐  ╔╦╗┌─┐┬  ┬┬┌─┐╔═╗┌─┐┬ ┬ ┬┬" << endl;
    cout << "║║║├┤ │  │  │ ││││├┤    │ │ │  ║║║│ │└┐┌┘│├┤ ╠═╝│ ││ └┬┘│" << endl;
    cout << "╚╩╝└─┘┴─┘└─┘└─┘┴ ┴└─┘   ┴ └─┘  ╩ ╩└─┘ └┘ ┴└─┘╩  └─┘┴─┘┴ o" << endl;

    // checking for flags like testing and loading
    for(int i = 1; i < argc; ++i){
        cmd = argv[i];
        if (argc == 1){ break; }
        if (cmd == "-testing"){
            testing = true;
        }
        if (cmd == "-load") {
            ifstream file {argv[i+1]};
            board.loadBoard(file);
            cout << "We will load your game!" << endl;
            loadedGame = true;
        }
    }

    // available characters to choos from
    vector<char> charList;
    charList.push_back('G');
    charList.push_back('B');
    charList.push_back('D');
    charList.push_back('P');
    charList.push_back('S');
    charList.push_back('M');
    charList.push_back('N');
    charList.push_back('T');
    // not a loaded game, new game, so get some necessary info first
    if (!loadedGame) {
        // command line interface
        cout << "Please enter the number of players: ";
        string someCommand;
        int numPlayers;
        cin >> someCommand;
        stringstream newInsert(someCommand); 
        newInsert >> numPlayers;

        NUM_PLAYERS = numPlayers;

        for (int i = 0; i < numPlayers; i++){
            bool valid = false;
            char name;
            string character;

            while (!valid) {
                cout << "Please enter your name (char): " << endl;
                cout << "Valid options: " << endl;
                for (char a: charList) {
                    cout << a << " ";
                }
                cout << endl << ">";
                cin >> name;
                // if chosen option is a valid option
                if(std::find(charList.begin(), charList.end(), name) != charList.end()) {
                    if (name == 'G') {
                        character = "Godzilla";
                        valid = true;
                    } else if (name == 'B') {
                        character = "Bambi";
                        valid = true;
                    } else if (name == 'D') {
                        character = "Dumbledore";
                        valid = true;
                    } else if (name == 'P') {
                        character = "Pikachu";
                        valid = true;
                    } else if (name == 'S') {
                        character = "Sherlock";
                        valid = true;
                    } else if (name == 'M') {
                        character = "Mario";
                        valid = true;
                    } else if (name == 'N') {
                        character = "Naruto";
                        valid = true;
                    } else if (name == 'T') {
                        character = "Thor";
                        valid = true;
                    }
                    charList.erase(remove(charList.begin(), charList.end(), name), charList.end());
                } else {
                    cout << "This character is already taken." << endl;
                }
            }
            // initialize all our players
            Player * newPlayer = new Player();
            newPlayer->init(name, character, 0);
            players.emplace_back(newPlayer);
            board.addPlayer(players[i]);
            board.setNumPlayers(numPlayers);
        }
    } else {
        players = board.getListPlayers();
        NUM_PLAYERS = board.getNumPlayers();
    }

    // game commands
    while (game) {
        board.print();
        Cell * currentCell;

        while (!players[curr_player]->getIsPlaying()) {
            if (curr_player == NUM_PLAYERS - 1) {
                curr_player = 0; // go back to first player after last players turn
            } else {
                ++curr_player;
            }
        }

        cout << "\n-------------------------------------------------------" << endl;
        cout << "Player " << players[curr_player]->getPlayerType() << "’s turn." << endl;
        cout << "-------------------------------------------------------\n" << endl;

        //if Player is in TIME OUT ZONE, do they want to pay their way out?
        while (players[curr_player]->getInTimeOut() == true){
            cout << "You are currently in TIME OUT ZONE. Do you want to [pay] $50, use a [pass], or [roll]?" << endl;
            cout << ">";
            cin >> cmd;

            if (cmd == "roll"){ 
                break; 
            }

            int numPassesOwned = players[curr_player]->getPasses();
            if ((cmd == "pass") && (numPassesOwned == 0)){
                cout << "You don't have any passes to use. Please try again." << endl;
            }

            if ((cmd == "pay") || ((cmd == "pass") && numPassesOwned > 0)){
                if (cmd == "pay"){
                    if (players[curr_player]->getCurrMoney() < 50) {
                        cout << "You do not have enough money. You will be forced to pay with a pass." << endl;
                        cmd = "pass";
                    } else {
                        cout << "You have paid $50." << endl;
                        int n = players[curr_player]->getCurrMoney() - 50;
                        players[curr_player]->setCurrMoney(n);
                    }
                }
                if (cmd == "pass"){
                    cout << "You have paid with a pass." << endl;
                    players[curr_player]->subPass();
                    board.subPass();
                }
                players[curr_player]->setInTimeOut(false);
                players[curr_player]->setTimeSpentInTimeOut(0);
            }
        }

        // beginning of turn commands
        bool canGo = true;

        while (canGo){
            int dice1, dice2;
            if (testing == true){
                cout << "Time to roll the dice. Please [roll # #] whenever ready." << endl;
            }
            else {
                cout << "Time to roll the dice. Please [roll] whenever ready." << endl;
            }
            cout << ">";
            string rollcmd;
            cin >> rollcmd;

            if (testing == true){
                string dice1S, dice2S;
                cin >> dice1S >> dice2S;
                dice1 = stoi(dice1S);
                dice2 = stoi(dice2S);
                
            } else {
                dice1 = players[curr_player]->roll();
                dice2 = players[curr_player]->roll();
            }

            int diceVal = dice1 + dice2;

            cout << "You rolled a " << dice1 << " and a " << dice2 << "." << endl;

            //check if player is in TIME OUT ZONE
            if (players[curr_player]->getInTimeOut() == true){
                int n = players[curr_player]->getTimeSpentInTimeOut();
                players[curr_player]->setTimeSpentInTimeOut(n + 1);

                //need to see if the 2 dice are same
                if (dice1 == dice2){
                    cout << "Congratulations! You have left the TIME OUT ZONE." << endl;
                    players[curr_player]->setInTimeOut(false);
                    players[curr_player]->setTimeSpentInTimeOut(0);
                    canGo = false;
                } else {
                    //if player has been in zone for too long
                    if (players[curr_player]->getTimeSpentInTimeOut() == 3){
                        cout << "You have been in TIME OUT ZONE for three turns. You must [pay] $50 or use a [pass]." << endl;
                        while (players[curr_player]->getInTimeOut() == true){
                            cout << ">";
                            cin >> cmd;
                            int numPassesOwned = players[curr_player]->getPasses();
                            if ((cmd == "pass") && (numPassesOwned == 0)){
                                cout << "You don't have any passes to use. Please try again." << endl;
                            }

                            if ((cmd == "pay") || ((cmd == "pass") && numPassesOwned > 0)){
                                if (cmd == "pay"){
                                    if (players[curr_player]->getCurrMoney() < 0) {
                                        cout << "You do not have enough money. You will be forced to pay with a pass." << endl;
                                        cmd = "pass";
                                    } else {
                                        cout << "You have paid $50." << endl;
                                        int n = players[curr_player]->getCurrMoney() - 50;
                                        players[curr_player]->setCurrMoney(n);
                                    }
                                }
                                if (cmd == "pass"){
                                    cout << "You have paid with a pass." << endl;
                                    players[curr_player]->subPass();
                                    board.subPass();
                                }
                                players[curr_player]->setInTimeOut(false);
                                players[curr_player]->setTimeSpentInTimeOut(0);
                            }
                        }
                        canGo = false;
                    }
                    //if they can still be in zone
                    else{
                        cout << "Sorry, you did not roll doubles. You are still in TIME OUT ZONE." << endl;
                        canGo = false;
                    }
                }
            } 
            //not in TIME OUT ZONE
             else {
                cout << "Move a total of " << diceVal << " spaces." << endl;
                if (dice1 == dice2) {
                    players[curr_player]->addNumDoubles();
                    canGo = true;
                }
                else {
                    canGo = false;
                }
            }

            if (players[curr_player]->getInTimeOut() == false){

                //need to set new position
                int currPos = players[curr_player]->getCurrPosition();
                int newPos = currPos + diceVal;
                // going to another rotation of the board
                if (newPos > 39) {
                    newPos -= 40;
                    if (newPos > 0) { //collect free ticket if u pass 0 but new cycle
                        cout << "Congrats! You got money for a free ticket." << endl;
                        int n = players[curr_player]->getCurrMoney() + 200;
                        players[curr_player]->setCurrMoney(n);
                    }
                }

                //Player Movement
                players[curr_player]->setPositions(newPos);
                currentCell = board.getCells()[newPos];

                //check if landed on CAUGHTSNEAKING or rolled doubles 3 times in a row
                if ((newPos == 30) || (players[curr_player]->getNumDoubles() == 3)){
                    cout << "You are going directly to TIME OUT ZONE." << endl;
                    players[curr_player]->setInTimeOut(true);
                    players[curr_player]->setTimeSpentInTimeOut(0);
                    players[curr_player]->setPositions(10);
                    currentCell = board.getCells()[10];
                    canGo = false;
                } 

                cout << "Now you are on square: " << to_string(players[curr_player]->getCurrPosition()) << " " << currentCell->getName() << endl;

                board.notifyObservers(players[curr_player]);

                //check if landed on RAFFLE
                if ((newPos == 2) || (newPos == 33)){
                    int randomCup = rand() % 100;
                    if ((randomCup == 1) && (board.getTotalPasses() < 4)){
                        cout << "You have recieved a Get Out of TIME OUT ZONE pass!" << endl;
                        board.addPass();
                        players[curr_player]->addPass();
                    }
                }
            
                if ((currentCell->getCellType() == "Property") && (players[curr_player]->getNumDoubles() != 3)) {
                    if (!currentCell->getOwned()) {
                        bool answeredProperly = false;
                        while (!answeredProperly) {
                            string answer;
                            cout << "Would you like to buy this property? (Y/N)" << endl;
                            cout << "Property is: " << currentCell->getName() << endl;
                            cout << ">";
                            cin >> answer;
                            if (answer == "Y") {
                                int currMoney = players[curr_player]->getCurrMoney();
                                int cost = static_cast<Property*>(currentCell)->getPropPrice();
                                if (currMoney < cost) {
                                    cout << "Sorry, you do not have enough money." << endl;
                                    board.auction(static_cast<Property*>(currentCell));
                                }
                                else {
                                    cout << "Congratulations! You have bought this property." << endl;
                                    players[curr_player]->addProperty(static_cast<Property*>(currentCell));
                                    currentCell->setOwned(true);
                                    currentCell->setOwnedBy(players[curr_player]);
                                    players[curr_player]->setCurrMoney(currMoney - cost);
                                }
                                answeredProperly = true;
                            } else if (answer == "N") {
                                cout << "This property will be auctioned!" << endl;
                                board.auction(static_cast<Property*>(currentCell));
                                answeredProperly = true;
                            } else {
                                cout << "Please only answer in (Y/N)" << endl;
                            }
                        }
                    } else {
                        if ((currentCell->getOwnedBy()->getName() != players[curr_player]->getName()) && (currentCell->getIsMortgaged() == false)) {
                            Player * owner = currentCell->getOwnedBy();
                            int currMoneyOwner = owner->getCurrMoney();
                            int currMoneyPlayer = players[curr_player]->getCurrMoney();
                            cout << "You are on someone else's property." << endl;
                            int fee = static_cast<Property*>(currentCell)->calculateFee(0);
                            cout << "The fee you owe is: " << to_string(fee) << endl;
                            if((currMoneyPlayer - fee) < 0){
                                cout << "You are bankrupt!" << endl;
                                players[curr_player]->setIsBankrupt(true);
                            }
                            else {
                                cout << "You have paid: " << to_string(fee) << endl;
                                owner->setCurrMoney(currMoneyOwner + fee);
                                players[curr_player]->setCurrMoney(currMoneyPlayer - fee);
                            }
                        }
                    }
                }
            }
        }

        players[curr_player]->restartNumDoubles();

        //BANKRUPTCY CHECK
        if (players[curr_player]->getIsPlaying() && players[curr_player]->getIsBankrupt()) {
            int currMoneyPlayer = players[curr_player]->getCurrMoney();
            cout << "You owe more money than what you currently possess. You have 2 options:" << endl;
            cout << "1) You may declare bankruptcy.\n 2) You have the option to try and raise money by selling improvements and mortgaging." << endl;
            cout << "What would you like to do? (1/2) " << endl;
            int n;
            cin >> n;
            if(n == 1){
                vector<Property*> property_list = players[curr_player]->getProperty();
                cout << "You have declared bankruptcy." << endl;
                players[curr_player]->setIsBankrupt(true); //set player bankrupt as true
                players[curr_player]->setIsPlaying(false); //they aren't in the game anymore

                // give all of the bankrupt player's buildings to the player that they owe money to
                if (currentCell->getCellType() == "Property") {
                    Player * owner = currentCell->getOwnedBy();
                    for(const auto& p : property_list){
                        p->setOwnedBy(owner);
                        players[curr_player]->removeProperty(p);
                        owner->addProperty(static_cast<Property*>(p));
                    }
                } else {
                    for(const auto& p : property_list){
                        p->setIsMortgaged(false);
                        p->setIsOwned(false);
                        players[curr_player]->removeProperty(p);
                        board.auction(p);
                    }
                }
            }
            else if(n == 2){
                cout << "You now have the chance to raise money." << endl;
                bool enough_money = false;
                vector<Property*> property_list = players[curr_player]->getProperty();
                // loop to sell off properties
                cout << "Selling properties..." << endl;
                for(const auto& p : property_list){
                    int building_price = p->getPropPrice(); //this temp variable will store the price of the building the person is trying to sell
                    p->setOwned(false); //set the building as not owned by anybody
                    players[curr_player]->removeProperty(p);
                    currMoneyPlayer += building_price; //add the sold building to funds
                    if(currMoneyPlayer >= 0){ //checks if it's enough money
                        enough_money = true;
                        cout << "Congratulations! You have raised enough money to pay off what you owe." << endl;
                        players[curr_player]->setIsBankrupt(false);
                        players[curr_player]->setIsPlaying(true);
                        break; //exit the loop of selling properties
                    }
                }
                //if at the end of the loop the player still doesn't have enough then he declares bankruptcy
                if(!enough_money){
                    cout << "Not enough money. You have declared bankruptcy." << endl;
                    players[curr_player]->setIsBankrupt(true);
                    players[curr_player]->setIsPlaying(false);
                    // give all assets to other player
                    if (currentCell->getCellType() == "Property") {
                        Player * owner = currentCell->getOwnedBy();
                        for(const auto& p : property_list){
                            p->setOwnedBy(owner);
                            players[curr_player]->removeProperty(p);
                            owner->addProperty(static_cast<Property*>(p));
                        }
                    } else {
                        for(const auto& p : property_list){
                            p->setIsOwned(false);
                            p->setIsMortgaged(false);
                            players[curr_player]->removeProperty(p);
                            board.auction(p);
                        }
                    }
                }
            }
        }
        // end of turn commands
        while (true) {

            // check for a winner
            if (players.size() == 1) {
                cout << "Player " << players[0]->getName() << " wins!" << endl;
                
                cout << "╔═╗┌─┐┌┐┌┌─┐┬─┐┌─┐┌┬┐┬ ┬┬  ┌─┐┌┬┐┬┌─┐┌┐┌┌─┐┬┬┬" << endl;
                cout << "║  │ │││││ ┬├┬┘├─┤ │ │ ││  ├─┤ │ ││ ││││└─┐│││" << endl;
                cout << "╚═╝└─┘┘└┘└─┘┴└─┴ ┴ ┴ └─┘┴─┘┴ ┴ ┴ ┴└─┘┘└┘└─┘ooo" << endl;

                game = false;
                for (int i = 0; i < players.size(); ++i) {
                    delete players[i]; 
                }
                players.clear();
                board.deleteMe();
                break;
            }
            int winnerIndex = -1;
            int count = 0;
            for (int i = 0; i < players.size(); i++) {
                if (players[i]->getIsPlaying()) {
                    ++count;
                    winnerIndex = i;
                }
            }
            if (count == 1) {
                cout << "Player " << players[winnerIndex]->getName() << " wins!" << endl;
                cout << "╔═╗┌─┐┌┐┌┌─┐┬─┐┌─┐┌┬┐┬ ┬┬  ┌─┐┌┬┐┬┌─┐┌┐┌┌─┐┬┬┬" << endl;
                cout << "║  │ │││││ ┬├┬┘├─┤ │ │ ││  ├─┤ │ ││ ││││└─┐│││" << endl;
                cout << "╚═╝└─┘┘└┘└─┘┴└─┴ ┴ ┴ └─┘┴─┘┴ ┴ ┴ ┴└─┘┘└┘└─┘ooo" << endl;
                game = false;
                for (int i = 0; i < players.size(); ++i) {
                    delete players[i]; 
                }
                players.clear();
                board.deleteMe();
                break;
            } else {
                winnerIndex = -1;
                count = 0;
            }

            cout << "\n***************************************************************************";
            cout << "\nEnter a command:" << endl;
            cout << "Please enter in \"help\" to see all options." << endl;
            cout << "***************************************************************************\n" << endl;
            cout << ">";
            cin >> cmd;

            if (cmd == "board") {
            } else if (cmd == "status") {
            } else if (cmd == "improve") {
                string propertyName;
                cin >> propertyName;
                
                Cell * wantedCell = board.findCell(propertyName);
                Property * wantedProperty = static_cast<Property*>(wantedCell);

                // check Monopoly
                bool isMonopoly = true;
                if (wantedProperty->getPropertyType() == "MOVIES"){
                    vector<string> props = wantedProperty->getSetProperties();
                    for (auto i = props.begin(); i != props.end(); ++i){
                        if (board.findCell(*i)->getOwned()){
                            if (board.findCell(*i)->getOwnedBy()->getName() != players[curr_player]->getName()){
                                isMonopoly = false;
                                break;
                            }
                        } else {
                            isMonopoly = false;
                            break;
                        }
                    }
                }

                string action;
                cout << "Please enter <buy> or <sell> depending on if you want to buy or sell your improvement." << endl;
                cout << ">";
                cin >> action;

                if (action == "sell") {
                    cout << "You are choosing to sell this property: " << propertyName << endl;
                    if (wantedProperty->getOwnedBy()->getName() == players[curr_player]->getName()){
                        if (wantedProperty->getNumImprove() <= 0) {
                            cout << "You do not have an improvement you can sell." << endl;
                        } else {
                            int improveCost = wantedProperty->getImproveCost();
                            int n = players[curr_player]->getCurrMoney();
                            players[curr_player]->setCurrMoney(n + (improveCost * 0.5));
                            wantedProperty->addNumImprove(-1);
                            cout << "You have sold an improvement of " << propertyName << endl;
                        }
        
                    } else {
                        cout << "You do not own this property!" << endl;
                    }
                }
                else if ((action == "buy") && (isMonopoly)) {
                    cout << "You are choosing to buy this property: " << propertyName << endl;
                    if (wantedProperty->getPropertyType() == "VIEWING" || wantedProperty->getPropertyType() == "CREW") {
                        cout << "You cannot improve viewing locations or crew members!" << endl;
                    }
                    else if (wantedProperty->getPropertyType() == "MOVIES") {
                        if (wantedProperty->getOwnedBy()->getName() == players[curr_player]->getName()){
                            if (wantedProperty->getCanBeImproved()) {
                                if(wantedProperty->getNumImprove() < 5){
                                    int currMoney = players[curr_player]->getCurrMoney();
                                    int improvementCost = wantedProperty->getImproveCost();
                                    if (currMoney >= improvementCost) {
                                        cout << "You have successfuly bought an improvement for: " << propertyName << endl;
                                        wantedProperty->addNumImprove(1);
                                        if (wantedProperty->getNumImprove() >= 5) {
                                            wantedProperty->setCanBeImproved(false);
                                        }
                                        players[curr_player]->setCurrMoney(currMoney - improvementCost);
                                    } else {
                                        cout << "You do not have enough money for an improvement." << endl;
                                    }
                                } else {
                                    cout << "This property has already been improved its max number of times." << endl;
                                }
                            }
                        } else {
                            cout << "You do not own this property!" << endl;
                        }
                    }
                }
                else if (!isMonopoly){
                    cout << "You don't own all properties in monopoly containing " << wantedProperty->getName() << "." << endl;
                }
                else {
                    cout << "Unavailable command.";
                }
            } else if (cmd == "trade") {
                int other = 0;
                bool int_arg1 = true;
                bool int_arg2 = true;
                char request;
                cin >> request;
                string arg1, arg2;
                cin >> arg1 >> arg2;
                 //check if arg1 is number or not
                for(unsigned int i=0; i < arg1.length(); ++i){
                    if(isdigit(arg1[i]) == false){
                        int_arg1 = false;
                    }
                }
                //check if arg2 is number or not
                for(unsigned int i=0; i < arg2.length(); ++i){
                    if(isdigit(arg2[i]) == false){
                        int_arg2 = false;
                    }
                }
                //find index of requested player
                for(unsigned int i=0; i < players.size(); ++i){
                    if(players[i]->getName() == request){
                        other = i;
                    }
                }
                //if the player wants to trade themselves
                if(players[curr_player]->getName() == request){ 
                    cout << "This trade is not valid, you can't trade yourself." << endl;
                }else{
                    if(int_arg1){ //if first argument is money
                        Cell * wantedCell = board.findCell(arg2);
                        Property * wantedProperty = static_cast<Property*>(wantedCell);
                        if(players[curr_player]->getCurrMoney() < stoi(arg1)){ //if you don't have enough money to make trade
                            cout << "This trade is not valid, you don't have enough money." << endl;
                        }else{
                            if(wantedCell == nullptr){ //cell can't be found
                                cout << "This trade is not valid, cell is not valid." << endl;
                            }else if(!players[other]->isOwner(wantedProperty)){ //other person doesn't own property
                                cout << "This trade is not valid, " << players[other]->getPlayerType() << " does not own this property." << endl;
                            }else{
                                board.trade(players[curr_player], players[other], stoi(arg1), wantedProperty);
                            }
                        }
                    }
                    else if(int_arg2){ //if second argument is money
                        Cell * wantedCell = board.findCell(arg1);
                        Property * wantedProperty = static_cast<Property*>(wantedCell);
                        if(players[other]->getCurrMoney() < stoi(arg2)){ //if other player doesn't have enough money to make trade
                            cout << "This trade is not valid, " << players[other]->getPlayerType() << " does not have enough money." << endl;
                        }
                        else{
                            if(wantedCell == nullptr){ //cell can't be found
                                cout << "This trade is not valid, cell is not valid." << endl;
                            }else if(!players[curr_player]->isOwner(wantedProperty)){ //current person doesn't own property
                                cout << "This trade is not valid, you do not own this property." << endl;
                            }else{
                                board.trade(players[curr_player], players[other], wantedProperty, stoi(arg2));
                            }
                        }
                    }else{ //neither are numbers
                        Cell * arg1Cell = board.findCell(arg1);
                        Cell * arg2Cell = board.findCell(arg2);
                        Property * arg1Prop = static_cast<Property*>(arg1Cell);
                        Property * arg2Prop = static_cast<Property*>(arg2Cell);
                        if(arg1Cell == nullptr || arg2Cell == nullptr){
                            cout << "This trade is not valid, one or more cell(s) are not valid." << endl;
                        }else if(!players[curr_player]->isOwner(arg1Prop) || !players[other]->isOwner(arg2Prop)){
                            cout << "This trade is not valid, one or more player(s) don't own specified property." << endl;
                        }else{
                            board.trade(players[curr_player], players[other], arg1Prop, arg2Prop);
                        }
                    }
                }
            } else if (cmd == "next") {
                if (curr_player == NUM_PLAYERS - 1) {
                    curr_player = 0; // go back to first player after last players turn
                } else {
                    ++curr_player;
                }
                canGo = false;
                break;
            } else if (cmd == "mortgage") {
                cout << "Which property are you trying to mortage? " << endl;
                cout << ">";
                cin >> cmd;

                Cell * foundCell = board.findCell(cmd);
                Property * tempProperty = static_cast<Property*>(foundCell);

                if (players[curr_player]->isOwner(tempProperty)){
                    int mortgage = board.mortgage(tempProperty);
                    int n = players[curr_player]->getCurrMoney();
                    players[curr_player]->setCurrMoney(n + (mortgage * 0.5));
                } else {
                    cout << "You don't own this property." << endl;
                }

            } else if (cmd == "unmortgage") {
                cout << "Which property are you trying to unmortgage? " << endl;
                cout << ">";
                cin >> cmd;
                Cell * foundCell = board.findCell(cmd);
                Property * tempProperty = static_cast<Property*>(foundCell);

                if (players[curr_player]->isOwner(tempProperty)){
                    int n = players[curr_player]->getCurrMoney();
                    int propPrice = tempProperty->getPropPrice();

                    if ((propPrice * 0.6) <= n){
                        board.unmortgage(tempProperty);
                        players[curr_player]->setCurrMoney(n - (propPrice * 0.6));
                    } else {
                        cout << "You don't have enough money to unmortgage" << endl;
                    }
                } else {
                    cout << "You don't own this property." << endl;
                }

            } else if (cmd == "all") {
                board.all();
            } else if (cmd == "assets") {
                string assets = players[curr_player]->assets();
                cout << assets << endl;
            } else if (cmd == "save") {
                cout << "What will be your file name?" << endl;
                cout << ">";
                string s;
                cin >> s;
                ofstream outputFile(s + ".txt");
                board.save(outputFile);
            } else if (cmd == "quit") {
                game = false;
                canGo = false;
                for (int i = 0; i < players.size(); ++i) {
                    delete players[i]; 
                }
                players.clear();
                board.deleteMe();
                break;
            } else if (cmd == "help") {
                string red = "\033[1;31m";
                cout << red << "roll: " << RESET << "to roll a dice" << endl;
                cout << red << "next: " << RESET << "to give control to the next player" << endl;
                cout << red << "assets: " << RESET << "to view your current assets" << endl;

                cout << red << "trade <name> <give> <receive>: " << RESET << "to trade with someone" << endl;
                cout << "     NOTE: <name> is intended recipent, <give> is property/money you are trading," << endl;
                cout << "            and <receive> is property/money you want in return." << endl;

                cout << red << "improve <property>: " << RESET << "to buy or sell an improvement for a property" << endl;
                cout << red << "mortgage <property>: " << RESET << "to mortgage a property:" << endl;
                cout << red <<"unmortgage <property>: " << RESET << "to unmortgage a property" << endl;
                cout << red << "bankrupt: " << RESET << "to declare bankruptcy:" << endl;
                cout << red << "all: " << RESET << "to view assets of every player;" << endl;
                cout << red << "save: " << RESET << "to view your current game:" << endl;
            }
             else {
                cout << "Invalid Command." << endl;
            }
           
        }
    }
return 0;
}
