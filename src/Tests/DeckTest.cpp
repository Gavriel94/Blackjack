/**
 * @file DeckTest.cpp
 * @brief The implementation of the DeckTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#include "../../include/Tests/DeckTest.h"

/**
 * @brief Default constructor for DeckTest.
 */
DeckTest::DeckTest() = default;

/**
 * @brief See declaration in DeckTest.h for details.
 */
void DeckTest::create() {
    Deck deck = Deck();

    std::vector<Card> cards;

    /** Manually creates a deck */
    for(int i = 0; i < Card::enumSuitEnd; i++) {
        for(int j = 2; j < Card::enumValueEnd; j++) {
            auto suit = (Card::Suit) i;
            auto value = (Card::Value) j;
            Card card(suit, value);
            cards.push_back(card);
        }
    }
    assert(deck.getSize() == 52);
    assert(deck.getDeck() == cards);
}

/**
 * @brief See declaration in DeckTest.h for details.
 */
void DeckTest::shuffle() {
    Deck shuffledDeck = Deck();
    Deck deck = Deck();

    shuffledDeck.shuffle();

    assert(shuffledDeck != deck);
}

/**
 * @brief See declaration in DeckTest.h for details.
 */
void DeckTest::removeCard() {
    Deck deck = Deck();
    deck.shuffle();
    Card bottomCard = deck.getDeck().at(deck.getDeck().size()-1);
    Card removedCard = deck.removeCard();

    assert(bottomCard == removedCard);
    assert(deck.getSize() == 51);
}