#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <memory>

class GameState; // forward declaration

using namespace std;
using GameStatePtr = shared_ptr<GameState>;

class View
{
protected:
    GameStatePtr model;

public:
    explicit View(GameStatePtr m)
        : model(std::move(m))
    {
    }

    virtual ~View() = default;

    // Must be implemented by derived classes
    virtual void notify(const string &cmd) = 0;
    virtual void displayBoard() = 0;
    virtual void displayHand() = 0;
    virtual void displayCard(int handIndex) = 0;
    virtual void displayHelp() = 0;
    virtual void inspectMinion(int boardIndex, int playerNum) = 0;
};

#endif