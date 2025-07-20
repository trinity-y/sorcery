#include "controller.h"
#include "GameState.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

Controller(bool testingMode, string deck1FileName="default.deck", string deck2FileName="default.deck", string initFileName=""):
  testingMode {testingMode},
  deck1{ new ifstream(deck1FileName.c_str())},
  deck2{ new ifstream(deck2FileName.c_str())},
  initFile{initFileName == "" ? nullptr : new ifstream(initFileName.c_str())},
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
  while (getline(deck1, input)) {
    deck1CardNames.push_back(input);
  }
  while (getline(deck2, input)) {
    deck2CardNames.push_back(input);
  }

  gameState = new GameState(player1Name, player2Name, deck1CardNames, deck2CardNames) 

  string cmd;
  istream inputStream = initFile != nullptr ? *initFile : cin; // if we have an initFile, make that the input stream, otherwise default to cin

  while (true) {
    while (getline(inputStream, cmd)) {
      // commands that do not require processing by the controller
      if (cmd == "")
      gameState.notify(cmd);
    }
    inputStream = cin; // convert to cin if file doesn't exist/ EOF
  }
}
// void Controller::turn()
// void Controller::executeCommand(string cmd) {
  
// }
