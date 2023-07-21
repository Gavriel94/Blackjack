/**
 * @file RunGameTest.h
 * @brief The declaration of the RunGameTest class and its functions.
 * @author Anthony Gavriel
 * @date 07/07/2023
 */

#ifndef BLACKJACK_RUNGAMETEST_H
#define BLACKJACK_RUNGAMETEST_H

#include "../Deck.h"
#include "../Dealer.h"
#include "../GameComponents.h"
#include "../../include/RunGame.h"

/**
 * @class RunGameTest
 * @brief Used to test the functionality of the RunGame class.
 */
class RunGameTest {
public:
        /**
         * @brief Tests the blackjackCheck() function defined in RunGame.h.
         *
         * Ensures the outcome is correct when both dealer and player have blackjack.
         * The message "Bob ties with dealer!" should be displayed.
         */
        static void blackjackTie();

        /**
        * @brief Tests the blackjackCheck() function defined in RunGame.h.
        *
        * Ensures the outcome is correct when the player beats the dealer with blackjack.
        * The message "Bob wins with Blackjack!" should be displayed.
        */
        static void blackjackWin();

        /**
        * @brief Tests the blackjackCheck() function defined in RunGame.h.
        *
        * Ensures the outcome is correct when the dealer beats the player with blackjack.
        * The message "Bob loses!" should be displayed.
        */
        static void blackjackLoss();

        /**
         * @brief Tests the valueCheck() function defined in RunGame.h.
         *
         * Ensures the outcome is correct when both player and dealer have the same handValue.
         * The message "Bob ties with dealer!" should be displayed.
         */
        static void valueTie();

        /**
         * @brief Tests the valueCheck() function defined in RunGame.h.
         *
         * Ensures the outcome is correct when the player beats the dealer by value.
         * The message "Bob wins!" should be displayed.
         */
        static void valueWin();

        /**
         * @brief Tests the valueCheck() function defined in RunGame.h.
         *
         * Ensures the outcome is correct when the dealer beats the player by value.
         * The message "Bob loses!" should be displayed.
         */
        static void valueLoss();

        /**
         * @brief Tests the calculateTurnResult() function defined in RunGame.h.
         *
         * Ensures the outcome is correct if the player is bust.
         * The message "Bob loses!" should be displayed.
         */
        static void playerIsBust();

        /**
         * @brief Tests the calculateTurnResult() function defined in RunGame.h.
         *
         * Ensures the outcome is correct if the dealer is bust.
         * The message "Bob wins!" should be displayed.
         */
        static void dealerIsBust();

        /**
         * @brief Tests the calculateTurnResult() function defined in RunGame.h.
         *
         * Ensures the outcome is correct if the player has blackjack.
         * The message "Bob wins with Blackjack!" should be displayed.
         */
        static void playerHasBlackjack();

        /**
        * @brief Tests the calculateTurnResult() function defined in RunGame.h.
        *
        * Ensures the outcome is correct if the player has blackjack.
        * The message "Dealer has blackjack! Bob loses!" should be displayed.
        */
        static void dealerHasBlackjack();

        /**
         * @brief Tests the calculateTurnResult() function defined in RunGame.h.
         *
         * Ensures the outcome is correct if both the player and dealer have blackjack.
         * The message "Bob ties with dealer!" should be displayed.
         */
        static void bothHaveBlackjack();

        /**
         * @brief Tests the calculateTurnResult() function defined in RunGame.h.
         *
         * Ensures the outcome is correct if the player has a higher handValue than the dealer.
         * The message "Bob wins!" should be displayed.
         */
        static void playerHigherValue();

        /**
        * @brief Tests the calculateTurnResult() function defined in RunGame.h.
        *
        * Ensures the outcome is correct if the dealer has a higher handValue than the player.
        * The message "Bob loses!" should be displayed.
        */
        static void dealerHigherValue();

        /**
        * @brief Tests the calculateTurnResult() function defined in RunGame.h.
        *
        * Ensures the outcome is correct when both player and dealer have the same handValue.
        * The message "Bob ties with dealer!" should be displayed.
        */
        static void bothSameValue();

        /**
         * @brief Runs one player's complete turn.
         *
         * Tests the players ability to:
         * - hit
         * - stick
         * - get blackjack
         * - go bust
         */
        static void playerTurn();

        /**
         * @brief Runs one dealer's turn.
         *
         * Tests the dealers ability to:
         * - hit
         * - stick when handValue => 17 and =< 21
         * - get blackjack
         * - go bust
         */
        static void dealerTurn();

        /**
         * @brief Ensures a new game will start if a player ends a game and decides to keep playing.
         */
        static void keepPlaying();

        /**
         * @brief Ensures the application will terminate if a player ends a game and decides to stop playing.
         */
        static void stopPlaying();
private:
    /**
     * @brief Default constructor for RunGameTest.
     *
     * The constructor is private so the class is not instantiated.
     */
    RunGameTest();
};

#endif //BLACKJACK_RUNGAMETEST_H