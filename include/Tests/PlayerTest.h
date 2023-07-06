//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_PLAYERTEST_H
#define BLACKJACK_PLAYERTEST_H

#include "../Player.h"

class PlayerTest {
public:
    PlayerTest();
    static void getName();
    static void ace();
    static void receiveCard();
    static void isBust();
};

#endif //BLACKJACK_PLAYERTEST_H
