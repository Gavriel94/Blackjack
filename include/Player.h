//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Card.h"
#include <vector>

class Player {
public:
    Player(std::string name);
    std::vector<Card> hand;
    int getHandValue();
    std::string viewCards();
    bool hit();
    bool stick();
    bool isPlaying();
private:
    std::string name;
    bool playing;
    int handValue;
    int ace();

};

#endif //BLACKJACK_PLAYER_H
