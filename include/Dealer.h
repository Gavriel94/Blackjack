/**
 * @file Dealer.h
 * @brief The declaration of the Dealer class and its functions.
 * @author Anthony Gavriel
 * @date 03/07/2023
 */

#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include <iostream>
#include <vector>

#include "Card.h"
#include "Player.h"
#include "Deck.h"

/**
 * @class Dealer
 * @brief The Blackjack Dealer, who plays against the human players.
 *
 * The dealer follows traditional rules such as sticking if the value of
 * their hand is 17 or above.
 */
class Dealer {
public:
    /**
     * @brief Constructor for a Dealer object
     *
     * Initialises all fields to a default state where no in-game actions have been taken.
     */
    Dealer();

    /**
     * @brief Adds a new card to the dealers hand.

     * The dealer follows the same rules as in a casino:
     * - If their hand is worth 10 or less and they receive an Ace, the value added is 11.
     * - If their hand is worth more than 10 and they receive an Ace, the value added is 1.
     * - If their hand is 17 or more, and they aren't getBust, they getStick.
     *
     * Updates the `handValue` attribute.
     *
     * @param card The card the dealer is receiving.
     */
    void receiveCard(const Card& card);

    /**
     * @brief Resets attributes which determine the dealers game state.
     *
     * Used after every game to reset the following:
     * - hand
     * - handValue
     * - playing
     * - getBust
     * - blackjack
     *
     * This ensures all games are independent from previous ones.
     */
    void startNewGame();


    /**
     * @brief Provides an ASCII representation of the dealers hand in the console.
     *
     * Produces a header informing the player the cards belong
     * to the dealer before printing ASCII cards in a row.
     *
     * Produces a footer displaying the total value of the cards in the dealers hand.
     */
    void printHand() const;

    /**
     * @brief Gets the cards in the dealers hand.
     *
     * @return A vector of Card objects, where each card is held by the dealer.
     */
    std::vector<Card> getHand();

    /**
     * @brief Gets the value of the cards in the dealers hand.
     *
     * Adds together the value for each card.
     *
     * @return An integer representing the cumulative value of all cards in the dealers hand.
     */
    int getHandValue() const;

    /**
     * @brief A getter for the `playing` variable.
     *
     * @return True if the dealer is still playing, otherwise false.
     */
    bool getPlaying() const;

    /**
     * @brief A getter for the `getBust` variable.
     *
     * @return True if the dealer is getBust, otherwise false.
     */
    bool getBust() const;

    /**
     * @brief A getter for the `blackjack` variable.
     *
     * @return True if the dealer has blackjack, otherwise false.
     */
    bool getBlackjack() const;

private:
    /**
     * @brief All cards belonging to the dealer for the current game.
     */
    std::vector<Card> hand;

    /**
     * @brief The total value of all cards currently held by the dealer.
     */
    int handValue;

    /**
     * @brief A variable indicating if the dealer has finished their turn or not.
     */
    bool playing;

    /**
     * @brief A variable indicating if the dealer is getBust or not.
     */
    bool bust;

    /**
     * @brief A variable indicating if the dealer has blackjack or not
     */
    bool blackjack;
};

#endif //BLACKJACK_DEALER_H