#include "GameState.h"
#include <string>
#include <iostream>
using namespace std;

void GameState::notify(string cmd) {
    cout << "game state notified with command " << cmd << endl;
};
