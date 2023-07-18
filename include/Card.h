/**
 * @file Card.h
 * @brief The declaration of the Card class and its functions.
 * @author Anthony Gavriel
 * @date 30/06/2023
 */

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>

/**
 * @class Card
 * @brief An object which represents a playing card in Blackjack
 *
 * Card objects are given a suit and a value which allows them to be used
 * in the same way as cards in the real world
 *
 * As well as having a suit and value, another field, `asciiCard` provides an ASCII representation of each card
 * making them easily differentiable and providing visual feedback when
 * printing to the console.
 */
class Card {
public:
    /**
     * @enum Value
     * @brief The available values for a card
     *
     * Each value represents a standard card value, ranging from TWO (2) to ACE (1/11).
     * enumValueEnd is used as an endpoint for iteration and does not represent any real card value.
     */
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

    /**
     * @enum Suit
     * @brief The available suits for a card
     *
     * Each value represents one of the four standard card suits, Diamonds, Spades, Clubs and Hearts.
     * enumSuitEnd is used as an endpoint for iteration and does not represent any real card suit.
     */
    enum Suit {
        DIAMONDS = 0,
        SPADES,
        CLUBS,
        HEARTS,
        enumSuitEnd
    };

    /**
     * @enum DiamondAscii
     * @brief Used as a library for ASCII representations for each value of the Diamonds suit.
     */
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

    /**
     * @enum SpadeAscii
     * @brief Used as a library for ASCII representations for each value of the Spades suit.
     */
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

    /**
     * @enum ClubAscii
     * @brief Used as a library for ASCII representations for each value of the Clubs suit.
     */
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

    /**
     * @enum HeartAscii
     * @brief Used as a library for ASCII representations for each value of the Hearts suit.
     */
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

    /**
     * @brief Constructor for a Card object.
     *
     * Initialises a Card instance with both a suit and a value.
     *
     * @param suit The suit the Card represents.
     * @param value The value the Card represents.
     */
    Card(Card::Suit suit, Card::Value value);

    /**
     * @brief Used to assign an ASCII representation to a Diamond card during deck instantiation.
     *
     * @param num The value of a card in the Diamonds suit.
     */
    void setDiamondAscii(int num);

    /**
     * @brief Used to assign an ASCII representation to a Club card during deck instantiation.
     *
     * @param num The value of a card in the Clubs suit.
     */
    void setClubAscii(int num);

    /**
     * @brief Used to assign an ASCII representation to a Spade card during deck instantiation.
     *
     * @param num The value of a card in the Spades suit.
     */
    void setSpadeAscii(int num);

    /**
     * @brief Used to assign an ASCII representation to a Heart card during deck instantiation.
     *
     * @param num The value of a card in the Hearts suit.
     */
    void setHeartAscii(int num);

    /**
     * @brief Gets the suit of the card.
     *
     * @return The suit of the card as a string.
     */
    std::string getSuit() const;

    /**
     * @brief Gets the value of the card.
     *
     * @return The value of the card as a string.
     */
    std::string getValue() const;

    /**
     * @brief Gets the ASCII representation of the card.
     *
     * @return The ASCII representation as a string.
     */
    std::string getAscii() const;

private:
    /**
     * @brief Overloads the `\<\<` operator to print the suit and value easily.
     *
     * @param output The output stream where the information is sent.
     * @param card The card whose values are being printed.
     * @return A reference to the output stream, now containing the card information.
     */
    friend std::ostream& operator<<(std::ostream& output, const Card& card);

    /**
     * @brief Overloads the `==` operator to compare two cards easily.
     *
     * @param card1 A reference to a card object.
     * @param card2 A reference to a card object.
     * @return True if the cards are the same, otherwise false.
     */
    friend bool operator==(const Card& card1, const Card& card2);

    /**
     * @brief The value of the card, ranging from TWO (2) to ACE (1/11).
     */
    Value value;

    /**
     * @brief The suit of the card (Diamonds, Spades, Clubs and Hearts).
     */
    Suit suit;

    /**
     * @brief The ASCII representation of the card.
     */
    std::string asciiCard;
};

#endif //BLACKJACK_CARD_H