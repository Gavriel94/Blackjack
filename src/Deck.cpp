//
// Created by Anthony Gavriel on 30/06/2023.
//

#include "../include/Deck.h"

Deck::Deck() {
    createDeck();
}

/**
 * Creates a deck by iterating through the suits and values
 * Creates one card of each value for each suit and adds it to the deck
 */
void Deck::createDeck() {
    for(int i = 0; i < Card::enumSuitEnd; i++) {
        for(int j = 2; j < Card::enumValueEnd; j++) {
            auto suit = (Card::Suit) i;
            auto value = (Card::Value) j;
            Card card(suit, value);
            deck.push_back(card);
        }
    }
}

/**
 * Removes card at the top of the deck
 * @return Card
 */
Card Deck::removeCard() {
    if(deck.empty()) {
//        Create deck and shuffle
        createDeck();
        shuffleDeck();
    }
    Card card = deck.at(deck.size()-1);
    deck.pop_back();
    return card;
}

/**
 * Shuffles the cards
 */
void Deck::shuffleDeck() {
    auto rdm_device = std::random_device {};
    auto rng = std::default_random_engine {
        rdm_device()
    };
    std::shuffle(std::begin(deck), std::end(deck), rng);
}

/**
 * Helper methods for tests
 */

void Deck::printDeck() {
    for(auto card : deck) {
        std::cout << card;
    }
}

int Deck::getSize() {
    return int(deck.size());
}
