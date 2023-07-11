//
// Created by Anthony Gavriel on 03/07/2023.
//

#ifndef BLACKJACK_GAMECOMPONENTS_H
#define BLACKJACK_GAMECOMPONENTS_H

#include <vector>
#include <sstream>
#include "Player.h"
#include "Deck.h"
#include "Dealer.h"

class GameComponents {
public:
    GameComponents();
    static void gameIntro();
    static std::vector<Player> setupPlayers();
    static Deck setupDeck();
    static Dealer setupDealer();
    static std::vector<std::string> printHandHelper(const std::string &card, char delim);
    static void bustGraphic(const std::string& name, int value);
    static void cardsGraphic();
    static void playerBlackjack(const Player& player);
    static void dealerBlackjack(const Dealer& dealer);
    static void displayRules();
};

#endif //BLACKJACK_GAMECOMPONENTS_H
