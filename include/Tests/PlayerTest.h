/**
 * @file PlayerTest.h
 * @brief The declaration of the PlayerTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_PLAYERTEST_H
#define BLACKJACK_PLAYERTEST_H

#include "../Player.h"

/**
 * @class PlayerTest
 * @brief Used to test the functionality of the Player class.
 */
class PlayerTest {
public:
    /**
     * @brief Tests the ace() function defined in Player.h.
     *
     * Ensures user is able to choose the value '1' for an Ace.
     */
    static void aceIsOne();

    /**
     * @brief Tests the ace() function defined in Player.h.
     *
     * Ensures user is able to choose the value '11' for an Ace.
     */
    static void aceIsEleven();

    /**
     * @brief Tests the receiveCard() function defined in Player.h.
     *
     * This test creates a new Card and executes the receiveCard() method on the player.
     * The test asserts the card is now in the players hand.
     */
    static void receiveCard();

    /**
     * @brief Tests the getHandValue() function defined in Player.h.
     *
     * This test creates a new card and executes the receiveCard() method on the player.
     * The test asserts the value of the card is returned correctly from the player rather than the card.
     */
    static void getHandValue();

    /**
     * @brief Tests the getBust() function defined in Player.h.
     *
     * This test creates a trio of cards which, when given to the player, result in a handValue above 21.
     * This test asserts the `bust` attribute of the player has changed to `true`.
     */
    static void getBust();

    /**
     * @brief Test the printHand() function defined in Player.h.
     *
     * Visual test, passing two random cards to the player before displaying their hand in in the terminal.
     * The user must ensure the cards are printed correctly.
     */
    static void printHand();

    /**
     * @brief Tests the makeBet() function defined in Player.h.
     *
     * Allows the user to make a bet.
     * This test asserts the players `bet` attribute is no longer `0` after the method has run.
     */
    static void makeBet();

    /**
     * @brief Tests the sequence of events when a player wins with Blackjack.
     *
     * This test asserts the `blackjack` attribute has changed to true.
     * This test also asserts the logic to calculate the winnings from their bet is correct.
     */
    static void blackjackWin();

    /**
     * @brief Tests the sequence of events when a player wins by being closer to 21 than the dealer.
     *
     * This test asserts the logic to calculate the winnings from their bet is correct.
     */
    static void standardWin();

    /**
     * @brief Tests the hitOrStick() function defined in Player.h.
     *
     * Checks the sequence of events is correct if the user selects `hit`.
     * This test asserts the player's `playing` attribute remains true.
     */
    static void hit();

    /**
     * @brief Tests the hitOrStick() function defined in Player.h.
     *
     * Checks the sequence of events is correct if the user selects `stick`.
     * This test asserts the player's `playing` attribute changes to false.
     */
    static void stick();

    /**
     * @brief Tests the `==` operator has been overloaded correctly.
     */
    static void comparePlayers();

private:
    /**
     * @brief Default constructor for PlayerTest.
     *
     * The constructor is private so the class is not instantiated.
     */
    PlayerTest();
};

#endif //BLACKJACK_PLAYERTEST_H
