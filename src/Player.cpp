//
// Created by Anthony Gavriel on 30/06/2023.
//

#include "../include/Player.h"
#include "../include/GameComponents.h"

Player::Player(std::string name) {
    this -> name = std::move(name);
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
}

void Player::receiveCard(Card card) {
    handRepresentation.push_back(card.getAscii());
    int value = 0;
    if(card.getValue() == "Ace") {
        value = ace();
    } else {
        value = stoi(card.getValue());
    }
    hand.push_back(card);
    handValue += value;
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

int Player::getHandValue() {
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
            return false;
    }

    return false;
}

bool Player::getPlaying() {
    return playing;
}

bool Player::isBust() {
    return bust;
}

std::string Player::getName() {
    return name;
}

bool Player::getBlackjack() {
    return blackjack;
}

void Player::printHand() {
    std::string line = "*----------------------------------*\n";

    std::cout << line;
    std::cout << "           " << name << "'s  Cards          \n";
    std::cout << line;

    GameComponents gameComponents = GameComponents();

    std::vector<std::vector<std::string>> cardLines;
    for (const auto &card: hand) {
        cardLines.push_back(gameComponents.printHandHelper(card.getAscii(), '\n'));
    }

    for(size_t i = 0; i < cardLines[0].size(); ++i) {
        for(const auto& card : cardLines) {
            std::cout << card[i] << " ";
        }
        std::cout << "\n";
    }

    std::cout << line;
    std::cout << "          Hand value: " << getHandValue() << "          \n";
    std::cout << line;
}

void Player::stick() {
    std::string line = "*----------------------------------*\n";

    std::cout << line;
    std::cout << "           " << name << " sticks with " << handValue << "             \n";
    std::cout << line;
}
