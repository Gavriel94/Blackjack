//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <vector>
#include <utility>
#include "Card.h"
#include "Deck.h"

class Player {
public:
    Player(std::string name);
    int ace();
    int getHandValue();
    std::vector<Card> getHand();
    bool getBlackjack();
    void stick();
    bool hitOrStick();
    bool getPlaying();
    bool isBust();
    std::string getName();
    void printHand();
    void receiveCard(Card card);
private:
    std::string name;
    std::vector<Card> hand;
    std::vector<std::string> handRepresentation;
    bool playing;
    bool bust;
    bool blackjack;
    int handValue;
};

#endif //BLACKJACK_PLAYER_H
