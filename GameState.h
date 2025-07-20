#include "player.h"
#include "card.h"

// for the GameState to send notifications to Controller, for example that the game has been won or that the view needs to be updated (similar to a3q1) - trin
class GameStateNotification {
  public:
    virtual void notify() = 0; // idk the signature or anything yet
}

class GameState {
private:
  int activePlayer;
  Player *arrOfPlayers[2];
  swapPlayers();

public:
  GameState(); // should take in both players names, vectors with deck card names, maybe shuffle decks??? -trin
  // also if you want the deck vectors to have a different format lmk, i was thinking they maybe shouldnt be card objects to make it so that the controller only knows about GameState and not the rest of the model, but idk
  // i made a CardFactory class that will create the card objects from strings, rn in the UML i put it as in GameState but idk
  ~GameState();
  void notify(string cmd); // this is how the controller passes commands - trin
  // notify function to let GameState know turn has changed
  // The end command ends the current player’s turn. A player may end their turn
  // at any time.
  void end();
  // The draw command draws a card, similar to the effect if the player just
  // started their turn.
  Card &draw();
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
  //
  void inspect();
  // plays the ith card in the active player’s hand with no target
  void play(int i);
  // plays the ith card in the active player’s hand on card t owned by player p.
  // This can be used to play enchantments and spells with targets.
  void play(int i, int p, int t);
  // commands the ith minion to use it's activated ability in the active
  // player’s hand with no target
  void use(int i);
  // commands the ith minion to use it's activated ability in the active
  // player’s hand with a target
  void use(int i, int p, int t);
  // is the game won yet
  bool isWon();
}