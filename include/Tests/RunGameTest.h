//
// Created by Anthony Gavriel on 07/07/2023.
//

#ifndef BLACKJACK_RUNGAMETEST_H
#define BLACKJACK_RUNGAMETEST_H

#include "../Deck.h"
#include "../Dealer.h"
#include "../GameComponents.h"
#include "../../include/RunGame.h"

class RunGameTest {
public:
        static void gameLoop();
        static void initialiseGame();
        static void checkWin();
        static void blackjackCheck();
        static void valueCheck();
private:
    RunGameTest(); // prevents instance of class
};

#endif //BLACKJACK_RUNGAMETEST_H
