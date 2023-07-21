/**
 * @file DealerTest.h
 * @brief The declaration of the DealerTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_DEALERTEST_H
#define BLACKJACK_DEALERTEST_H

#include "../Dealer.h"
#include <iostream>

/**
 * @class DealerTest
 * @brief Used to test functionality of the Dealer class
 */
class DealerTest {
public:
    /**
     * @brief Tests the receiveCard() function defined in Dealer.h.
     *
     * Initialises a dealer and a card object.
     * Uses receiveCard() to add the card to the dealers hand.
     * This test asserts the card in the dealers hand is the same card object in scope.
     */
    static void receiveCard();

    /**
     * @brief Tests the handValue() function defined in Dealer.h.
     *
     * Initialises a dealer and deck object.
     * Shuffles the deck and removes a card.
     * This test asserts the value of a random card (including Ace) is the same as the dealers hand.
     *
     * Resets the dealer and executes another assertion, comparing the value to a hard-coded hand with multiple cards.
     */
    static void handValue();

    /**
     * @brief Tests the getBlackjack() function defined in Dealer.h.
     *
     * Hard-codes a blackjack hand and checks the `blackjack` boolean attribute has returned true.
     */
    static void blackjack();

    /**
     * @brief Tests the getBust() function defined in Dealer.h.
     *
     * Hard-codes a bust hand and checks the `bust` boolean attribute has returned true.
     */
    static void getBust();

    /**
     * @brief Tests the getStick() function defined in Dealer.h.
     *
     * Hard-codes a hand valuing 17, where the dealer should stick, and checks the `playing` boolean attribute has returned false.
     */
    static void getStick();
private:
    /**
     * @brief Default constructor for DealerTest.
     *
     * The constructor is private so the class is not instantiated.
     */
    DealerTest(); // prevents instance of class
};

#endif //BLACKJACK_DEALERTEST_H
