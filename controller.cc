#include "controller.h"
#include "GameState.h"
#include "TextDisplay.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

Controller::Controller(bool testingMode, string deck1FileName, string deck2FileName, string initFileName):
  testingMode {testingMode},
  deck1{ new ifstream(deck1FileName.c_str())},
  deck2{ new ifstream(deck2FileName.c_str())},
  initFile{initFileName == "" ? nullptr : new ifstream(initFileName.c_str())}
  {};

void Controller::play() {
  string player1Name;
  string player2Name;
  cin >> player1Name;
  cin >> player2Name;

  // load decks
  vector<string> deck1CardNames;
  vector<string> deck2CardNames;
  string input;
  while (getline(*deck1, input)) {
    deck1CardNames.push_back(input);
  }
  while (getline(*deck2, input)) {
    deck2CardNames.push_back(input);
  }

  gameState = make_unique<GameState>(player1Name, player2Name, deck1CardNames, deck2CardNames);
  view = make_unique<TextDisplay>();
  string cmd;

  while (true) {
    while (getline(*initFile, cmd)) {
      mainLoop(cmd);
    }
    while (getline(cin, cmd)) {
      mainLoop(cmd);
    }
  }
}

void Controller::mainLoop(string cmd) {
  // commands that do not require processing by the game state
  cout << "main loop recieved command " << cmd << endl;
  if (cmd == "help") {
    view->notify(cmd);
  }
  gameState->notify(cmd);
}

