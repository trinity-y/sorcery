#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "player.h"
#include "./cards/card.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;
// for the GameState to send notifications to Controller, for example that the game has been won or that the view needs to be updated (similar to a3q1) - trin
class GameStateNotification
{
public:
  GameStateNotification() {};
  virtual ~GameStateNotification() {};
  // virtual void notifyCard(int playerIndex, int leftBox, int rightBox) = 0;
  // // virtual void notifyMinion(int playerIndex, int attack, int defense) = 0;
  // virtual void notifyBoard(int playerIndex, bool ritualActive) = 0;
  // virtual void notifyBoard(int playerIndex, int numMinions) = 0;
  virtual void notify() = 0;
};

class GameState
{
private:
  int activePlayer;
  int inactivePlayer;
  unique_ptr<Player> arrOfPlayers[2];
  void swapPlayers();
  // GameStateNotification *notification;
  // bool activeGame = false;

public:
  GameState(string player1Name, string player2Name, vector<string> deck1CardNames, vector<string> deck2CardNames, GameStateNotification &controller); // should take in both players names, vectors with deck card names, maybe shuffle decks??? -trin
  // also if you want the deck vectors to have a different format lmk, i was thinking they maybe shouldnt be card objects to make it so that the controller only knows about GameState and not the rest of the model, but idk
  ~GameState();
  GameStateNotification &controller;
  // this is how the controller passes commands
  void notify(string cmd);
  void notify(string cmd, int i);
  void notify(string cmd, int i, int p);
  void notify(string cmd, int i, int p, string t);
  // notify function to let GameState know turn has changed
  // The end command ends the current player’s turn. A player may end their turn
  // at any time.
  void end();
  // The draw command draws a card, similar to the effect if the player just
  // started their turn.
  // Card &draw();
  void draw();

  // discards the ith card in the player’s hand, simply removing it from their
  // hand (the card does not go to the graveyard, trigger leave play effects or
  // anything else)
  void discard(int i);
  //  orders minion i to attack the opposing player, where 1 is the leftmost
  //  minion and 5 is the rightmost minion
  void attack(int i);
  // orders the active player’s minion i to attack the inactive player’s minion
  // j
  void attack(int i, int j);
  // plays the ith card in the active player’s hand with no target
  void play(int i);
  // plays the ith card in the active player’s hand on card t owned by player p.
  // This can be used to play enchantments and spells with targets.
  void play(int i, int p, string t);
  // commands the ith minion to use it's activated ability in the active
  // player’s hand with no target
  void use(int i);
  // commands the ith minion to use it's activated ability in the active
  // player’s hand with a target (another minion i)
  void use(int i, int p, int t);
  // commands the ith minion to use it's activated ability in the active
  // player’s hand with a target (a ritual/some other string identified card)
  void use(int i, int p, string t);
  // is the game won yet
  bool isWon();
  // startup game stuff
  void startPlayerTurn();

  // get active player for model
  Player &getActivePlayer();
  Player &getInactivePlayer();

  // View interface methods
  const Player &currentPlayer() const;
  const Player &player(int index) const;
  int activePlayerIndex() const;
};
#endif

