//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_RUNGAME_H
#define BLACKJACK_RUNGAME_H

#include "Deck.h"
#include "Dealer.h"
#include "GameComponents.h"

class RunGame {
public:
    RunGame();
    bool gameLoop();
    void initialiseGame();
private:
    Dealer dealer;
    Deck deck;
    std::vector<Player> players;
};

#endif //BLACKJACK_RUNGAME_H
