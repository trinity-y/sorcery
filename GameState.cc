#include "GameState.h"
#include "player.h"
#include "./zones/board.h"
#include "./cards/card.h"
#include "./cards/spell.h"
#include "./cards/ritual.h"
#include "./zones/deck.h"
#include "./zones/hand.h"
#include "./zones/graveyard.h"

// remove
#include <iostream>

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
  // the game begins with player 1.
  activePlayer = 0;
  inactivePlayer = 1;
  // Start player 1's turn
  startPlayerTurn();
}

// Destructor
GameState::~GameState()
{
}

// Ends current player's turn
void GameState::end()
{
  arrOfPlayers[activePlayer]->notifyCards(END_OF_TURN, *(arrOfPlayers[activePlayer]), *(arrOfPlayers[inactivePlayer]));
  swapPlayers();
  // Start next players turn
  startPlayerTurn();
}

// Draws a card for the active player
// Card &GameState::draw()
// {
//   arrOfPlayers[activePlayer]->drawCard();
// }
void GameState::draw()
{
  arrOfPlayers[activePlayer]->drawCard();
}

// Discards the ith card from active player's hand
void GameState::discard(int i)
{
  arrOfPlayers[activePlayer]->discardCard(i - 1);
}

// Orders minion i to attack opposing player
void GameState::attack(int i)
{
  int index = i - 1;
  // cerr << "attack 1" << endl;
  if (arrOfPlayers[activePlayer]->getMinionActions(index) >= 1)
  {
    if (i >= 1 && i <= arrOfPlayers[activePlayer]->getNumMinions())
    {
      int minionAttack = arrOfPlayers[activePlayer]->getMinionAttack(index);
      arrOfPlayers[inactivePlayer]->reduceLife(minionAttack);
      arrOfPlayers[activePlayer]->decrementMinionActions(index);
    }
    else
    {
      cout << "You tried to attack with a non-existent minion " << i << endl;
      return;
    }
  }
  else
  {
    // invalid attack if they don't have enough actions
    cout << "You tried to attack, but you don't have enough actions." << endl;
    return;
  }
}

// Orders minion i to attack opposing minion j
void GameState::attack(int i, int j)
{
  int index = i - 1;
  // todo: check other minion
  if (index < 0 || index >= arrOfPlayers[activePlayer]->getNumMinions())
  {
    cout << "You tried to attack with a non-existent minion " << i << endl;
    return;
  }
  // invalid attack if they don't have enough actions
  if (arrOfPlayers[activePlayer]->getMinionActions(index) >= 1)
  {
    arrOfPlayers[activePlayer]->decrementMinionActions(index);
    // i is minion A (active player), j is minion B (inactive player)
    int initialMinionAAttack = arrOfPlayers[activePlayer]->getMinionAttack(index);
    int initialMinionBAttack = arrOfPlayers[inactivePlayer]->getMinionAttack(index);
    // reduces minion B’s defence by minion A’s attack
    // reduces minion A’s defence by minion B’s attack
    arrOfPlayers[activePlayer]->changeMinionDefence(index, -initialMinionBAttack);
    arrOfPlayers[inactivePlayer]->changeMinionDefence(index, -initialMinionAAttack);
  }
}

// ! awkward because in one play method we do it in gamestate and another we do it inside player. also now i need  to pass in players into player and its just weird
// Plays the ith card with no target
void GameState::play(int i)
{
  // Range checking for sanity
  if (i >= 1 && i <= 5)
  {
    // assuming there are no cards that do not need access to one or both players
    arrOfPlayers[activePlayer]->playCard(i - 1, *(arrOfPlayers[activePlayer]), *(arrOfPlayers[inactivePlayer]));
  }
}

