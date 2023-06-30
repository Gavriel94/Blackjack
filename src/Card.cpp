//
// Created by Anthony Gavriel on 30/06/2023.
//

#include "../include/Card.h"

Card::Card(Card::Suit suit, Card::Value value) {
    this->suit = suit;
    this->value = value;
}

std::string Card::getSuit() const {
    switch(suit) {
        case DIAMONDS:
            return "Diamonds";
        case SPADES:
            return "Spades";
        case CLUBS:
            return "Clubs";
        case HEARTS:
            return "Hearts";
        case enumSuitEnd:
            break;
    }
    return "Error finding suit";
}

std::string Card::getValue() const {
    switch(value) {
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case TEN:
            return "10";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        case ACE:
            return "Ace";
        case enumValueEnd:
            break;
    }
    return "Error finding value";
}

// Overload << operator to print details on one line
std::ostream& operator<<(std::ostream& output, const Card& card) {
    std::string suit = card.getSuit();
    std::string value = card.getValue();

    output << value << " of " << suit << "\n";
    return output;
}