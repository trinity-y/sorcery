#include "textdisplay.h"
#include "GameState.h"
#include "player.h"
#include "./cards/minion.h"
#include "./cards/ritual.h"
#include "ascii_graphics.h"
#include <iostream>
#include <sstream>
#include <algorithm>

TextDisplay::TextDisplay(const GameState& m)
    : View(m)
{
}

void TextDisplay::notify(const string &cmd, int i)
{
    if (cmd == "help")
        displayHelp();
    else if (cmd == "board")
        displayBoard();
    else if (cmd == "hand")
        displayHand();
    else if (cmd == "inspect")
    {
        inspectMinion(i - 1, gameState.activePlayerIndex());
    }
    else
    {
        std::cout << "[TextDisplay] unknown cmd: " << cmd << "\n";
    }
}

void TextDisplay::printCard(const card_template_t &tpl)
{
    for (auto &line : tpl)
        std::cout << line << "\n";
}

void TextDisplay::printRow(const vector<card_template_t> &row)
{
    if (row.empty())
        return;
    int H = (int)row[0].size();
    for (int r = 0; r < H; ++r)
    {
        for (auto &tpl : row)
            std::cout << tpl[r] << " ";
        std::cout << "\n";
    }
}
void TextDisplay::displayHelp()
{
    std::cout << "Available commands:" << endl;
    std::cout << "  help           - Show this help message" << endl;
    std::cout << "  board          - Display the current board state" << endl;
    std::cout << "  hand           - Display your hand" << endl;
    std::cout << "  inspect <i>    - View minion i's card and all enchantments on that minion" << endl;
    std::cout << "  play <i> [p t] - Play card i, optionally targeting target-card t owned by target-player p" << endl;
    std::cout << "  attack <i>.    - Orders minion i to attack the opponent" << endl;
    std::cout << "  attack <i> [j] - Orders minion i to attack other-minion j" << endl;
    std::cout << "  use <i> [p t]  - Use minion i's special ability, optionally targeting target-card t owned by target-player p" << endl;
    std::cout << "  end            - End the current player’s turn." << endl;
    std::cout << "  quit           - Quit the game" << endl;
}

void TextDisplay::displayHand()
{
    auto &hand = gameState.currentPlayer().getHand();
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
                "?", "?")); // to do:  need to figure out enchantment stats
        }
        else if (c.type == "Ritual")
        {
            const auto &ritual = static_cast<const Ritual &>(c);
            row.push_back(display_ritual(
                c.name, c.cost,
                ritual.getActivationCost(), c.description, // getting ritual activation cost and charges via getters
                ritual.getCharges()));
        }
    }
    printRow(row);
    std::cout << "\n";
}

