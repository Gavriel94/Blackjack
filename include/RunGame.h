//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_RUNGAME_H
#define BLACKJACK_RUNGAME_H

#include "Deck.h"
#include "Dealer.h"
#include "GameComponents.h"

class RunGameTest;

class RunGame {
public:
    RunGame();
    bool gameLoop();
    void initialiseGame();
    void checkWin();
private:
    Dealer dealer;
    Deck deck;
    std::vector<Player> players;
    void playerTurn(Player& player);
    void dealerTurn();
    void printValues();
    bool keepPlaying();
    bool blackjackCheck(Player& player);
    void valueCheck(Player& player);
    void checkIfPlayerOut(Player& player);
    //allows testing of private methods
    friend class RunGameTest;
};

#endif //BLACKJACK_RUNGAME_H
