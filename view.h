#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <memory>

class GameState; // forward declaration

using namespace std;
// using GameStatePtr = const GameState* ;

class View
{
protected:
    const GameState& gameState;

public:
    explicit View(const GameState& gameState)
        : gameState(gameState)
    {
    }

    virtual ~View() = default;

    // Must be implemented by derived classes
    virtual void notify(const string &cmd) = 0;
    virtual void notify(const string &cmd, int i) = 0;
    virtual void displayBoard() = 0;
    virtual void displayHand() = 0;
    virtual void displayCard(int handIndex) = 0;
    virtual void displayHelp() = 0;
    virtual void inspectMinion(int boardIndex, int playerNum) = 0;
};

#endif

