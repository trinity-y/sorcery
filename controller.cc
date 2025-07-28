#include "controller.h"
#include "GameState.h"
#include "TextDisplay.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "./zones/deck.h" // TEMP
using namespace std;

Controller::Controller(bool testingMode, string deck1FileName, string deck2FileName, string initFileName):
  testingMode {testingMode},
  deck1{ new ifstream(deck1FileName.c_str())},
  deck2{ new ifstream(deck2FileName.c_str())},
  initFile{initFileName == "" ? nullptr : new ifstream(initFileName.c_str())}
  {
    cout << "controller is constructed" << endl;
  };

void Controller::play() {
  string player1Name;
  string player2Name;
  getline(cin, player1Name);
  getline(cin, player2Name);

  // load decks
  vector<string> deck1CardNames;
  vector<string> deck2CardNames;
  string input;
  cout << "starting to get input from the deck file 1" << endl;
  while (getline(*deck1, input)) {
    deck1CardNames.push_back(input);
  }
  cout << "starting to get input from the deck file 2" << endl;
  while (getline(*deck2, input)) {
    deck2CardNames.push_back(input);
  }

  gameState = make_unique<GameState>(player1Name, player2Name, deck1CardNames, deck2CardNames);
  // BELOW IS TEMPORARY FOR TESTING
  unique_ptr<Deck> deck1 = make_unique<Deck>(deck1CardNames);
  // deck1->printDeck();
  // deck1->shuffle();
  // deck1->printDeck();
  view = make_unique<TextDisplay>();
  string line;

  while (true) {
    cout << "starting to take input from initFile" << endl;
    while (initFile && getline(*initFile, line)) {
      mainLoop(line);
    }
    cout << "starting to take input from command line" << endl;
    while (getline(cin, line)) {
      mainLoop(line);
    }
  }
}

void Controller::mainLoop(string line) { // I think cmd needs to be an istringstream for when we need to pass in discard i or other cmds right?
  // commands that do not require processing by the game state
  stringstream commandStream{line};
  string cmd;
  commandStream >> cmd;
  if (cmd == "help") {
    view->notify(cmd);
  } else if (cmd == "end") {
    gameState->notify(cmd);
  } else if (cmd == "quit") {
    // idk how to terminate
  } else if (cmd == "draw"){
    if (testingMode){
      gameState->notify(cmd);
    }
  } else if (cmd == "discard") {
    int i;
    commandStream >> i;
    if (testingMode) {
      gameState->notify(cmd, i);
    }
  } else if (cmd == "attack") {
    int i, j;
    commandStream >> i;
    if (commandStream >> j) {
      gameState->notify(cmd, i, j);
    } else {
      gameState->notify(cmd, i);
    }
  } else if (cmd == "play") {
    int i, p;
    string t;
    commandStream >> i;
    if (commandStream >> p >> t) {
      gameState->notify(cmd, i, p, t);
    } else {
      gameState->notify(cmd, i);
    }
  } else if (cmd == "use") {
    int i, p; 
    string t;
    commandStream >> i;
    if (commandStream >> p >> t) {
      gameState->notify(cmd, i, p, t);
    } else {
      gameState->notify(cmd, i);
    }
  } else if (cmd == "inspect") {
    int i;
    commandStream >> i;
    view->notify(cmd, i); // just inspecting so i think i just notify view
  } else if (cmd == "hand") {
    view->notify(cmd);
  } else if (cmd == "board") {
    view->notify(cmd);
  }
}