void TextDisplay::displayBoard()
{
    auto &A = gameState.player(0);
    auto &B = gameState.player(1);
    auto &boardA = A.getBoard();
    auto &boardB = B.getBoard();

    // Row 1: [Ritual][Empty][Player 1][Empty][Grayeyard]
    vector<card_template_t> row1;
    // Player 1's ritual slot
    if (boardA.hasRitualCard())
    {
        const auto &ritual = boardA.getRitual();
        row1.push_back(display_ritual(
            ritual.name, ritual.cost,
            ritual.getActivationCost(), ritual.description,
            ritual.getCharges()));
    }
    else
    {
        row1.push_back(CARD_TEMPLATE_EMPTY); // if no ritual, fill with empty
    }
    row1.push_back(CARD_TEMPLATE_EMPTY); // Empty
    row1.push_back(display_player_card(
        1, A.getName(), A.getLife(), A.getMagic())); // Player 1 in center-top
    row1.push_back(CARD_TEMPLATE_EMPTY);             // Empty
    // Player 1's graveyard
    auto &graveyardA = A.getGraveyard();
    if (graveyardA.getNumMinions() > 0)
    {
        row1.push_back(display_minion_no_ability(
            "Graveyard", 0, 0, graveyardA.getNumMinions()));
    }
    else
    {
        row1.push_back(CARD_TEMPLATE_EMPTY); // Empty graveyard
    }

    // Row 2: Player 1's minions (5 slots)
    vector<card_template_t> row2;
    for (int i = 0; i < 5, ++i;)
    {
        if (i < boardA.getNumMinions())
        {
            auto &m = boardA.getMinion(i);
            row2.push_back(display_minion_no_ability(
                m.name, m.cost, m.getAttack(), m.getDefense()));
        }
        else
        {
            row2.push_back(CARD_TEMPLATE_EMPTY); // Fill empty slots
        }
    }

    // Row 3: Player 2's minions (5 slots)
    vector<card_template_t> row3;
    for (int i = 0; i < 5; ++i)
    {
        if (i < boardB.getNumMinions())
        {
            auto &m = boardB.getMinion(i);
            row3.push_back(display_minion_no_ability(
                m.name, m.cost, m.getAttack(), m.getDefense()));
        }
        else
        {
            row3.push_back(CARD_TEMPLATE_EMPTY); // Fill empty slots
        }
    }

    // Row 4: [Ritual][Empty][Player 2][Empty][Graveyard]
    vector<card_template_t> row4;
    // Player 2's ritual slot
    if (boardB.hasRitualCard())
    {
        const auto &ritual = boardB.getRitual();
        row4.push_back(display_ritual(
            ritual.name, ritual.cost,
            ritual.getActivationCost(), ritual.description,
            ritual.getCharges()));
    }
    else
    {
        row4.push_back(CARD_TEMPLATE_EMPTY); // if no ritual, fill with empty
    }
    row4.push_back(CARD_TEMPLATE_EMPTY); // Empty
    row4.push_back(display_player_card(
        2, B.getName(), B.getLife(), B.getMagic())); // Player 2 in center-bottom
    row4.push_back(CARD_TEMPLATE_EMPTY);             // Empty
    auto &graveyardB = B.getGraveyard();
    if (graveyardB.getNumMinions() > 0)
    {
        row4.push_back(display_minion_no_ability(
            "Graveyard", 0, 0, graveyardB.getNumMinions()));
    }
    else
    {
        row4.push_back(CARD_TEMPLATE_EMPTY); // Empty graveyard
    }

    // Print the rows
    printRow(row1);
    printRow(row2);
    printRow({CENTRE_GRAPHIC}); // centre graphic
    printRow(row3);
    printRow(row4);
}

void TextDisplay::displayCard(int handIndex)
{
    auto &c = gameState.currentPlayer().getHand().getCard(handIndex);
    card_template_t tpl;
    if (c.type == "Minion")
    {
        auto &minion = static_cast<const Minion &>(c);

        // Check if minion has activated abilty to display properly
        if (minion.getActivatedAbilityCost() > 0)
        {
            // Minion with activated ability - need to get ablity cost and description
            // TODO: replace minion.getActivatedAbilityDescription() with the actual function
            tpl = display_minion_activated_ability(
                c.name, c.cost, minion.getAttack(), minion.getDefense(),
                minion.getActivatedAbilityCost(), "minion.getActivatedAbilityDescription()");
        }
        else
        {
            // Check if minion has triggered ability
            // asumme if no activated ability, but description, then its a triggered ability
            if (!c.description.empty())
            {
                tpl = display_minion_triggered_ability(
                    c.name, c.cost, minion.getAttack(), minion.getDefense(),
                    c.description);
            }
            else
            {
                // Minion without any abilities
                tpl = display_minion_no_ability(
                    c.name, c.cost, minion.getAttack(), minion.getDefense());
            }
        }
    }
    else if (c.type == "Spell")
    {
        tpl = display_spell(c.name, c.cost, c.description);
    }
    else if (c.type == "Enchantment")
    {
        tpl = display_enchantment_attack_defence(
            c.name, c.cost, c.description,
            "?", "?"); // to do: need to figure out enchantment stats
    }
    else if (c.type == "Ritual")
    {
        const auto &ritual = static_cast<const Ritual &>(c);
        tpl = display_ritual(
            c.name, c.cost,
            ritual.getActivationCost(), c.description, // getting ritual activation cost and charges via getters
            ritual.getCharges());
    }
    else
    {
        // todo: error handling for unknown card type
    }
    printCard(tpl);
    std::cout << "\n";
}

void TextDisplay::inspectMinion(int idx, int pnum)
{
    auto &P = gameState.player(pnum);
    auto &board = P.getBoard();
    auto &m = board.getMinion(idx);

    // Display the main minion card
    card_template_t mainTpl = display_minion_no_ability(
        m.name, m.cost, m.getAttack(), m.getDefense());
    printCard(mainTpl);

    // For now, we don't have enchantments implemented
    // This is a placeholder for future enchantment display
    std::cout << "\n";
}