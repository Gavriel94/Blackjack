//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_CARDTEST_H
#define BLACKJACK_CARDTEST_H

#include "../Card.h"
#include <iostream>

class CardTest {
public:
    static void getSuit();
    static void getValue();
    static void setAscii();
private:
    CardTest(); // prevents instance of class
};

#endif //BLACKJACK_CARDTEST_H
