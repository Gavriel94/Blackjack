//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <iostream>
#include <vector>
#include <random>
#include "Card.h"

class Deck {
public:
    Deck();
    void create();
    Card removeCard();
    void shuffle();
    std::vector<Card> getDeck();
    int getSize();
private:
    std::vector<Card> deck;
};




#endif //BLACKJACK_DECK_H
