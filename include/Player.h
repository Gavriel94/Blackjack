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
    explicit Player(std::string name);
    int ace();
    int getHandValue() const;
    std::vector<Card> getHand();
    bool getBlackjack() const;
    void stick();
    bool hitOrStick();
    bool getPlaying() const;
    bool isBust() const;
    std::string getName();
    void printHand() const;
    void receiveCard(const Card& card);
    void startNewGame();
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
