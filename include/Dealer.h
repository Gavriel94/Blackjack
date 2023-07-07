//
// Created by Anthony Gavriel on 03/07/2023.
//

#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include <iostream>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "Deck.h"

class Dealer {
public:
    Dealer();
    void receiveCard(const Card& card);
    bool getBust() const;
    std::vector<Card> getHand();
    int getHandValue() const;
    size_t getHandSize() const;
    bool getPlaying() const;
    void printHand() const;
    bool getBlackjack() const;
    void startNewGame();
private:
    std::vector<Card> hand;
    std::vector<std::string> handRepresentation;
    bool bust;
    int handValue;
    bool playing;
    bool blackjack;
};

#endif //BLACKJACK_DEALER_H
