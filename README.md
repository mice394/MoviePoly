# MoviePoly

## Table of Contents
* [Game Description](#game-description)
  * Overview
  * Enhancements
  * Cells
  * Player Avatars
* [Commands](#commands)
  * Command-Line Interface (Flags)
* [Code Structure](#code-structure)
* [Demo](#demo)
  * Launching Sample Game
  * Flags
  * Trade
  * Improve Property
  * Mortgage/Unmortgage
  * Bankrupt
  * Save Game

### Game Description
#### Overview
MoviePoly is an enhanced version of monopoly with a theme of movies in different genres. The basic rules of monopoly apply, with a few added abilities. For more information about the basic monopoly rules, please refer to: https://en.wikipedia.org/wiki/Monopoly_(game)
#### Enhancements
* Save game: Because a game lasts a long time, there is a save game feature
* Load game: Can load a pre-exsiting game
* Mortgage/Unmortgage properties: Players can mortgage their properties if they need money and unmortgage once they have enough money to do so
#### Cells
|**Monopoly Block**|**Properties**|**Colour**|
|:-------:|:-------:|:-------:|
|STUDIO GHUBILI|TOTORO, PONYO|DARK YELLOW|
|COMEDY|HANGOVER, SUPERBAD, KINGSMEN|LIGHT BLUE|
|CHRISTMAS|ELF, KLAUS, GRINCH|PURPLE|
|HORROR|IT, PURGE, CARRIE|LIGHT GREEN|
|ROMANCE|TITANIC, NOTEBOOK|DARK BLUE|
|KIDS|FROZEN, MULAN, ALADDIN|RED|
|ACTION|AVENGERS, SKYFALL, NONSTOP|YELLOW|
|THRILLER|BURNING, MOTHER, PARASITE|DARK GREEN|

|**Special Sets**|**Normal Monopoly Property**|**Properties**|
|:-------:|:-------:|:-------:|
|CREW MEMBERS|RAILROADS|DIRECTOR, PRODUCER, WRITER, CAMERA|
|VIEWING|UTILITIES|THEATRE, DRIVE-IN|
|--------|PARKING|POPCORN|
|--------|INCOME TAX|FINE|
|--------|PASS GO, COLLECT MONEY|FREE TICKET|
|--------|CHANCE|CHANCE|
|--------|COMMUNITY CHEST|RAFFLE|
|--------|JAIL|TIME OUT ZONE|
|--------|GO TO JAIL| CAUGHT SNEAKING|
#### Player Avatars
|**Icon**|**Character**|
|:-------:|:-------:|
|G|GODZILLA|
|B|BAMBI|
|D|DUMBLEDORE|
|P|PIKACHU|
|S|SHERLOCK|
|M|MARIO|
|N|NARUTO|
|T|THOR|

### Commands
#### Command-Line Interface (Flags)
```
-testing              // allows user 1 to choose dice results (can be any integer)
-load <savedGame>.txt // allows users to load a saved game (.txt)
```

### Code Structure
For UML, please refer to uml.pdf in repository. <br>
Primary Design Patterns Used:
* Observer Design Pattern
* Inheritance
* Polymorphism

### Demo
#### Launching Sample Game D
| ![sample game launch](//url) |
|:-------:|
#### Flags D D
|**Testing**|**From Saved Game**|
|:-------:|:-------:|
| ![Testing](//url) | ![From Saved Game](//url) |
#### Trade D
|**Money for Property**|**Property for Property**|**Property for Money**|
|:-------:|:-------:|:-------:|
| ![M for P](//url) | ![P for P](//url) | ![P for M](//url) |
#### Improve Property D
|**Don't Have Monopoly Set**|**Have Monopoly Set**|
|:-------:|:-------:|
| ![not allowed](//url) | ![allowed](//url) |
#### Mortgage/Unmortgage Property D
| ![mort/unmort](//url) |
|:-------:|
#### Bankrupt D
| ![bankrupt](//url) |
|:-------:|
#### Save Game (show .txt)
| ![save](//url) |
|:-------:|
