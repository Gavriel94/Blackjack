//
// Created by Anthony Gavriel on 30/06/2023.
//

#include "../include/Player.h"
#include "../include/GameComponents.h"

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

void Player::receiveCard(const Card& card) {
    handRepresentation.push_back(card.getAscii());
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

int Player::ace() {
    int choice = 0;
    while(choice != 1 && choice != 11) {
        std::cout << name << ", would you like the Ace to be a 1 or 11?\n";
        std::cout << "Type '1' or '11' and press enter.\n";
        std::cin >> choice;
        std::cout << "\n";
        if(std::cin.fail()) {
            std::cin.clear(); // clear fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int Player::getHandValue() const {
    return handValue;
}

std::vector<Card> Player::getHand() {
    return hand;
}

bool Player::hitOrStick() {
    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << name << ", hit or stick?\n";
        std::cout << "Type 1 for hit or 2 for stick and press enter:\n";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear(); // clear fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(choice < 1 || choice > 2) {
            std::cout << "Invalid input.\n"
                         "Press 1 for hit or 2 for stick:\n\n";
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

bool Player::getPlaying() const {
    return playing;
}

bool Player::getBust() const {
    return bust;
}

std::string Player::getName() const {
    return name;
}

bool Player::getBlackjack() const {
    return blackjack;
}

void Player::printHand() const {
    std::string line = "*----------------------------------*\n";



    std::cout << line;
    std::cout << "           " << name << "'s  Cards          \n";
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
    std::cout << "          Hand value: " << getHandValue() << "          \n";
    std::cout << line << "\n";
}


void Player::stick() {
    std::string line = "*----------------------------------*\n";

    std::cout << line;
    std::cout << "           " << name << " sticks with " << handValue << "             \n";
    std::cout << line;
}

void Player::startNewGame() {
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
    hand = {};
}

size_t Player::getHandSize() const {
    return hand.size();
}

float Player::getCash() const {
    return cash;
}

float Player::getBet() const {
    return bet;
}

void Player::makeBet() {
    bet = 0;
    while(bet < 5 || bet > cash) {
        std::cout << name << "'s current cash: $" << cash << "\n";
        std::cout << "Min bet: $5\n";
        std::cout << "Enter your bet, (you can enter whole numbers or decimals):\n$";
        std::cin >> bet;
        if(std::cin.fail()) {
            std::cin.clear(); // clear fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int Player::getPlayerID() const {
    return playerID;
}
bool operator==(const Player& player1, const Player& player2)  {
    return player1.getPlayerID() == player2.getPlayerID();
}

void Player::receiveWinnings() {
    std::cout << "\n";
    if(blackjack) {
        // player wins bet back plus 1.5 times the amount
        float betPlusBlackjackWin = bet + (1.5 * bet);
        cash += betPlusBlackjackWin;

        std::cout << name << " receives $" << betPlusBlackjackWin << "\n";
        std::cout << name << "'s cash $" << cash << "\n\n";
    } else {
        // player wins bet back plus the same amount
        float betPlusWin = bet + bet;
        cash += betPlusWin;
        std::cout << name << " receives $" << betPlusWin << "\n";
        std::cout << "Current cash $" << cash << "\n\n";
    }
}

void Player::loseBet() {
    cash -= bet;
}