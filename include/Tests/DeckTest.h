/**
 * @file DeckTest.h
 * @brief The declaration of the DeckTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_DECKTEST_H
#define BLACKJACK_DECKTEST_H

#include "../Deck.h"

/**
 * @class DeckTest
 * @brief Used to test the functionality of the Deck class.
 */
class DeckTest {
public:
    /**
     * @brief Tests the create() function defined in Deck.h.
     *
     * This function creates a new deck object, whose constructor uses the create() function to instantiate a deck.
     * A deck is also manually created by iterating through the suits and values of cards.
     *
     * This test asserts the two decks are matching.
     */
    static void create();

    /**
     * @brief Tests the shuffle() function defined in Deck.h.
     *
     * This function creates two deck objects and runs shuffle() on one of them.
     * This test asserts the two decks are not matching, proving one has been rearranged.
     */
    static void shuffle();

    /**
     * @brief Tests the removeCard() function defined in Deck.h.
     *
     * This function creates a new deck object and shuffles it.
     * The card at position deck.size()-1 is checked and its information is saved in a Card object.
     * The removeCard() method is used on the deck to pop the card at size()-1 and save it as a new Card object.
     * This test asserts the two cards are the same.
     * Another assertion is executed to ensure the size of the deck has been reduced by 1.
     */
    static void removeCard();
private:
    /**
     * @brief Default constructor for DeckTest.
     *
     * The constructor is private so the class is not instantiated.
     */
    DeckTest();
};

#endif //BLACKJACK_DECKTEST_H