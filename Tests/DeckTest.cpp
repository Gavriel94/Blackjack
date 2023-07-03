//
// Created by Anthony Gavriel on 01/07/2023.
//

#include "../include/Deck.h"

class DeckTest {
public:
    static void testCreate() {
        Deck deck = Deck();
        deck.create();

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

    static void testShuffle() {
        Deck shuffledDeck = Deck();
        shuffledDeck.create();
        shuffledDeck.shuffle();

        Deck plainDeck = Deck();

        assert(plainDeck.getDeck() != shuffledDeck.getDeck());
    }

    static void testRemoveCard() {
        Deck deck = Deck();

        deck.create();
        Card bottomCard = deck.getDeck().at(deck.getDeck().size()-1);
        Card removedCard = deck.removeCard();

        assert(bottomCard == removedCard);
        assert(deck.getSize() == 51);
    }
};