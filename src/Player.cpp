/**
 * @file Player.cpp
 * @brief The implementation of the Player class and its functions.
 * @author Anthony Gavriel
 * @date 30/06/2023
 */

#include "../include/Player.h"
#include "../include/GameComponents.h"

/**
 * @brief See declaration in Player.h for details.
 */
Player::Player(std::string name, int playerID) {
    this->playerID = playerID;
    this->name = std::move(name);
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
    cash = 50;
    bet = 0;
}

/**
 * @brief See declaration in Player.h for details.
 */
void Player::receiveCard(const Card& card) {
    if(card.getValue() == "Ace") {
        handValue += ace();
    } else {
        handValue += stoi(card.getValue());
    }
    hand.push_back(card);
    if(handValue > 21) {
        bust = true;
        playing = false;
    }
    if(handValue == 21 && hand.size() == 2) {
        playing = false;
        blackjack = true;
    }
}

/**
 * @brief See declaration in Player.h for details.
 */
bool Player::hitOrStick() {
    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << name << ", hit or getStick?\n";
        std::cout << "Type 1 for hit or 2 for getStick and press enter:\n";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear the fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
        } else if(choice < 1 || choice > 2) {
            std::cout << "Invalid input.\n"
                         "Press 1 for hit or 2 for getStick:\n\n";
        } else {
            break;
        }
    }
    switch(choice) {
        case 1:
            return true;
        case 2:
            playing = false;
            return playing;
    }

    return false;
}

/**
 * @brief See declaration in Player.h for details.
 */
void Player::makeBet() {
    bet = 0;
    while(bet < 5 || bet > cash) {
        std::cout << name << "'s current cash: $" << cash << "\n";
        std::cout << "Min bet: $5\n";
        std::cout << "Enter your bet, (you can enter whole numbers or decimals):\n$";
        std::cin >> bet;
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear the fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
        } else if(bet < 5) {
            std::cout << "\nBet was too low. It must be at least $5.\n\n";
        } else if(bet > cash) {
            std::cout << "\nYou don't have that much cash!\n"
                         "You bet $" << bet << " but have $" << cash << "\n\n";
        } else {
            break;
        }
    }
    std::cout << "\n";
}

/**
 * @brief See declaration in Player.h for details.
 */
void Player::startNewGame() {
    hand = {};
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
}

/**
 * @brief See declaration in Player.h for details.
 */
void Player::printHand() const {
    std::string line = "*----------------------------------*\n";

    /** Header */
    std::cout << line;
    std::cout << "           " << name << "'s  Cards          \n";
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
    std::cout << "      "<< name << "'s hand value: " << getHandValue() << "       \n";
    std::cout << line << "\n";
}

/**
 * @brief See declaration in Player.h for details.
 */
void Player::win() {
    std::cout << "\n";
    float betPlusWin;
    if(blackjack) {
        /** Player wins back bet plus 1.5 * bet */
        betPlusWin = bet + (1.5 * bet);
    } else {
        /** Player wins back bet, plus the same amount */
        betPlusWin = bet + bet;
    }
    cash += betPlusWin;
    std::cout << name << " receives $" << betPlusWin << "\n";
    std::cout << "Current cash: $" << cash << "\n\n";

}

/**
 * @brief See declaration in Player.h for details.
 */
void Player::lose() {
    cash -= bet;
}

/**
 * @brief See declaration in Player.h for details.
 */
int Player::ace() {
    int choice = 0;
    while(choice != 1 && choice != 11) {
        std::cout << name << ", would you like the Ace to be a 1 or 11?\n";
        std::cout << "Type '1' or '11' and press enter.\n";
        std::cin >> choice;
        std::cout << "\n";
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear the fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
        } else if(choice != 1 && choice != 11) {
            std::cout << "Invalid input.\n"
                         "Type '1' or '11' and press enter.\n\n";
        }
    }
    switch(choice) {
        case 1:
            return 1;
        case 11:
            return 11;
    }
    return 1;
}

/**
 * @brief See declaration in Player.h for details.
 */
bool operator==(const Player& player1, const Player& player2)  {
    return player1.playerID == player2.playerID;
}

/**
 * @brief See declaration in Player.h for details.
 */
std::string Player::getName() const {
    return name;
}

/**
 * @brief See declaration in Player.h for details.
 */
std::vector<Card> Player::getHand() {
    return hand;
}

/**
 * @brief See declaration in Player.h for details.
 */
int Player::getHandValue() const {
    return handValue;
}

/**
 * @brief See declaration in Player.h for details.
 */
bool Player::getPlaying() const {
    return playing;
}

bool Player::getBust() const {
    return bust;
}

/**
 * @brief See declaration in Player.h for details.
 */
bool Player::getBlackjack() const {
    return blackjack;
}

/**
 * @brief See declaration in Player.h for details.
 */
float Player::getCash() const {
    return cash;
}

/**
 * @brief See declaration in Player.h for details.
 */
float Player::getBet() const {
    return bet;
}