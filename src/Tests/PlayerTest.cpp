//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../../include/Tests/PlayerTest.h"

PlayerTest::PlayerTest() = default;

void PlayerTest::ace() {
    Player player = Player("Bob", 1);

    int value;
    std::cout << "\n";
    std::cout << "assert(value == 1)\n";
    value = player.ace();
    assert(value == 1);
    std::cout << "\n";
    std::cout << "assert(value == 11)\n";
    value = player.ace();
    assert(value == 11);
    std::cout << "\n";
}

void PlayerTest::receiveCard() {
    Player player = Player("Bob", 1);

    Card ace = Card(Card::SPADES, Card::ACE);
    Card king = Card(Card::HEARTS, Card::KING);

    std::vector<Card> testHand = {ace};

    std::cout << "\n";
    std::cout << "Testing for blackjack\n";
    std::cout << "assert(value == 11)\n";
    player.receiveCard(ace);
    std::cout << "\n";

    assert(player.getHand() == testHand);

    testHand.push_back(king);
    std::cout << "\n";
    player.receiveCard(king);
    std::cout << "\n";
    assert(player.getHand() == testHand);
    assert(player.getBlackjack() == true);
    assert(player.getPlaying() == false);
    assert(player.getHandValue() == 21);

    testHand.clear();

    player = Player("Alice", 1);

    Card seven = Card(Card::CLUBS, Card::SEVEN);
    player.receiveCard(seven);
    assert(player.getPlaying() == true);
    assert(player.getHandValue() == 7);
    std::cout << "\n";
}

void PlayerTest::getBust() {
    Player player = Player("Bob", 1);

    player.receiveCard(Card(Card::HEARTS, Card::JACK));
    assert(player.getHandValue() == 10);
    player.receiveCard(Card(Card::HEARTS, Card::QUEEN));
    assert(player.getHandValue() == 20);
    player.receiveCard(Card(Card::HEARTS, Card::KING));
    assert(player.getHandValue() == 30);
    assert(player.getPlaying() == false);
    assert(player.getBust() == true);
}

/**
 * Visual test, ensure the cards print correctly
 */
void PlayerTest::printHand() {
    Player player = Player("Bob", 0);

    player.receiveCard(Card(Card::HEARTS, Card::JACK));
    player.receiveCard(Card(Card::SPADES, Card::SEVEN));

    player.printHand();
}

void PlayerTest::makeBet() {
    Player player = Player("Bob", 0);

    player.makeBet();

    assert(player.getBet() != 0);
}

void PlayerTest::receiveWinnings() {
    Player player = Player("Bob", 0);
    float currentCash = player.getCash();

    player.makeBet();
    assert(player.getBet() != 0);

    std::cout << "assert(player.getBlackjack() == true)\n";
    player.receiveCard(Card(Card::SPADES, Card::KING));
    player.receiveCard(Card(Card::HEARTS, Card::ACE));

    assert(player.getBlackjack() == true);
    float winnings = player.getBet() + (player.getBet() * 1.5);
    player.receiveWinnings();
    assert(player.getCash() == currentCash + winnings);

    player = Player("Bob", 0);
    currentCash = player.getCash();

    player.makeBet();
    assert(player.getBet() != 0);

    player.receiveCard(Card(Card::HEARTS, Card::KING));
    player.receiveCard(Card(Card::HEARTS, Card::QUEEN));

    assert(player.getBlackjack() != true);
    winnings = player.getBet()*2;
    player.receiveWinnings();
    assert(player.getCash() == currentCash + winnings);
}

void PlayerTest::hitOrStick() {
    Player player = Player("Bob", 0);

    std::cout << "Assert checking for `hit`\n";
    player.hitOrStick();
    assert(player.getPlaying() == true);

    std::cout << "\nAssert checking for `stick`\n";
    player = Player("Bob", 0);
    player.hitOrStick();
    assert(player.getPlaying() == false);
}