#include "textdisplay.h"
#include "GameState.h"
#include "player.h"
#include "./cards/minion.h"
#include "./cards/ritual.h"
#include "./cards/enchantments/enchanter.h"
#include "ascii_graphics.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>

TextDisplay::TextDisplay(const GameState &m)
    : View(m)
{
}

void TextDisplay::notify(const string &cmd)
{
    if (cmd == "help")
        displayHelp();
    else if (cmd == "board")
        displayBoard();
    else if (cmd == "hand")
        displayHand();
    else
    {
        std::cout << "[TextDisplay] unknown cmd: " << cmd << "\n";
    }
}

void TextDisplay::notify(const string &cmd, int i)
{
    if (cmd == "inspect")
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

void TextDisplay::printBoardTopBorder()
{
    // Calculate total width: 5 cards * 33 chars + 4 spaces = 169 chars
    int totalWidth = 5 * 33 + 4;

    std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < totalWidth; ++i)
    {
        std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << "\n";
}

void TextDisplay::printBoardBottomBorder()
{
    // Calculate total width: 5 cards * 33 chars + 4 spaces = 169 chars
    int totalWidth = 5 * 33 + 4;

    std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i = 0; i < totalWidth; ++i)
    {
        std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << "\n";
}

void TextDisplay::printBoardRowWithBorder(const vector<card_template_t> &row)
{
    if (row.empty())
        return;

    int H = (int)row[0].size();
    for (int r = 0; r < H; ++r)
    {
        std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN; // Left border
        for (auto &tpl : row)
            std::cout << tpl[r] << " ";
        std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << "\n"; // Right border
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

    std::cout << "DEBUG: Hand has " << hand.getHandLen() << " cards" << std::endl;

    vector<card_template_t> row;
    for (int i = 0; i < hand.getHandLen(); ++i)
    {
        cerr << "REACHED HERE DISPLAYHAND" << endl;
        auto &c = hand.getCard(i);
        cerr << "REACHED HERE DISPLAYHAND1" << endl;
        if (c.type == "MINION")
        {
            cerr << "REACHED HERE MINION" << endl;
            auto &minion = static_cast<const Minion &>(c);
            cerr << "REACHED HERE MINION2" << endl;
            // Check if minion has activated ability to display properly
            if (minion.getActivatedAbilityCost() > 0)
            {
                // Minion with activated ability - need to get ability cost and description
                row.push_back(display_minion_activated_ability(
                    c.name, c.getCost(), minion.getAttack(), minion.getDefense(),
                    minion.getActivatedAbilityCost(), c.description));
            }
            else
            {
                // Check if minion has triggered ability
                // assume if no activated ability, but has a description, then its a triggered ability
                if (!c.description.empty())
                {
                    row.push_back(display_minion_triggered_ability(
                        c.name, c.getCost(), minion.getAttack(), minion.getDefense(),
                        c.description));
                }
                else
                {
                    // Minion without any abilities
                    row.push_back(display_minion_no_ability(
                        c.name, c.getCost(), minion.getAttack(), minion.getDefense()));
                }
            }
        }
        else if (c.type == "SPELL")
        {
            cerr << "REACHED HERE SPELL" << endl;
            row.push_back(display_spell(
                c.name, c.getCost(), c.description));
        }
        else if (c.type == "ENCHANTMENT")
        {
            cerr << "REACHED HERE ENCHANTMENT" << endl;
            const auto &enchantment = static_cast<const Enchantment &>(c);
            row.push_back(display_enchantment_attack_defence(
                c.name, c.getCost(), c.description,
                enchantment.getLeftBox(), enchantment.getLeftBox()));
        }
        else if (c.type == "RITUAL")
        {
            cerr << "REACHED HERE RITUAL" << endl;
            const auto &ritual = static_cast<const Ritual &>(c);
            cerr << "REACHED HERE RITUAL 2" << endl;
            row.push_back(display_ritual(
                c.name, c.getCost(),
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

    // Print top border
    printBoardTopBorder();

    // Row 1: [Ritual][Empty][Player 1][Empty][Graveyard]
    vector<card_template_t> row1;
    // Player 1's ritual slot
    if (boardA.hasRitualCard())
    {
        const auto &ritual = boardA.getRitual();
        row1.push_back(display_ritual(
            ritual.name, ritual.getCost(),
            ritual.getActivationCost(), ritual.description,
            ritual.getCharges()));
    }
    else
    {
        row1.push_back(CARD_TEMPLATE_BORDER); // if no ritual, fill with empty
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
        row1.push_back(CARD_TEMPLATE_BORDER); // Empty graveyard
    }

    // Row 2: Player 1's minions (5 slots)
    vector<card_template_t> row2;
    for (int i = 0; i < 5; ++i)
    {
        if (i < boardA.getNumMinions())
        {
            auto &m = boardA.getMinion(i);
            if (m.getActivatedAbilityCost() > 0)
            {
                row2.push_back(display_minion_activated_ability(
                    m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense(),
                    m.getActivatedAbilityCost(), m.description));
            }
            else if (!m.getMinionDescription().empty())
            {
                row2.push_back(display_minion_triggered_ability(
                    m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense(),
                    m.description));
            }
            else
            {
                row2.push_back(display_minion_no_ability(
                    m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense()));
            }
        }
        else
        {
            row2.push_back(CARD_TEMPLATE_BORDER); // Fill empty slots
        }
    }

    // Row 3: Player 2's minions (5 slots)
    vector<card_template_t> row3;
    for (int i = 0; i < 5; ++i)
    {
        if (i < boardB.getNumMinions())
        {
            auto &m = boardB.getMinion(i);
            if (m.getActivatedAbilityCost() > 0)
            {
                row3.push_back(display_minion_activated_ability(
                    m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense(),
                    m.getActivatedAbilityCost(), m.description));
            }
            else if (!m.getMinionDescription().empty())
            {
                row3.push_back(display_minion_triggered_ability(
                    m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense(),
                    m.description));
            }
            else
            {
                row3.push_back(display_minion_no_ability(
                    m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense()));
            }
        }
        else
        {
            row3.push_back(CARD_TEMPLATE_BORDER); // Fill empty slots
        }
    }

    // Row 4: [Ritual][Empty][Player 2][Empty][Graveyard]
    vector<card_template_t> row4;
    // Player 2's ritual slot
    if (boardB.hasRitualCard())
    {
        const auto &ritual = boardB.getRitual();
        row4.push_back(display_ritual(
            ritual.name, ritual.getCost(),
            ritual.getActivationCost(), ritual.description,
            ritual.getCharges()));
    }
    else
    {
        row4.push_back(CARD_TEMPLATE_BORDER); // if no ritual, fill with empty
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
        row4.push_back(CARD_TEMPLATE_BORDER); // Empty graveyard
    }

    // Print the rows with side borders
    printBoardRowWithBorder(row1);
    printBoardRowWithBorder(row2);
    printRow({CENTRE_GRAPHIC}); // centre graphic (already has its own borders)
    printBoardRowWithBorder(row3);
    printBoardRowWithBorder(row4);

    // Print bottom border
    printBoardBottomBorder();
}

void TextDisplay::displayCard(int handIndex)
{
    auto &c = gameState.currentPlayer().getHand().getCard(handIndex);
    card_template_t tpl;
    if (c.type == "MINION")
    {
        auto &minion = static_cast<const Minion &>(c);

        // Check if minion has activated abilty to display properly
        if (minion.getActivatedAbilityCost() > 0)
        {
            // Minion with activated ability - need to get ablity cost and description
            // TODO: replace minion.getActivatedAbilityDescription() with the actual function
            tpl = display_minion_activated_ability(
                c.name, c.getCost(), minion.getAttack(), minion.getDefense(),
                minion.getActivatedAbilityCost(), minion.getMinionDescription());
        }
        else
        {
            // Check if minion has triggered ability
            // asumme if no activated ability, but has a description, then its a triggered ability
            if (!c.description.empty())
            {
                tpl = display_minion_triggered_ability(
                    c.name, c.getCost(), minion.getAttack(), minion.getDefense(),
                    c.description);
            }
            else
            {
                // Minion without any abilities
                tpl = display_minion_no_ability(
                    c.name, c.getCost(), minion.getAttack(), minion.getDefense());
            }
        }
    }
    else if (c.type == "SPELL")
    {
        tpl = display_spell(c.name, c.getCost(), c.description);
    }
    else if (c.type == "ENCHANTMENT")
    {
        const auto &enchantment = static_cast<const Enchantment &>(c);
        tpl = display_enchantment_attack_defence(
            c.name, c.getCost(), c.description,
            enchantment.getLeftBox(), enchantment.getRightBox());
    }
    else if (c.type == "RITUAL")
    {
        const auto &ritual = static_cast<const Ritual &>(c);
        tpl = display_ritual(
            c.name, c.getCost(),
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

    card_template_t mainTpl;

    if (m.getActivatedAbilityCost() > 0)
    {
        mainTpl = display_minion_activated_ability(
            m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense(),
            m.getActivatedAbilityCost(), m.getMinionDescription());
    }
    else if (!m.getMinionDescription().empty())
    {
        mainTpl = display_minion_triggered_ability(
            m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense(),
            m.getMinionDescription());
    }
    else
    {
        mainTpl = display_minion_no_ability(
            m.getMinionName(), m.getCost(), m.getAttack(), m.getDefense());
    }

    printCard(mainTpl);

    // Collect all enchanters by traversing the decorator chain using recursion
    vector<reference_wrapper<const Enchanter>> enchanters;

    std::function<void(const Minion &)> collectEnchanters = [&](const Minion &minion)
    {
        std::cout << "DEBUG: Checking minion: " << minion.name << ", type: " << minion.type << ", description: " << minion.description << std::endl;

        if (auto enchanter = dynamic_cast<const Enchanter *>(&minion)) // non owning pointer!!! so its okay
        {
            enchanters.push_back(std::cref(*enchanter));

            if (enchanter->nextMinion)
            {
                std::cout << "DEBUG: Recursing to next minion: " << enchanter->nextMinion->name << std::endl;
                collectEnchanters(*enchanter->nextMinion);
            }
        }
        else
        {
            std::cout << "DEBUG: Not an enchanter (reached base minion)" << std::endl;
        }
    };

    collectEnchanters(m);

    // Display enchantments if any - oldest to newest, five per line
    if (!enchanters.empty())
    {
        // Reverse the vector to show oldest to newest (since we collected newest to oldest)
        reverse(enchanters.begin(), enchanters.end());

        // Display enchantments five per line
        for (size_t i = 0; i < enchanters.size(); i += 5)
        {
            vector<card_template_t> enchantmentRow;

            // Add up to 5 enchantments to this row
            for (size_t j = i; j < min(i + 5, enchanters.size()); ++j)
            {
                const Enchanter &ench = enchanters[j].get();
                // Check if this enchantment affects attack/defense
                if (ench.getLeftBox() != "" || ench.getRightBox() != "")
                {
                    // Has attack/defense modifications - use the boxes
                    enchantmentRow.push_back(display_enchantment_attack_defence(
                        ench.name, ench.getCost(), ench.description,
                        ench.getLeftBox(), ench.getRightBox()));
                }
                else
                {
                    // No attack/defense modifications - use regular enchantment display
                    enchantmentRow.push_back(display_enchantment(
                        ench.name, ench.getCost(), ench.description));
                }
            }

            printRow(enchantmentRow);
        }
    }

    std::cout << "\n";
}
