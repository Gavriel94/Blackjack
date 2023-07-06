//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_DEALERTEST_H
#define BLACKJACK_DEALERTEST_H

#include "../Dealer.h"
#include <iostream>

class DealerTest {
public:
    DealerTest();
    static void startGame();
    static void receiveCard();
    static void handValue();
    static void blackjack();
    static void bust();
    static void stick();

};

#endif //BLACKJACK_DEALERTEST_H
