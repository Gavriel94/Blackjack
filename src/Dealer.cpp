/**
 * @file Dealer.cpp
 * @brief The implementation of the Dealer class and its functions.
 * @author Anthony Gavriel
 * @date 03/07/2023
 */

#include "../include/Dealer.h"
#include "../include/GameComponents.h"

/**
 * @brief Constructor for Dealer object.
 *
 */
Dealer::Dealer() {
    hand = {};
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
}

/**
 * @brief See declaration in Dealer.h for details
 */
void Dealer::receiveCard(const Card& card) {
    if(card.getValue() == "Ace") {
        if(handValue <= 10) {
            /** Hand is worth <= 10 so Ace is worth 11 */
            handValue += 11;
        } else {
            /** Hand is worth > 10 so Ace is worth 1. */
            handValue += 1;
        }
    } else {
        /** Add value of card to hand. */
        handValue += stoi(card.getValue());
    }

    /**
     * Checks dealers game state.
     */
    hand.push_back(card);
    if(handValue > 21) {
        /** Dealer is getBust. */
        bust = true;
        playing = false;
    } else if(handValue == 21 && hand.size() == 2) {
        /** Dealer has 2 cards which have a value of 21 (must be blackjack). */
        blackjack = true;
        playing = false;
    } else if(handValue >= 17) {
        /** Dealer sticks at 17 or above. */
        playing = false;
    }
}

/**
 * @brief See declaration in Dealer.h for details.
 */
void Dealer::startNewGame() {
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
    hand = {};
}

/**
 * @brief See declaration in Dealer.h for details.
 */
void Dealer::printHand() const{
    std::string line = "*----------------------------------*\n";

    /** Header */
    std::cout << line;
    if(hand.size() == 1) {
        std::cout << "            Dealers Card            \n";
    } else {
        std::cout << "            Dealers Cards           \n";
    }
    std::cout << line;

    /**
     * For each card in their hand:
     * - Use printHandHelper() to get a line of the card.
     * - Append each line to cardLines.
     */
    std::vector<std::vector<std::string>> cardLines;
    cardLines.reserve(hand.size());
    for (const auto &card: hand) {
        cardLines.push_back(GameComponents::printHandHelper(card.getAscii(), '\n'));
    }

    /**
     * - For each line, iterate over ASCII representations in cardLines.
     * - Print the i-th line of the card.
     * - Continue until all lines are completed, resulting in side-by-side cards.
     */
    for(size_t i = 0; i < cardLines[0].size(); ++i) {
        for(const auto& card : cardLines) {
            std::cout << card[i] << " ";
        }
        std::cout << "\n";
    }

    /** Footer */
    std::cout << line;
    std::cout << "          Hand value: " << getHandValue() << "          \n";
    std::cout << line << "\n";
}

/**
 * @brief See declaration in Dealer.h for details.
 */
std::vector<Card> Dealer::getHand() {
    return hand;
}

/**
 * @brief See declaration in Dealer.h for details.
 */
int Dealer::getHandValue() const {
    return handValue;
}

/**
 * @brief See declaration in Dealer.h for details.
 */
bool Dealer::getBlackjack() const {
    return blackjack;
}

/**
 * @brief See declaration in Dealer.h for details.
 */
bool Dealer::getPlaying() const {
    return playing;
}

/**
* @brief See declaration in Dealer.h for details.
*/
bool Dealer::getBust() const {
    return bust;
}