#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "view.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

class TextDisplay : public View
{
private:
    void printCard(const card_template_t &tpl);
    void printRow(const std::vector<card_template_t> &row);
    // border printing methods
    void printBoardTopBorder();
    void printBoardBottomBorder();
    void printBoardRowWithBorder(const std::vector<card_template_t> &row);

public:
    explicit TextDisplay(const GameState &m);
    ~TextDisplay() override = default;

    void notify(const std::string &cmd, int i) override;
    void notify(const string &cmd) override;
    void displayBoard() override;
    void displayHand() override;
    void displayCard(int handIndex) override;
    void displayHelp() override;
    void inspectMinion(int boardIndex, int playerNum) override;
};

#endif

