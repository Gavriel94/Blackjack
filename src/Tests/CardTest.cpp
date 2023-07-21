/**
 * @file CardTest.cpp
 * @brief The implementation of the CardTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#include "../../include/Tests/CardTest.h"

/**
 * @brief Default constructor for CardTest.
 */
CardTest::CardTest() = default;

/**
 * @brief See declaration in CardTest.h for details.
 */
void CardTest::getSuit() {
    Card::Suit suitArray[4] = {Card::DIAMONDS, Card::SPADES, Card::CLUBS, Card::HEARTS };
    std::string suitStringArray[4] = {"Diamonds", "Spades", "Clubs", "Hearts"};

    Card::Value defaultValue = Card::TWO;

    for(int i = 0; i < 4; i++) {
        assert(Card(suitArray[i], defaultValue).getSuit() == suitStringArray[i]);
    }
}

/**
 * @brief See declaration in CardTest.h for details.
 */
void CardTest::getValue() {
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

/**
 * @brief See declaration in CardTest.h for details.
 */
void CardTest::ascii() {
    Card card = Card(Card::DIAMONDS, Card::TWO);
    std::cout << "2 of Diamonds\n\n";
    card.setDiamondAscii(2);
    std::cout << card.getAscii() << "\n\n";

    std::cout << "Ace of Spades\n\n";
    card = Card(Card::SPADES, Card::ACE);
    card.setSpadeAscii(14);
    std::cout << card.getAscii() << "\n\n";

}