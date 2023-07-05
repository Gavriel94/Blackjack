//
// Created by Anthony Gavriel on 30/06/2023.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>

class Card {
public:
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
        DIAMONDS = 0,
        SPADES,
        CLUBS,
        HEARTS,
        enumSuitEnd
    };
    enum DiamondAscii {
        TWO_OF_DIAMONDS = 2,
        THREE_OF_DIAMONDS,
        FOUR_OF_DIAMONDS,
        FIVE_OF_DIAMONDS,
        SIX_OF_DIAMONDS,
        SEVEN_OF_DIAMONDS,
        EIGHT_OF_DIAMONDS,
        NINE_OF_DIAMONDS,
        TEN_OF_DIAMONDS,
        JACK_OF_DIAMONDS,
        QUEEN_OF_DIAMONDS,
        KING_OF_DIAMONDS,
        ACE_OF_DIAMONDS
    };

    enum SpadeAscii {
        TWO_OF_SPADES = 2,
        THREE_OF_SPADES,
        FOUR_OF_SPADES,
        FIVE_OF_SPADES,
        SIX_OF_SPADES,
        SEVEN_OF_SPADES,
        EIGHT_OF_SPADES,
        NINE_OF_SPADES,
        TEN_OF_SPADES,
        JACK_OF_SPADES,
        QUEEN_OF_SPADES,
        KING_OF_SPADES,
        ACE_OF_SPADES
    };

    enum ClubAscii {
        TWO_OF_CLUBS = 2,
        THREE_OF_CLUBS,
        FOUR_OF_CLUBS,
        FIVE_OF_CLUBS,
        SIX_OF_CLUBS,
        SEVEN_OF_CLUBS,
        EIGHT_OF_CLUBS,
        NINE_OF_CLUBS,
        TEN_OF_CLUBS,
        JACK_OF_CLUBS,
        QUEEN_OF_CLUBS,
        KING_OF_CLUBS,
        ACE_OF_CLUBS
    };

    enum HeartAscii {
        TWO_OF_HEARTS = 2,
        THREE_OF_HEARTS,
        FOUR_OF_HEARTS,
        FIVE_OF_HEARTS,
        SIX_OF_HEARTS,
        SEVEN_OF_HEARTS,
        EIGHT_OF_HEARTS,
        NINE_OF_HEARTS,
        TEN_OF_HEARTS,
        JACK_OF_HEARTS,
        QUEEN_OF_HEARTS,
        KING_OF_HEARTS,
        ACE_OF_HEARTS
    };

    Card(Card::Suit suit, Card::Value value);
    std::string getSuit() const;
    std::string getValue() const;
    void setDiamondAscii(int num);
    void setClubAscii(int num);
    void setSpadeAscii(int num);
    void setHeartAscii(int num);
    std::string getAscii() const;
private:
    friend std::ostream& operator<<(std::ostream& output, const Card& card);
    friend bool operator==(const Card& card1, const Card& card2);
    Value value;
    Suit suit;
    std::string asciiCard;
    DiamondAscii diamondAscii;
    SpadeAscii spadesAscii;
    ClubAscii clubsAscii;
    HeartAscii heartsAscii;
};

#endif //BLACKJACK_CARD_H
