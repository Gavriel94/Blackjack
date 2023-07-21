/**
 * @file CardTest.h
 * @brief The declaration of the CardTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_CARDTEST_H
#define BLACKJACK_CARDTEST_H

#include "../Card.h"
#include <iostream>

/**
 * @class CardTest
 * @brief Used to test functionality of the Card class
 */
class CardTest {
public:
    /**
     * @brief Tests the getSuit() function defined in Card.h.
     *
     * Initialises a card with each suit and calls getSuit().
     * This test asserts the suits are matching.
     */
    static void getSuit();

    /**
     * @brief Tests the getValue() function defined in Card.h.
     *
     * Initialises a card with each value and calls getValue().
     * This test asserts the values are matching.
     */
    static void getValue();

    /**
     * @brief Tests the getAscii() function defined in Card.h.
     *
     * A visual test, displays the card to the user.
     */
    static void ascii();
private:
    /**
     * @brief Default constructor for CardTest.
     *
     * The constructor is private so the class is not instantiated.
     */
    CardTest();
};

#endif //BLACKJACK_CARDTEST_H