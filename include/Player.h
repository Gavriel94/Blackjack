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
    Player(std::string name, int playerID);
    std::string getName() const;
    int ace();
    void receiveCard(const Card& card);
    bool getBust() const;
    int getHandValue() const;
    size_t getHandSize() const;
    std::vector<Card> getHand();
    bool getBlackjack() const;
    void stick();
    bool hitOrStick();
    bool getPlaying() const;
    void printHand() const;
    void startNewGame();
    float getCash() const;
    float getBet() const;
    void makeBet();
    int getPlayerID() const;
    void receiveWinnings();
    void loseBet();
private:
    int playerID;
    std::string name;
    std::vector<Card> hand;
    std::vector<std::string> handRepresentation;
    bool playing;
    bool bust;
    bool blackjack;
    int handValue;
    float cash;
    float bet;
    friend bool operator==(const Player& player1, const Player& player2);
};

#endif //BLACKJACK_PLAYER_H
