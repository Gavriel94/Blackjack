//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_DEALERTEST_H
#define BLACKJACK_DEALERTEST_H

#include "../Dealer.h"
#include <iostream>

class DealerTest {
public:
    static void receiveCard();
    static void handValue();
    static void blackjack();
    static void bust();
    static void stick();
private:
    DealerTest(); // prevents instance of class
};

#endif //BLACKJACK_DEALERTEST_H
