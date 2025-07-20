#IFNDEF CONTROLLER_H
#DEFINE CONTROLLER_H
#include <memory>
#include <iostream>

class GameState;

class Controller {
  bool testingMode;
  unique_ptr<istream> deck1;
  unique_ptr<istream> deck2;
  unique_ptr<istream> initFile;
  unique_ptr<GameState> gameState;
  istringstream iss;
  void executeCommand();
  void turn();
  
  public:
    Controller(bool testingMode);
    int play();
    bool turn(); // will return true when game is over??
}

#ENDIF