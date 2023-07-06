//
// Created by Anthony Gavriel on 30/06/2023.
//

/**
 * ASCII Art credit: ejm98
 * https://www.asciiart.eu/miscellaneous/playing-cards
 */

#include "../include/Card.h"

/**
 * Constructor for Card objects
 *
 * asciiCard is set during instantiation of the Deck
 *
 * @param suit suit of the card
 * @param value value of the card
 */
Card::Card(Card::Suit suit, Card::Value value) {
    this->suit = suit;
    this->value = value;
    asciiCard = "";
}

/**
 * Sets the asciiCard variable for cards belonging to the Diamond suit
 *
 * @param num the value of the card, determining which graphic it is assigned
 */
void Card::setDiamondAscii(int num) {
    switch(num) {
        case TWO_OF_DIAMONDS:
            asciiCard =  "  _____ \n"
                   " |2    |\n"
                   " |  o  |\n"
                   " |     |\n"
                   " |  o  |\n"
                   " |____Z|";
            break;
        case THREE_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |3    |\n"
                   " | o o |\n"
                   " |     |\n"
                   " |  o  |\n"
                   " |____E|";
            break;
        case FOUR_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |4    |\n"
                   " | o o |\n"
                   " |     |\n"
                   " | o o |\n"
                   " |____h|";
            break;
        case FIVE_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |5    |\n"
                   " | o o |\n"
                   " |  o  |\n"
                   " | o o |\n"
                   " |____S|";
            break;
        case SIX_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |6    |\n"
                   " | o o |\n"
                   " | o o |\n"
                   " | o o |\n"
                   " |____9|";
            break;
        case SEVEN_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |7    |\n"
                   " | o o |\n"
                   " |o o o|\n"
                   " | o o |\n"
                   " |____L|";
            break;
        case EIGHT_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |8    |\n"
                   " |o o o|\n"
                   " | o o |\n"
                   " |o o o|\n"
                   " |____8|";
            break;
        case NINE_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |9    |\n"
                   " |o o o|\n"
                   " |o o o|\n"
                   " |o o o|\n"
                   " |____6|";
            break;
        case TEN_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |10 o |\n"
                   " |o o o|\n"
                   " |o o o|\n"
                   " |o o o|\n"
                   " |____0I|";
            break;
        case JACK_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |J  ww|\n"
                   " | /\\{)|\n"
                   " | \\/% |\n"
                   " |   % |\n"
                   " |__%%[|";
            break;
        case QUEEN_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |Q  ww|\n"
                   " | /\\{(|\n"
                   " | \\/%%|\n"
                   " |  %%%|\n"
                   " |_%%%O|";
            break;
        case KING_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |K  WW|\n"
                   " | /\\{)|\n"
                   " | \\/%%|\n"
                   " |  %%%|\n"
                   " |_%%%>|";
            break;
        case ACE_OF_DIAMONDS:
            asciiCard = "  _____ \n"
                   " |A ^  |\n"
                   " | / \\ |\n"
                   " | \\ / |\n"
                   " |  .  |\n"
                   " |____V|";
            break;
        default:
            std::cout << "Error finding diamond ascii";
    }
}

/**
 * Sets the asciiCard variable for cards belonging to the Spade suit
 *
 * @param num the value of the card, determining which graphic it is assigned
 */
