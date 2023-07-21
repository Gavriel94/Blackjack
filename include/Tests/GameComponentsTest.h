/**
 * @file GameComponentsTest.h
 * @brief The declaration of the GameComponentsTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_GAMECOMPONENTSTEST_H
#define BLACKJACK_GAMECOMPONENTSTEST_H

#include "../GameComponents.h"

/**
 * @class GameComponentsTest
 * @brief Used to test the functionality of the GameComponents class.
 */
class GameComponentsTest {
public:
    /**
     * @brief Tests the setupPlayer() function defined in GameComponents.h.
     *
     * Tests the setupPlayer() function with 1 game player.
     * As this function requires user input, the tester is displayed the conditions required to pass the test.
     */
    static void setupOnePlayer();

    /**
     * @brief Tests the setupPlayer() function defined in GameComponents.h.
     *
     * Tests the setupPlayer() function with 1 game player.
     * As this function requires user input, the tester is displayed the conditions required to pass the test.
     */
    static void setupThreePlayers();

    /**
     * @brief Tests the setupDeck() function defined in GameComponents.h.
     *
     * Compares a deck created manually and through the setupDeck() function.
     * Asserts the decks are the same before the GameComponents deck is shuffled, then another assertion ensures they are different.
     */
    static void setupDeck();

    /**
     * @brief Tests the setupDealer() function defined in GameComponents.h.
     *
     * Creates a new dealer object and ensures it is playing.
     */
    static void setupDealer();

    /**
     * @brief Tests the printHandHelper() function defined in GameComponents.h.
     *
     * Visual test, the user must ensure the cards are displayed correctly in the terminal.
     */
    static void printHandHelper();
private:
    /**
     * @brief Default constructor for GameComponentsTest.
     *
     * The constructor is private so the class is not instantiated.
     */
    GameComponentsTest();
};

#endif //BLACKJACK_GAMECOMPONENTSTEST_H
