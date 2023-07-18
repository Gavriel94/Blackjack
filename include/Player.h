/**
 * @file Player.h
 * @brief The declaration of the Player class and its functions.
 * @author Anthony Gavriel
 * @date 30/06/2023
 */

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <vector>
#include <utility>

#include "Card.h"
#include "Deck.h"

/**
 * @brief Declaration of friend class required for testing private functions.
 */
class PlayerTest;

/**
 * @class Player
 * @brief A player who has a name, makes bets and wins or loses in the game of blackjack.
 *
 * Each player is initialised with $50.
 * A players ID is also assigned by default.
 * Input required from a user for creating an instance of a player is only their name.
 * Players are setup in the setupPlayers() function in the GameComponents class.
 */
class Player {
public:
    /**
     * @brief Constructor for a Player object.
     *
     * Initialises all fields to a default state where no in-game actions have been taken.
     * The number of players and the players name are defined via user input in the GameComponents class.
     *
     * @param name The name to be assigned to the player.
     * @param playerID An ID which is automatically assigned during instantiation.
     */
    Player(std::string name, int playerID);

    /**
     * @brief Adds a card to the players hand.
     *
     * If the card is an Ace, the private ace() function is triggered.
     *
     * @param card The card to be added to the players hand.
     */
    void receiveCard(const Card& card);

    /**
     * @brief Gives the player an option to hit or stick on their turn.
     *
     * Receives user input to determine the players action.
     *
     * @return True if the player wants another card, false if the player wants to stick.
     */
    bool hitOrStick();

    /**
     * @brief Receives user input to determine how much the player would like to bet.
     *
     * A minimum bet is $5, players can bet up to all of their cash in one.
     * Cash is stored as a `float`, allowing players to use decimals.
     */
    void makeBet();

    /**
     * @brief Resets attributes which determine the players game state.
     *
     * Used after every game to reset the following:
     * - hand
     * - handValue
     * - playing
     * - bust
     * - blackjack
     *
     * This ensures all games are independent from previous ones.
     */
    void startNewGame();

    /**
     * @brief Provides an ASCII representation of the players hand in the console.
     *
     * Produces a header displaying the players name before printing the ASCII cards in a row.
     * Produces a footer displaying the total value of the cards in their hand.
     */
    void printHand() const;

    /**
     * @brief Determines how much cash the player receives from winning their bet.
     *
     * Prints a message detailing the players name and how much their receive.
     * Uses traditional rules to determine the winnings and increments the `cash` attribute.
     * The cash received from winning is `bet * (1.5 * bet)` if the player wins with blackjack.
     * The cash received from winning is `bet + bet`.
     */
    void win();

    /**
     * @brief Reduces the `cash` variable by the amount the player bet.
     */
    void lose();

    /**
     * @brief A getter for the `name` variable.
     *
     * @return The players name as a string.
     */
    std::string getName() const;

    /**
     * @brief Gets the cards in the players hand.
     *
     * @return A vector of Card objects, where each card is held by the player.
     */
    std::vector<Card> getHand();

    /**
     * @brief Gets the value of the cards in the players hand.
     *
     * Adds together the value for each card.
     *
     * @return An integer representing the cumulative value of all cards in the players hand.
     */
    int getHandValue() const;

    /**
     * @brief A getter for the `playing` variable.
     *
     * @return True if the player is still playing, otherwise false.
     */
    bool getPlaying() const;

    /**
     * @brief A getter for the `bust` variable.
     *
     * @return True if the player is bust, otherwise false.
     */
    bool getBust() const;

    /**
     * @brief A getter for the `blackjack` variable.
     *
     * @return True if the player has blackjack, otherwise false.
     */
    bool getBlackjack() const;

    /**
     * @brief A getter for the `cash` variable.
     *
     * @return The amount of cash the player has, as a float value.
     */
    float getCash() const;

    /**
     * @brief A getter for the `bet` variable.
     *
     * @return The amount of cash the player has bet, as a float value.
     */
    float getBet() const;

private:
    /**
     * @brief Gives the player an option to have the ace as a 1 or 11.
     *
     * @return The value the player has chosen for the ace, as an integer.
     */
    int ace();

    /**
     * Overloads the `==` operator to compare two players.
     *
     * Uses the playerID as a metric for comparison.
     *
     * @param player1 A reference to a player object.
     * @param player2 A reference to a player object.
     * @return True if the players are the same, otherwise false.
     */
    friend bool operator==(const Player& player1, const Player& player2);

    /**
     * @brief The ID of the player.
     */
    int playerID;

    /**
     * @brief The name of the player.
     */
    std::string name;

    /**
     * @brief The cards the player currently has in their hand.
     */
    std::vector<Card> hand;

    /**
     * @brief The cumulative value of the cards in the players hand.
     */
    int handValue;

    /**
     * @brief A boolean indicating if a player is playing or not.
     */
    bool playing;

    /**
     * @brief A boolean indicating if a player is bust or not.
     */
    bool bust;

    /**
     * @brief A boolean indicating if a player has blackjack or not.
     */
    bool blackjack;

    /**
     * @brief A float which describes how much cash the player has.
     */
    float cash;

    /**
     * @brief A float which is the amount the player is betting.
     */
    float bet;

    /**
     * @brief Making PlayerTest a friend class allows testing of private functions.
     */
    friend class PlayerTest;
};

#endif //BLACKJACK_PLAYER_H
