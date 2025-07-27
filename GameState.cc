#include "GameState.h"
#include "player.h"
#include "./zones/board.h"
#include "./zones/deck.h"
#include "./zones/hand.h"
#include "./zones/graveyard.h"

// Private helper function
void GameState::swapPlayers()
{
  swap(activePlayer, inactivePlayer);
}

// Constructor
GameState::GameState(string player1Name, string player2Name, vector<string> deck1CardNames, vector<string> deck2CardNames)
{
  arrOfPlayers[0] = make_unique<Player>(player1Name, deck1CardNames);
  arrOfPlayers[1] = make_unique<Player>(player2Name, deck2CardNames);
}

// Destructor
GameState::~GameState()
{
}

// Ends current player's turn
void GameState::end()
{
  turnStarted = false;
  swapPlayers();
}

// Draws a card for the active player
Card &GameState::draw()
{
  arrOfPlayers[activePlayer]->drawCard();
}

// Discards the ith card from active player's hand
void GameState::discard(int i)
{
  arrOfPlayers[activePlayer]->discardCard(i);
}

// Orders minion i to attack opposing player
void GameState::attack(int i)
{
  int minionAttack = arrOfPlayers[activePlayer]->getMinionAttack(i);
  arrOfPlayers[inactivePlayer]->reduceLife(minionAttack);
}

// Orders minion i to attack opposing minion j
void GameState::attack(int i, int j)
{
  // i is minion A, j is minion B
  int initialMinionAAttack = arrOfPlayers[activePlayer]->getMinionAttack(i);
  int initialMinionADefence = arrOfPlayers[inactivePlayer]->getMinionDefence(j);
  int initialMinionBAttack = arrOfPlayers[activePlayer]->getMinionAttack(i);
  int initialMinionBDefence = arrOfPlayers[inactivePlayer]->getMinionDefence(j);
  // reduces minion B’s defence by minion A’s attack
  int newMinionBDefence =  initialMinionBDefence - initialMinionAAttack;
  // reduces minion A’s defence by minion B’s attack
  int newMinionADefence =  initialMinionADefence - initialMinionBAttack;
  arrOfPlayers[activePlayer]->setMinionDefence(i, newMinionADefence);
  arrOfPlayers[inactivePlayer]->setMinionDefence(i, newMinionBDefence);
}

// Inspects the current game state
void GameState::inspect()
{
  // implementation here
}

// Plays the ith card with no target
void GameState::play(int i)
{
  // implementation here
}

// Plays the ith card on card t owned by player p
void GameState::play(int i, int p, int t)
{
  // implementation here
}

// Uses activated ability of minion i with no target
void GameState::use(int i)
{
  // implementation here
}

// Uses activated ability of minion i with target p, t
void GameState::use(int i, int p, int t)
{
  // implementation here
}

// Checks if the game has been won
bool GameState::isWon()
{
  // The game’s objective is to reduce the opposing player’s life to 0, at which point the game ends.
  if (arrOfPlayers[0]->getLife() == 0 || arrOfPlayers[1]->getLife() == 0)
  {
    return true;
  }
  return false;
}
// Controller passes commands
void GameState::notify(string cmd)
{
  if (isWon())
  {
    return;
  }
  if (!turnStarted)
  {
    // APNAP Order????
    turnStarted = true;
    arrOfPlayers[activePlayer]->addMagic();
    // The player draws a card if their deck is nonempty.
    arrOfPlayers[activePlayer]->drawCard();
    // At the start of every turn, every minion owned by the player whose turn it is is restored to 1 action.
    arrOfPlayers[activePlayer]->restoreMinions();
    // all triggered abilities titled “at the start of your turn” (or similar) on cards on that player’s board activate.
    // enum Trigger::TriggerState::START_OF_TURN = 0
    arrOfPlayers[activePlayer]->activateCards(0);
  }
  // The player is allowed to take actions until they pass.
  if (cmd == "end")
  {
    end();
  }
  else if (cmd == "quit")
  {
    // The quit command ends the game immediately with no winner.
    activeGame = false;
    // may need to add more here
    return;
  }
  else if (cmd == "draw")
  {
    // assuming testing mode is true
    arrOfPlayers[activePlayer]->drawCard();
  }
  else if (cmd == "discard")
  {
    // assuming testing mode is true
    // temp ignore until istringstream is done
    // discard(i);
  }
}
// 1.2 Basic Gameplay
// The game’s objective is to reduce the opposing player’s life to 0, at which point the game ends. The game begins by first
// asking both players for their names. It then shuffles both player’s decks. Once the decks are shuffled, the game begins with
// player 1. Both players start with 20 life, 5 cards in their hand, and 3 magic.
// For the rest of the game, players alternate turns. A player’s turn consists of the following:
// • The player gains 1 magic.
// • The player draws a card if their deck is nonempty.
// • Any “At the start of the turn” effects occur.
// • The player is allowed to take actions until they pass.
// • Any “At the end of the turn” effects occur
// main game loop logic
void GameState::startGame()
{
  // It then shuffles both player’s decks.
  arrOfPlayers[0]->shuffleDeck();
  arrOfPlayers[1]->shuffleDeck();
  // the game begins with player 1.
  activePlayer = 0;
  inactivePlayer = 1;
  activeGame = true;
}
