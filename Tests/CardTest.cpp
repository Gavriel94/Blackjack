//
// Created by Anthony Gavriel on 30/06/2023.
//
#include "../include/Card.h"
#include <iostream>

class CardTest {
public:
    static void testGetSuit() {
        std::string functionName = "getSuit()";
        Card::Suit suitArray[4] = {Card::DIAMONDS, Card::SPADES, Card::CLUBS, Card::HEARTS };
        std::string suitStringArray[4] = {"Diamonds", "Spades", "Clubs", "Hearts"};

        Card::Value defaultValue = Card::TWO;

        for(int i = 0; i < 4; i++) {
            assert(Card(suitArray[i], defaultValue).getSuit() == suitStringArray[i]);
        }
    }

    static void testGetValue() {
        Card::Value valueArray[13] = {
                Card::TWO, Card::THREE,
                Card::FOUR, Card::FIVE,
                Card::SIX, Card::SEVEN,
                Card::EIGHT, Card::NINE,
                Card::TEN, Card::JACK,
                Card::QUEEN, Card::KING,
                Card::ACE
        };

        std::string valueStringArray[13] = {
                "2", "3",
                "4", "5",
                "6", "7",
                "8", "9",
                "10", "Jack",
                "Queen", "King",
                "Ace"
        };

        Card::Suit defaultSuit = Card::DIAMONDS;

        for(int i = 0; i < 4; i++) {
            assert(Card(defaultSuit, valueArray[i]).getValue() == valueStringArray[i]);
        }
    }

};