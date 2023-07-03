//
// Created by Anthony Gavriel on 03/07/2023.
//

#ifndef BLACKJACK_GAMECOMPONENTS_H
#define BLACKJACK_GAMECOMPONENTS_H

#include <vector>
#include "Player.h"
#include "Deck.h"
#include "Dealer.h"

class GameComponents {
public:
    GameComponents();
    void gameIntro();
    std::vector<Player> setupPlayers();
    Deck setupDeck();
    Dealer setupDealer();
    void gameLoop();
};

#endif //BLACKJACK_GAMECOMPONENTS_H
