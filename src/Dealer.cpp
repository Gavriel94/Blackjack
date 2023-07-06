//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/Dealer.h"
#include "../include/GameComponents.h"

/**
 * Constructor for Dealer objects
 */
Dealer::Dealer() {
    hand = {};
    bust = false;
    handValue = 0;
    playing = true;
    blackjack = false;
}

/**
 * A getter for the bust variable
 *
 * @return a bool saying if the dealer is bust or not
 */
bool Dealer::getBust() const {
    return bust;
}

/**
 * A getter for the hand variable
 *
 * @return a vector of Card objects where each is an element of the hand in the current game
 */
std::vector<Card> Dealer::getHand() {
    return hand;
}

/**
 * Adds a new Card to the dealers hand
 * Follows the same rules as a dealer in a casino:
 * - if the dealer hand is worth less than 10 and they receive an Ace, the value added is 11
 * - if the dealer hand is worth more than 10 and they receive an Ace, the value added is 1
 * - if the dealer hand is 17 or more they stick
 *
 * @param card the card the dealer is receiving
 */
void Dealer::receiveCard(const Card& card) {
    handRepresentation.push_back(card.getAscii());
    if(card.getValue() == "Ace") {
        if(handValue <= 10) {
            // hand is worth <= 10 so Ace is worth 11
            handValue += 11;
        } else {
            handValue += 1;
        }
    } else {
        handValue += stoi(card.getValue());
    }
    hand.push_back(card);
    if(handValue > 21) {
        bust = true;
        playing = false;
    } else if(handValue == 21 && hand.size() == 2) {
        blackjack = true;
        playing = false;
    } else if(handValue >= 17) {
        // stick at 17 or above
        playing = false;
    }
}

/**
 * A getter for the handValue variable
 *
 * @return an int with the cumulative value of each card in the dealers hand
 */
int Dealer::getHandValue() const {
    return handValue;
}

/**
 * A getter for the blackjack variable
 *
 * @return a bool to inform the game loop if the dealer has blackjack
 */
bool Dealer::getBlackjack() const {
    return blackjack;
}

/**
 * A getter for the playing variable
 *
 * @return a bool to inform the game loop if the dealer is still playing
 */
bool Dealer::getPlaying() const {
    return playing;
}

/**
 * Produces a header informing the user the following cards belong to the dealer
 * before printing the ASCII representations of their hand in a row
 *
 * - Saves ASCII representations by:
 *      - going through each card in the dealers hand
 *      - calling printHandHelper() to get a vector of lines in that card
 *      - appending each line of each card to cardLines
 * - Printing by:
 *      - iterating over the indices of the lines
 *      - for each line, iterates over asciiCard representations in cardLines
 *      - prints the i-th line of each card
 *      - continues until all lines are completed, resulting in side-by-side cards
 *
 * Produces a footer informing the user the total value of the hand
 */
void Dealer::printHand() const{
    std::string line = "*----------------------------------*\n";

    std::cout << line;
    if(hand.size() == 1) {
        std::cout << "            Dealers Card            \n";
    } else {
        std::cout << "            Dealers Cards           \n";
    }
    std::cout << line;

    std::vector<std::vector<std::string>> cardLines;
    cardLines.reserve(hand.size());
    for (const auto &card: hand) {
        cardLines.push_back(GameComponents::printHandHelper(card.getAscii(), '\n'));
    }

    for(size_t i = 0; i < cardLines[0].size(); ++i) {
        for(const auto& card : cardLines) {
            std::cout << card[i] << " ";
        }
        std::cout << "\n";
    }
    std::cout << line;
    std::cout << "        Hand value: " << getHandValue() << "          \n";
    std::cout << line << "\n";
}

void Dealer::startNewGame() {
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
    hand = {};
}
