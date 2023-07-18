/**
 * @file GameComponents.h
 * @brief The declaration of the GameComponents class and its functions.
 * @author Anthony Gavriel
 * @date 03/07/2023
 */

#ifndef BLACKJACK_GAMECOMPONENTS_H
#define BLACKJACK_GAMECOMPONENTS_H

#include <vector>
#include <sstream>

#include "Player.h"
#include "Deck.h"
#include "Dealer.h"

/**
 * @class GameComponents
 * @brief Provides methods to set up the players, deck, dealer, and contains helper functions and graphics.
 *
 * GameComponents contains utility and helper functions making it a suitable candidate for stateless behaviour.
 */
class GameComponents {
public:
    /**
     * @brief Player setup wizard.
     *
     * Asks the user how many players are playing, and what their names are.
     * Creates a player object for each player.
     *
     * @return A vector containing user defined Player objects.
     */
    static std::vector<Player> setupPlayers();

    /**
     * @brief Creates a new Deck object.
     *
     * Instantiates a new deck.
     * A deck is a set of 52 unique playing cards.
     * The deck is not shuffled by default.
     *
     * @return A new Deck object.
     */
    static Deck setupDeck();

    /**
     * @brief Creates a new dealer object.
     *
     * Instantiates a new dealer.
     * The dealer constructor ensures all dealer fields are set to a default, no-action-taken state.
     *
     * The dealer is ready to be used for a new game as soon as it is created.
     *
     * @return A new Dealer object.
     */
    static Dealer setupDealer();

    /**
     * @brief Helper function for printing ASCII cards in a row.
     *
     * Splits a string into multiple substrings and stores them in a vector.
     *
     * The card
     *
     * "  _____ \n"
     *  " |A .  |\n"
     *  " | /.\\ |\n"
     *  " |(_._)|\n"
     *  " |  |  |\n"
     *  " |____V|"
     *
     *  is stored as
     *
     * ["  _____ ", " |A .  |", " | /.\\ |", "" |(_._)|", " |  |  |", " |____V|"]
     *
     * When used in the Player or Dealer class to print their hand, the i-th line of each
     * card is printed, allowing any number of ASCII cards to be printed in a row.
     *
     * @param card The card to be split into substrings.
     * @param delim The end-of-line indicator.
     * @return A vector containing the card split into a row of substrings.
     */
    static std::vector<std::string> printHandHelper(const std::string &card, char delim);

    /**
     * @brief A simple description of the rules of Blackjack.
     */
    static void displayRules();

    /**
     * @brief A welcome message when the user starts a new game.
     */
    static void gameIntro();

    /**
     * @brief ASCII art of an explosion to represent the player going "bust".
     *
     * Displays the player name and value of their hand.
     *
     * @param name The name of the player who went bust.
     * @param value The value of their hand.
     */
    static void bustGraphic(const std::string& name, int value);

    /**
     * @brief ASCII art of an ace of each suit in a row.
     *
     * Used in the game intro.
     */
    static void cardsGraphic();

    /**
     * @brief Graphic showing the player has chosen to stick.
     *
     * Shows the value of the players hand and their name.
     *
     * @param name The name of the player.
     * @param handValue The value of the players hand.
     */
    static void stickGraphic(const std::string& name, int handValue);

    /**
     * @brief Graphic showing the player has blackjack
     *
     * Also prints the players hand.
     *
     * @param player The player who received blackjack.
     */
    static void playerBlackjack(const Player& player);

    /**
     * @brief Graphic showing the dealer has blackjack.
     *
     * Also prints the dealers hand.
     *
     * @param dealer The dealer who received blackjack.
     */
    static void dealerBlackjack(const Dealer& dealer);
private:
    /**
     * @brief Default constructor for GameComponents.
     *
     * The constructor is private so the class is not instantiated.
     */
    GameComponents();
};

#endif //BLACKJACK_GAMECOMPONENTS_H
