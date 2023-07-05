//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/Dealer.h"
#include "../include/GameComponents.h"

Dealer::Dealer() {
    hand = {};
    bust = false;
    handValue = 0;
    playing = true;
    blackjack = false;
}

void Dealer::startGame(Deck &deck, std::vector<Player> &players) {
    Card firstCard = deck.removeCard();
    receiveCard(firstCard);

    for(auto &player: players) {
        Card card1 = deck.removeCard();
        Card card2 = deck.removeCard();
        // Each player starts with 2 cards
        player.receiveCard(card1);
        player.receiveCard(card2);
    }
}

bool Dealer::getBust() {
    return bust;
}

std::vector<Card> Dealer::getHand() {
    return hand;
}

void Dealer::receiveCard(Card card) {
    handRepresentation.push_back(card.getAscii());
    int value = 0;
    if(card.getValue() == "Ace") {
        if(handValue <= 10) {
            value += 11;
        } else {
            value += 1;
        }
    } else {
        value += stoi(card.getValue());
    }
    hand.push_back(card);
    handValue += value;
    if(handValue > 21) {
        bust = true;
        playing = false;
    } else if(handValue == 21 && hand.size() == 2) {
        blackjack = true;
        playing = false;
    } else if(handValue >= 17) {
        playing = false;
    }
}

int Dealer::getHandValue() {
    return handValue;
}

bool Dealer::getBlackjack() {
    return blackjack;
}

bool Dealer::getPlaying() {
    return playing;
}

void Dealer::printHand() {
    std::string line = "*----------------------------------*\n";

    std::cout << line;
    if(hand.size() == 1) {
        std::cout << "            Dealers Card            \n";
    } else {
        std::cout << "            Dealers Cards           \n";
    };
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
    std::cout << "        Hand value: " << getHandValue() << "          \n";
    std::cout << line;
}
