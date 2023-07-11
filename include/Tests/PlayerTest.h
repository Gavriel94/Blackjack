//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_PLAYERTEST_H
#define BLACKJACK_PLAYERTEST_H

#include "../Player.h"

class PlayerTest {
public:
    static void ace();
    static void receiveCard();
    static void getBust();
    static void printHand();
    static void makeBet();
    static void receiveWinnings();
    static void hitOrStick();

private:
    PlayerTest(); // prevents instance of class
};

#endif //BLACKJACK_PLAYERTEST_H
