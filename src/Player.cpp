//
// Created by Anthony Gavriel on 30/06/2023.
//

#include "../include/Player.h"

Player::Player(std::string name) {
    this -> name = std::move(name);
    handValue = 0;
    playing = true;
    bust = false;
    blackjack = false;
}

void Player::receiveCard(Card card) {
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
        std::cout << "Blackjack!";
        playing = false;
        blackjack = true;
    }
}

int Player::ace() {
    int choice;
    std::cout << "Would you like the Ace to be a 1 or 11?\n";
    std::cout << "Type '1' or '11' and press enter.\n";
    std::cin >> choice;
    switch(choice) {
        case 1:
            return 1;
        case 11:
            return 11;
        default:
            std::cout << "Please select a valid option: (1/11).\n";
            std::cin >> choice;
    }
    return 1;
}

int Player::getHandValue() {
    return handValue;
}

std::vector<Card> Player::getHand() {
    return hand;
}

bool Player::hit() {
    return true;
}

void Player::stick() {
    playing = false;
}

bool Player::isPlaying() {
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
    std::cout << name << "'s cards\n";
    for(auto card: hand) {
        std::cout << card.getValue() << " of " << card.getSuit() << "\n";
    }
}