// Plays the ith card on card t owned by player p
void GameState::play(int i, int p, string t)
{
  Card &card = arrOfPlayers[activePlayer]->getCardFromHand(i - 1);
  Player &targetPlayer = *(arrOfPlayers[p - 1]);
  if (card.type == "SPELL")
  {
    const Spell &spell = static_cast<Spell &>(card);
    // call correct overloaded function
    if (t == "r")
    {
      spell.notify(targetPlayer, t);
    }
    else
    {
      try
      {
        int targetInt = stoi(t) - 1;
        spell.notify(targetPlayer, targetInt);
      }
      catch (...)
      {
        cout << "That's not a valid target!" << endl;
      }
    }
    arrOfPlayers[activePlayer]->discardCard(i - 1);
  }
  else if (card.type == "ENCHANTMENT")
  {
    Enchantment &enchantment = static_cast<Enchantment &>(card);
    try
    {
      int targetInt = stoi(t) - 1;
      // cout << "adding enchantment to " << targetInt << endl;

      targetPlayer.addEnchantment(enchantment, targetInt);
    }
    catch (...)
    {
      cout << "You tried to enchant a non-minion card!" << endl;
    }
  }
  else
  {
    cout << "That's not how you play that card." << endl;
  }
  // arrOfPlayers[activePlayer]->discardCard(i);
  // you are not able to play minions or rituals directly from the hand.
  arrOfPlayers[activePlayer]->discardCard(i - 1);
}

// todo: notify for start of turn, end of turn, etc

// Uses activated ability of minion i with no target
void GameState::use(int i)
{
  // TODO: when minion enters/exists play

  // for gameEffects with activePlayer + inactivePlayer
  arrOfPlayers[activePlayer]->activateMinionAbility(i - 1, *(arrOfPlayers[activePlayer]), *(arrOfPlayers[inactivePlayer]));
}

// Uses activated ability of minion i with target p, t (a minion on a board)
void GameState::use(int i, int p, int t)
{
  // notify does the checking + decrementing for actions
  // cout << "gamestate use" << endl;
  arrOfPlayers[activePlayer]->activateMinionAbility(i - 1, *(arrOfPlayers[p - 1]), t - 1);
}

// Uses activated ability of minion i with target p, t (a ritual)
void GameState::use(int i, int p, string t)
{
  // for gameEffects with no parameters
  // notify does the checking + decrementing for actions

  arrOfPlayers[activePlayer]->activateMinionAbility(i - 1, *(arrOfPlayers[p - 1]), t);
}

// Checks if the game has been won
bool GameState::isWon()
{
  // The game’s objective is to reduce the opposing player’s life to 0, at which point the game ends.
  if (arrOfPlayers[0]->getLife() <= 0 || arrOfPlayers[1]->getLife() <= 0)
  {
    return true;
  }
  return false;
}
// Controller passes commands
void GameState::notify(string cmd, int i, int p, string t)
{
  if (cmd == "play")
  {
    play(i, p, t);
  }
  else if (cmd == "use")
  {
    use(i, p, p);
  }
}
void GameState::notify(string cmd, int i, int j)
{
  if (cmd == "attack")
  {
    attack(i, j);
  }
}
void GameState::notify(string cmd, int i)
{
  if (cmd == "discard")
  {
    discard(i);
  }
  else if (cmd == "attack")
  {
    attack(i);
  }
  else if (cmd == "play")
  {
    play(i);
  }
  else if (cmd == "use")
  {
    use(i);
  }
  // Game state does not handle inspect, hand or board
}
void GameState::notify(string cmd)
{
  // The player is allowed to take actions until they pass.
  if (cmd == "end")
  {
    end();
  }
  else if (cmd == "draw")
  {
    // assuming testing mode is true
    arrOfPlayers[activePlayer]->drawCard();
  }
}

// get active player for model
Player &GameState::getActivePlayer()
{
  return *arrOfPlayers[activePlayer];
}

Player &GameState::getInactivePlayer()
{
  return *arrOfPlayers[inactivePlayer];
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

void GameState::startPlayerTurn()
{
  // APNAP Order????
  arrOfPlayers[activePlayer]->addMagic(1);
  // The player draws a card if their deck is nonempty.
  arrOfPlayers[activePlayer]->drawCard();
  // At the start of every turn, every minion owned by the player whose turn it is is restored to 1 action.
  arrOfPlayers[activePlayer]->restoreMinions();
  // all triggered abilities titled “at the start of your turn” (or similar) on cards on that player’s board activate.
  // enum Trigger::TriggerState::START_OF_TURN = 0
  arrOfPlayers[activePlayer]->notifyCards(START_OF_TURN, *(arrOfPlayers[activePlayer]), *(arrOfPlayers[inactivePlayer]));
}

// View interface methods
const Player &GameState::currentPlayer() const { return *arrOfPlayers[activePlayer]; }
const Player &GameState::player(int index) const { return *arrOfPlayers[index]; }
int GameState::activePlayerIndex() const { return activePlayer; }
