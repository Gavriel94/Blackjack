//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/Dealer.h"

Dealer::Dealer() {
    hand = {};
    bust = false;
    handValue = 0;
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
        std::cout << "Dealer bust with " << handValue << "!\n";
        bust = true;
        playing = false;
    } else if(handValue == 21 && hand.size() == 2) {
        std::cout << "Blackjack!\n";
        playing = false;
        blackjack = true;
    } else if(handValue >= 17) {
        std::cout << "Dealer sticks at " << handValue << "\n";
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
    for(auto card: hand) {
        std::cout << "Dealers cards\n";
        std::cout << card.getValue() << " of " << card.getSuit() << "\n";
    }
}

