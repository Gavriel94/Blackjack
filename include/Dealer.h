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
    void startGame(Deck &deck, std::vector<Player> &players);
    void receiveCard(Card card);
    bool getBust();
    std::vector<Card> getHand();
    int getHandValue();
    bool getPlaying();
    void printHand();
    bool getBlackjack();
private:
    std::vector<Card> hand;
    bool bust;
    int handValue;
    bool playing;
    bool blackjack;
};

#endif //BLACKJACK_DEALER_H
