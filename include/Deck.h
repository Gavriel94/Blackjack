//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "Card.h"
#include <iostream>
#include <vector>
#include <random>

class Deck {
public:
    Deck();
    void createDeck();
    Card removeCard();
    void shuffleDeck();
//    Functions for tests
    void printDeck();
    int getSize();
private:
    std::vector<Card> deck;
};




#endif //BLACKJACK_DECK_H
