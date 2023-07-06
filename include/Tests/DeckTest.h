//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_DECKTEST_H
#define BLACKJACK_DECKTEST_H

#include "../Deck.h"

class DeckTest {
public:
    DeckTest();
    static void create();
    static void shuffle();
    static void removeCard();
};

#endif //BLACKJACK_DECKTEST_H
