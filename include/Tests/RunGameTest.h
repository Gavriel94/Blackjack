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
        static void blackjackTie();
        static void blackjackWin();
        static void blackjackLoss();
        static void valueTie();
        static void valueWin();
        static void valueLoss();
        static void playerTurn();
        static void dealerTurn();
        static void keepPlaying();
        static void stopPlaying();
        static void playerIsBust();
        static void dealerIsBust();
        static void playerHasBlackjack();
        static void dealerHasBlackjack();
        static void bothHaveBlackjack();
        static void playerHigherValue();
        static void dealerHigherValue();
        static void bothSameValue();
        static void checkWin();
private:
    RunGameTest(); // prevents instance of class
};

#endif //BLACKJACK_RUNGAMETEST_H