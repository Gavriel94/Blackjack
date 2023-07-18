/**
 * @file Deck.cpp
 * @brief The implementation of the Deck class and its functions.
 * @author Anthony Gavriel
 * @date 30/06/2023
 */

#include "../include/Deck.h"

/**
 * @brief Constructor for Deck object.
 */
Deck::Deck() {
    create();
}

/**
 * @brief See declaration in Deck.h for details.
 */
void Deck::shuffle() {
    auto rdm_device = std::random_device {};
    auto rng = std::default_random_engine {
            rdm_device()
    };
    std::shuffle(std::begin(deck), std::end(deck), rng);
}

/**
 * @brief See declaration in Deck.h for details.
 */
Card Deck::removeCard() {
    Card card = deck.at(deck.size()-1);
    deck.pop_back();
    return card;
}

/**
 * @brief See declaration in Deck.h for details.
 */
std::vector<Card> Deck::getDeck() {
    return deck;
}

/**
 * @brief See declaration in Deck.h for details.
 */
int Deck::getSize() {
    return int(deck.size());
}

/**
 * @brief See declaration in Deck.h for details.
 */

void Deck::create() {
    for(int suitIndex = 0; suitIndex < Card::enumSuitEnd; suitIndex++) {
        /** Iterates through suits. */
        for(int valueIndex = 2; valueIndex < Card::enumValueEnd; valueIndex++) {
            /** For each suit, iterates through values. */
            auto suit = (Card::Suit) suitIndex;
            auto value = (Card::Value) valueIndex;
            Card card(suit, value);

            /** Sets ASCII representation for Card by suit and value. */
            switch(suitIndex) {
                case 0:
                    card.setDiamondAscii(valueIndex);
                    break;
                case 1:
                    card.setSpadeAscii(valueIndex);
                    break;
                case 2:
                    card.setClubAscii(valueIndex);
                    break;
                case 3:
                    card.setHeartAscii(valueIndex);
                    break;
                default:
                    std::cout << "Error setting Ascii";
            }
            deck.push_back(card);
        }
    }
}

/**
 * @brief See declaration in Deck.h for details.
 */
bool operator==(const Deck& deck1, const Deck& deck2) {
    /** If sizes aren't equal then decks aren't equal. */
    if(deck1.deck.size() != deck2.deck.size()) {
        return false;
    }

    /** If the order of the cards are different then the decks are different. */
    for(const auto& card1 : deck1.deck) {
        for(const auto& card2 : deck2.deck) {
            if(card1 != card2) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief See declaration in Deck.h for details.
 */
bool operator!=(const Deck& deck1, const Deck& deck2) {
    /** Checks for equality and negates the result */
    return !(deck1 == deck2);
}