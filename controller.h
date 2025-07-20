#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include <iostream>
#include <sstream>
class GameState;
class View;
class Controller {
  bool testingMode;
  unique_ptr<istream> deck1;
  unique_ptr<istream> deck2;
  unique_ptr<istream> initFile;
  unique_ptr<GameState> gameState;
  unique_ptr<View> view;
  istringstream iss;
  void executeCommand();
  void turn();
  void mainLoop(string cmd);
  public:
    Controller(bool testingMode, string deck1FileName="default.deck", string deck2FileName="default.deck", string initFileName="");
    void play();
};

#endif