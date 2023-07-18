//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../../include/Tests/PlayerTest.h"

PlayerTest::PlayerTest() = default;

void PlayerTest::aceIsOne() {
    Player player = Player("Bob", 0);

    int value;
    value = player.ace();
    assert(value == 1);
}

void PlayerTest::aceIsEleven() {
    Player player = Player("Bob", 0);

    int value;
    value = player.ace();
    assert(value == 11);
}

void PlayerTest::receiveCard() {
    Player player = Player("Bob", 0);
    Card card = Card(Card::CLUBS, Card::EIGHT);

    player.receiveCard(card);
    assert(player.getHand().at(0) == card);
}

void PlayerTest::getHandValue() {
    Player player = Player("Bob", 0);
    Card card = Card(Card::CLUBS, Card::EIGHT);

    player.receiveCard(card);
    assert(player.getHandValue() == 8);
}



void PlayerTest::getBust() {
    Player player = Player("Bob", 0);

    player.receiveCard(Card(Card::HEARTS, Card::JACK));
    assert(player.getHandValue() == 10);
    player.receiveCard(Card(Card::HEARTS, Card::QUEEN));
    assert(player.getHandValue() == 20);
    player.receiveCard(Card(Card::HEARTS, Card::KING));
    assert(player.getHandValue() == 30);
    assert(player.getBust() == true);
}

void PlayerTest::printHand() {
    Player player = Player("Bob", 0);
    Deck deck = Deck();

    player.receiveCard(deck.removeCard());
    player.receiveCard(deck.removeCard());
    player.printHand();
}

void PlayerTest::makeBet() {
    Player player = Player("Bob", 0);

    player.makeBet();
    assert(player.getBet() != 0);
}

void PlayerTest::blackjackWin() {
    Player player = Player("Bob", 0);

    float currentCash = player.getCash();
    player.makeBet();

    player.receiveCard(Card(Card::SPADES, Card::KING));
    player.receiveCard(Card(Card::HEARTS, Card::ACE));

    assert(player.getBlackjack() == true);
    float winnings = player.getBet() + (player.getBet() * 1.5);
    player.win();
    assert(player.getCash() == currentCash + winnings);
}

void PlayerTest::standardWin() {
    Player player = Player("Bob", 0);

    float currentCash = player.getCash();

    player.makeBet();

    player.receiveCard(Card(Card::HEARTS, Card::KING));
    player.receiveCard(Card(Card::HEARTS, Card::QUEEN));

    float winnings = player.getBet() + player.getBet();
    player.win();
    assert(player.getCash() == currentCash + winnings);
}

void PlayerTest::hit() {
    Player player = Player("Bob", 0);

    player.hitOrStick();
    assert(player.getPlaying() == true);
}

void PlayerTest::stick() {
    Player player = Player("Bob", 0);

    player.hitOrStick();
    assert(player.getPlaying() == false);
}

void PlayerTest::comparePlayers() {
    Player player = Player("Bob", 0);
    Player playerClone = player;

    assert(player == playerClone);

    Player playerThree = Player("Alice", 1);
    assert(player != playerThree);
}