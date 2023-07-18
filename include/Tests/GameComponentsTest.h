//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_GAMECOMPONENTSTEST_H
#define BLACKJACK_GAMECOMPONENTSTEST_H

#include "../GameComponents.h"

class GameComponentsTest {
public:
    static void setupOnePlayer();
    static void setupThreePlayers();
    static void setupDeck();
    static void setupDealer();
    static void printHandHelper();
private:
    GameComponentsTest(); // prevents instance of class
};

#endif //BLACKJACK_GAMECOMPONENTSTEST_H
