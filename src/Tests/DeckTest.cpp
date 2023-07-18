//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../../include/Tests/DeckTest.h"

DeckTest::DeckTest() = default;

void DeckTest::create() {
    Deck deck = Deck();

    std::vector<Card> cards;

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

void DeckTest::shuffle() {
    Deck shuffledDeck = Deck();
    Deck deck = Deck();

    shuffledDeck.shuffle();

    assert(shuffledDeck != deck);
}

void DeckTest::removeCard() {
    Deck deck = Deck();

    Card bottomCard = deck.getDeck().at(deck.getDeck().size()-1);
    Card removedCard = deck.removeCard();

    assert(bottomCard == removedCard);
    assert(deck.getSize() == 51);
}