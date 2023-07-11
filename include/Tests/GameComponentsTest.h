//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_GAMECOMPONENTSTEST_H
#define BLACKJACK_GAMECOMPONENTSTEST_H

#include "../GameComponents.h"

class GameComponentsTest {
public:
    static void setupPlayers();
    static void setupDeck();
    static void setupDealer();
    static void printHandHelper();
    static void playerBlackjack();
    static void dealerBlackjack();
private:
    GameComponentsTest(); // prevents instance of class
};

#endif //BLACKJACK_GAMECOMPONENTSTEST_H