void Card::setSpadeAscii(int num) {
    switch(num) {
        case TWO_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |2    |\n"
                   " |  ^  |\n"
                   " |     |\n"
                   " |  ^  |\n"
                   " |____Z|";
            break;
        case THREE_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |3    |\n"
                   " | ^ ^ |\n"
                   " |     |\n"
                   " |  ^  |\n"
                   " |____E|";
            break;
        case FOUR_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |4    |\n"
                   " | ^ ^ |\n"
                   " |     |\n"
                   " | ^ ^ |\n"
                   " |____h|";
            break;
        case FIVE_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |5    |\n"
                   " | ^ ^ |\n"
                   " |  ^  |\n"
                   " | ^ ^ |\n"
                   " |____S|";
            break;
        case SIX_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |6    |\n"
                   " | ^ ^ |\n"
                   " | ^ ^ |\n"
                   " | ^ ^ |\n"
                   " |____9|";
            break;
        case SEVEN_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |7    |\n"
                   " | ^ ^ |\n"
                   " |^ ^ ^|\n"
                   " | ^ ^ |\n"
                   " |____L|";
            break;
        case EIGHT_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |8    |\n"
                   " |^ ^ ^|\n"
                   " | ^ ^ |\n"
                   " |^ ^ ^|\n"
                   " |____8|";
            break;
        case NINE_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |9    |\n"
                   " |^ ^ ^|\n"
                   " |^ ^ ^|\n"
                   " |^ ^ ^|\n"
                   " |____6|";
            break;
        case TEN_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |10 ^ |\n"
                   " |^ ^ ^|\n"
                   " |^ ^ ^|\n"
                   " |^ ^ ^|\n"
                   " |___0I|";
            break;
        case JACK_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |J  ww|\n"
                   " | ^ {)|\n"
                   " |(.)% |\n"
                   " | | % |\n"
                   " |__%%[|";
            break;
        case QUEEN_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |Q  ww|\n"
                   " | ^ {(|\n"
                   " |(.)%%|\n"
                   " | |%%%|\n"
                   " |_%%%O|";
            break;
        case KING_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |K  WW|\n"
                   " | ^ {)|\n"
                   " |(.)%%|\n"
                   " | |%%%|\n"
                   " |_%%%>|";
            break;
        case ACE_OF_SPADES:
            asciiCard = "  _____ \n"
                   " |A .  |\n"
                   " | /.\\ |\n"
                   " |(_._)|\n"
                   " |  |  |\n"
                   " |____V|";
            break;
        default:
            std::cout << "Error finding spade ascii";
    }
}

/**
 * Sets the asciiCard variable for cards belonging to the Club suit
 *
 * @param num the value of the card, determining which graphic it is assigned
 */
void Card::setClubAscii(int num) {
    switch(num) {
        case TWO_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |2    |\n"
                   " |  &  |\n"
                   " |     |\n"
                   " |  &  |\n"
                   " |____Z|";
            break;
        case THREE_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |3    |\n"
                   " | & & |\n"
                   " |     |\n"
                   " |  &  |\n"
                   " |____E|";
        case FOUR_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |4    |\n"
                   " | & & |\n"
                   " |     |\n"
                   " | & & |\n"
                   " |____h|";
            break;
        case FIVE_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |5    |\n"
                   " | & & |\n"
                   " |  &  |\n"
                   " | & & |\n"
                   " |____S|";
            break;
        case SIX_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |6    |\n"
                   " | & & |\n"
                   " | & & |\n"
                   " | & & |\n"
                   " |____9|";
            break;
        case SEVEN_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |7    |\n"
                   " | & & |\n"
                   " |& & &|\n"
                   " | & & |\n"
                   " |____L|";
            break;
        case EIGHT_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |8    |\n"
                   " |& & &|\n"
                   " | & & |\n"
                   " |& & &|\n"
                   " |____8|";
            break;
        case NINE_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |9    |\n"
                   " |& & &|\n"
                   " |& & &|\n"
                   " |& & &|\n"
                   " |____6|";
            break;
        case TEN_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |10 & |\n"
                   " |& & &|\n"
                   " |& & &|\n"
                   " |& & &|\n"
                   " |___0I|";
            break;
        case JACK_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |J  ww|\n"
                   " | o {)|\n"
                   " |o o% |\n"
                   " | | % |\n"
                   " |__%%[|";
            break;
        case QUEEN_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |Q  ww|\n"
                   " | o {(|\n"
                   " |o o%%|\n"
                   " | |%%%|\n"
                   " |_%%%O|";
            break;
        case KING_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |K  WW|\n"
                   " | o {)|\n"
                   " |o o%%|\n"
                   " | |%%%|\n"
                   " |_%%%>|";
            break;
        case ACE_OF_CLUBS:
            asciiCard = "  _____ \n"
                   " |A _  |\n"
                   " | ( ) |\n"
                   " |(_'_)|\n"
                   " |  |  |\n"
                   " |____V|";
            break;
        default:
            std::cout << "Error finding club ascii";
    }
}

