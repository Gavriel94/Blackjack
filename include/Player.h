//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <utility>

/**
 * Tests for:
 *
 * - getName()
 * - ace()
 * - receiveCard()
 * -
 */

class Player {
public:
    Player(std::string name);
    void receiveCard(Deck &deck);
    int ace();
    int getHandValue();
    std::vector<Card> getHand();
    bool getBlackjack();
    bool hit();
    void stick();
    bool isPlaying();
    bool isBust();
    std::string getName();
    void printHand();
    void receiveCard(Card card);
private:
    std::string name;
    std::vector<Card> hand;
    bool playing;
    bool bust;
    bool blackjack;
    int handValue;
};

#endif //BLACKJACK_PLAYER_H
