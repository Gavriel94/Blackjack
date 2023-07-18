//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_PLAYERTEST_H
#define BLACKJACK_PLAYERTEST_H

#include "../Player.h"

class PlayerTest {
public:
    static void aceIsOne();
    static void aceIsEleven();
    static void receiveCard();
    static void getHandValue();
    static void getBust();
    static void printHand();
    static void makeBet();
    static void blackjackWin();
    static void standardWin();
    static void hit();
    static void stick();
    static void comparePlayers();

private:
    PlayerTest(); // prevents instance of class
};

#endif //BLACKJACK_PLAYERTEST_H
