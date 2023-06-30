//
// Created by Anthony Gavriel on 30/06/2023.
//

#include "../include/Player.h"
#include "../include/Card.h"
#include <utility>

Player::Player(std::string name) {
    this -> name = std::move(name);
    handValue = 0;
    playing = true;
}

int Player::ace() {
    std::string choice;
    std::cout << "Would you like the Ace to be a 1 or 11?\n";
    std::cout << "Type '1' or '11' and press enter.\n";
    std::cin >> choice;
    if(choice == "1") {
        return 1;
    } else if(choice == "11") {
        return 11;
    } else {
        ace();
    }
}

int Player::getHandValue() {
    int currentValue = 0;
    for(auto card : hand) {
        if(
                card.getValue() == "JACK" ||
                card.getValue() == "QUEEN" ||
                card.getValue() == "KING"
                ) {
            currentValue += 10;
        } else if(card.getValue() == "ACE") {
            currentValue += ace();
        } else {
            currentValue += std::stoi(card.getValue());
        }
    }
    handValue = currentValue;
    return currentValue;
}

std::string Player::viewCards() {
    std::cout << name + "'s cards:\n";
    for(auto card : hand) {
        std::cout << card;
        std::cout << "\n";
    }
    std::cout << "\n";
}





