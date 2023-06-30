//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>

class Card {
public:
    Card(auto suit, auto value);

    enum Value {
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
        enumValueEnd
    };
    enum Suit {
        DIAMONDS,
        SPADES,
        CLUBS,
        HEARTS,
        enumSuitEnd
    };
    Card(Card::Suit suit, Card::Value value);
    std::string getSuit() const;
    std::string getValue() const;
private:
    friend std::ostream& operator<<(std::ostream& output, const Card& card);
    Value value;
    Suit suit;
};

#endif //BLACKJACK_CARD_H