/**
 * Sets the asciiCard variable for cards belonging to the Heart suit
 *
 * @param num the value of the card, determining which graphic it is assigned
 */
void Card::setHeartAscii(int num) {
    switch(num) {
        case TWO_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |2    |\n"
                   " |  v  |\n"
                   " |     |\n"
                   " |  v  |\n"
                   " |____Z|";
            break;
        case THREE_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |3    |\n"
                   " | v v |\n"
                   " |     |\n"
                   " |  v  |\n"
                   " |____E|";
            break;
        case FOUR_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |4    |\n"
                   " | v v |\n"
                   " |     |\n"
                   " | v v |\n"
                   " |____h|";
            break;
        case FIVE_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |5    |\n"
                   " | v v |\n"
                   " |  v  |\n"
                   " | v v |\n"
                   " |____S|";
            break;
        case SIX_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |6    |\n"
                   " | v v |\n"
                   " | v v |\n"
                   " | v v |\n"
                   " |____9|";
            break;
        case SEVEN_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |7    |\n"
                   " | v v |\n"
                   " |v v v|\n"
                   " | v v |\n"
                   " |____L|";
            break;
        case EIGHT_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |8    |\n"
                   " |v v v|\n"
                   " | v v |\n"
                   " |v v v|\n"
                   " |____8|";
            break;
        case NINE_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |9    |\n"
                   " |v v v|\n"
                   " |v v v|\n"
                   " |v v v|\n"
                   " |____6|";
            break;
        case TEN_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |10 v |\n"
                   " |v v v|\n"
                   " |v v v|\n"
                   " |v v v|\n"
                   " |___0I|";
            break;
        case JACK_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |J  ww|\n"
                   " |   {)|\n"
                   " |(v)% |\n"
                   " | v % |\n"
                   " |__%%[|";
            break;
        case QUEEN_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |Q  ww|\n"
                   " |   {(|\n"
                   " |(v)%%|\n"
                   " | v%%%|\n"
                   " |_%%%O|";
            break;
        case KING_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |K  WW|\n"
                   " |   {)|\n"
                   " |(v)%%|\n"
                   " | v%%%|\n"
                   " |_%%%>|";
            break;
        case ACE_OF_HEARTS:
            asciiCard = "  _____ \n"
                   " |A_ _ |\n"
                   " |( v )|\n"
                   " | \\ / |\n"
                   " |  .  |\n"
                   " |____V|";
            break;
        default:
            std::cout << "Error finding heart ascii";
    }
}

/**
 * A getter for the asciiCard variable
 *
 * @return
 */
std::string Card::getAscii() const {
    return asciiCard;
}

/**
 * A getter for the name of the suit enum
 *
 * @return a string representation of the cards suit
 */
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


/**
 * A getter for the name of the value enum
 *
 * @return a string representation of the cards value
 */
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
            return "10";
        case QUEEN:
            return "10";
        case KING:
            return "10";
        case ACE:
            return "Ace";
        case enumValueEnd:
            break;
    }
    return "Error finding value";
}

/**
 * Overloading operator `<<` to enable printing of suit and value easily
 *
 * @param output frame of sentence
 * @param card card suit and value
 *
 * @return a string with the value and suit of the card
 */
std::ostream& operator<<(std::ostream& output, const Card& card) {
    std::string suit = card.getSuit();
    std::string value = card.getValue();

    output << value << " of " << suit << "\n";
    return output;
}

/**
 * Overloading operator `==` to enable easy comparison of cards
 *
 * @param card1 a card object
 * @param card2 card to be compared with card1
 *
 * @return true if the cards are the same, else returns false
 */
bool operator==(const Card& card1, const Card& card2)  {
    bool compareValue = false;
    bool compareSuit = false;
    if(card1.getValue() == card2.getValue()) {
        compareValue = true;
    }
    if(card1.getSuit() == card2.getSuit()) {
        compareSuit = true;
    }
    return compareValue == compareSuit;
}