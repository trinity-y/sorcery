#include "textdisplay.h"
#include "GameState.h"
#include "Player.h"
#include "./cards/minion.h"
#include "./cards/ritual.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

TextDisplay::TextDisplay(GameStatePtr m)
    : View(std::move(m))
{
}

void TextDisplay::notify(const string &cmd)
{
    istringstream iss(cmd);
    string keyword;
    iss >> keyword;

    if (keyword == "help")
        displayHelp();
    else if (keyword == "board")
        displayBoard();
    else if (keyword == "hand")
        displayHand();
    else if (keyword == "inspect")
    {
        int idx;
        iss >> idx;
        inspectMinion(idx - 1, model->activePlayerIndex());
    }
    // else: other commands mutate the model → model will re‑notify
    else
        cout << "[TextDisplay] unknown cmd: " << cmd << "\n";
}

void TextDisplay::printCard(const card_template_t &tpl)
{
    for (auto &line : tpl)
        cout << line << "\n";
}

void TextDisplay::printRow(const vector<card_template_t> &row)
{
    if (row.empty())
        return;
    int H = (int)row[0].size();
    for (int r = 0; r < H; ++r)
    {
        for (auto &tpl : row)
            cout << tpl[r] << " ";
        cout << "\n";
    }
}
void TextDisplay::displayHelp()
{
    cout << "Available commands:" << endl;
    cout << "  help           - Show this help message" << endl;
    cout << "  board          - Display the current board state" << endl;
    cout << "  hand           - Display your hand" << endl;
    cout << "  inspect <i>    - View minion i's card and all enchantments on that minion" << endl;
    cout << "  play <i> [p t] - Play card i, optionally targeting target-card t owned by target-player p" << endl;
    cout << "  attack <i>.    - Orders minion i to attack the opponent" << endl;
    cout << "  attack <i> [j] - Orders minion i to attack other-minion j" << endl;
    cout << "  use <i> [p t]  - Use minion i's special ability, optionally targeting target-card t owned by target-player p" << endl;
    cout << "  end            - End the current player’s turn." << endl;
    cout << "  quit           - Quit the game" << endl;
}

void TextDisplay::displayHand()
{
    auto &hand = model->currentPlayer().getHand();
    vector<card_template_t> row;
    for (int i = 0; i < hand.getHandLen(); ++i)
    {
        auto &c = hand.getCard(i);
        if (c.type == "Minion")
        {
            // Cast to minion to get attack/defense
            auto &minion = static_cast<const Minion &>(c);
            row.push_back(display_minion_no_ability(
                c.name, c.cost, minion.getAttack(), minion.getDefense()));
        }
        else if (c.type == "Spell")
        {
            row.push_back(display_spell(
                c.name, c.cost, c.description));
        }
        else if (c.type == "Enchantment")
        {
            row.push_back(display_enchantment_attack_defence(
                c.name, c.cost, c.description,
                "?", "?")); // We'll need to figure out enchantment stats
        }
        else if (c.type == "Ritual")
        {
            row.push_back(display_ritual(
                c.name, c.cost,
                0, c.description, // activation cost 0, no charges for now
                0));
        }
    }
    printRow(row);
    cout << "\n";
}

void TextDisplay::displayBoard()
{
    auto &A = model->player(0);
    auto &B = model->player(1);

    // top row: A's ritual + A's minions + grave
    vector<card_template_t> top;
    // For now, add empty card for ritual slot
    top.push_back(CARD_TEMPLATE_EMPTY);

    // Add A's minions
    auto &boardA = A.getBoard();
    for (int i = 0; i < boardA.getNumMinions(); ++i)
    {
        auto &m = boardA.getMinion(i);
        // For now, display as minion with no ability
        top.push_back(display_minion_no_ability(
            m.name, m.cost, m.getAttack(), m.getDefense()));
    }

    // Fill remaining slots with empty cards
    while (top.size() < 6)
        top.push_back(CARD_TEMPLATE_EMPTY);

    // Add A's graveyard (empty for now)
    top.push_back(CARD_TEMPLATE_EMPTY);

    printRow(top);

    // centre graphic
    printRow({CENTRE_GRAPHIC});

    // bottom row: B's grave + minions + ritual
    vector<card_template_t> bot;
    // B's graveyard (empty for now)
    bot.push_back(CARD_TEMPLATE_EMPTY);

    // Add B's minions
    auto &boardB = B.getBoard();
    for (int i = 0; i < boardB.getNumMinions(); ++i)
    {
        auto &m = boardB.getMinion(i);
        bot.push_back(display_minion_no_ability(
            m.name, m.cost, m.getAttack(), m.getDefense()));
    }

    // Fill remaining slots
    while (bot.size() < 6)
        bot.push_back(CARD_TEMPLATE_EMPTY);

    // B's ritual slot (empty for now)
    bot.push_back(CARD_TEMPLATE_EMPTY);

    printRow(bot);

    // finally, the player boxes
    cout << "\nPlayers:\n";
    printCard(display_player_card(
        1, A.getName(), A.getLife(), A.getMagic()));
    printCard(display_player_card(
        2, B.getName(), B.getLife(), B.getMagic()));
    cout << "\n";
}

void TextDisplay::displayCard(int handIndex)
{
    auto &c = model->currentPlayer().getHand().getCard(handIndex);
    card_template_t tpl;
    if (c.type == "Minion")
    {
        auto &minion = static_cast<const Minion &>(c);
        tpl = display_minion_no_ability(
            c.name, c.cost, minion.getAttack(), minion.getDefense());
    }
    else if (c.type == "Spell")
    {
        tpl = display_spell(c.name, c.cost, c.description);
    }
    // Add other types as needed
    printCard(tpl);
    cout << "\n";
}

void TextDisplay::inspectMinion(int idx, int pnum)
{
    auto &P = model->player(pnum);
    auto &board = P.getBoard();
    auto &m = board.getMinion(idx);

    // Display the main minion card
    card_template_t mainTpl = display_minion_no_ability(
        m.name, m.cost, m.getAttack(), m.getDefense());
    printCard(mainTpl);

    // For now, we don't have enchantments implemented
    // This is a placeholder for future enchantment display
    cout << "\n";
}