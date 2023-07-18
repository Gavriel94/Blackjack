//
// Created by Anthony Gavriel on 07/07/2023.
//

#include "../../include/Tests/RunGameTest.h"

RunGameTest::RunGameTest() = default;

void RunGameTest::blackjackTie() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::SPADES, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);

    player.receiveCard(king);
    player.receiveCard(ace);
    assert(player.getBlackjack() == true);
    runGame.players.push_back(player);
    runGame.dealer.receiveCard(king);
    runGame.dealer.receiveCard(ace);
    bool result = runGame.blackjackCheck(player);
    assert(result == true);
}

void RunGameTest::blackjackWin() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::SPADES, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.makeBet();
    float currentCash = player.getCash();
    player.receiveCard(king),
    player.receiveCard(ace);
    runGame.players.push_back(player);
    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);
    bool result = runGame.blackjackCheck(player);

    assert(player.getBlackjack() == true);
    assert(result == true);
    assert(player.getCash() > currentCash);
}

void RunGameTest::blackjackLoss() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::SPADES, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.makeBet();
    float currentCash = player.getCash();
    player.receiveCard(eight);
    player.receiveCard(nine);
    runGame.players.push_back(player);
    runGame.dealer.receiveCard(king);
    runGame.dealer.receiveCard(ace);
    bool result = runGame.blackjackCheck(player);

    assert(runGame.dealer.getBlackjack() == true);
    assert(result == true);
    assert(player.getCash() < currentCash);
}

void RunGameTest::valueTie() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(eight);
    player.receiveCard(nine);
    runGame.players.push_back(player);
    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);
    runGame.calculateTurnResult();

    assert(player.getHandValue() == runGame.dealer.getHandValue());
}

void RunGameTest::valueWin() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);
    Card seven = Card(Card::HEARTS, Card::SEVEN);

    player.makeBet();
    float currentCash = player.getCash();
    player.receiveCard(eight);
    player.receiveCard(nine);
    runGame.players.push_back(player);
    runGame.dealer.receiveCard(seven);
    runGame.dealer.receiveCard(nine);
    runGame.calculateTurnResult();

    assert(player.getHandValue() > runGame.dealer.getHandValue());
    assert(runGame.players.at(0).getCash() > currentCash);
}

void RunGameTest::valueLoss() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);
    Card seven = Card(Card::HEARTS, Card::SEVEN);

    player.makeBet();
    float currentCash = player.getCash();
    player.receiveCard(seven);
    player.receiveCard(nine);
    runGame.players.push_back(player);
    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);
    runGame.calculateTurnResult();

    assert(player.getHandValue() < runGame.dealer.getHandValue());
    assert(runGame.players.at(0).getCash() < currentCash);
}

void RunGameTest::playerIsBust() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);
    Card seven = Card(Card::HEARTS, Card::SEVEN);

    player.receiveCard(eight),
    player.receiveCard(nine);
    player.receiveCard(seven);
    runGame.players.push_back(player);
    assert(player.getBust() == true);

    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);

    runGame.calculateTurnResult();
}

void RunGameTest::dealerIsBust() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();

    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);
    Card seven = Card(Card::HEARTS, Card::SEVEN);

    player.receiveCard(eight);
    player.receiveCard(nine);
    runGame.players.push_back(player);

    runGame.dealer.receiveCard(seven);
    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);
    assert(runGame.dealer.getBust() == true);

    runGame.calculateTurnResult();
}

void RunGameTest::playerHasBlackjack() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(king);
    player.receiveCard(ace);
    runGame.players.push_back(player);
    assert(player.getBlackjack() == true);

    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);

    runGame.calculateTurnResult();
}

void RunGameTest::dealerHasBlackjack() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(king);
    player.receiveCard(nine);
    runGame.players.push_back(player);

    runGame.dealer.receiveCard(ace);
    runGame.dealer.receiveCard(king);
    assert(runGame.dealer.getBlackjack() == true);

    runGame.calculateTurnResult();
}

void RunGameTest::bothHaveBlackjack() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);

    player.receiveCard(king);
    player.receiveCard(ace);
    assert(player.getBlackjack() == true);
    runGame.players.push_back(player);

    runGame.dealer.receiveCard(king);
    runGame.dealer.receiveCard(ace);
    assert(runGame.dealer.getBlackjack() == true);

    runGame.calculateTurnResult();
}

void RunGameTest::playerHigherValue() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card queen = Card(Card::HEARTS, Card::QUEEN);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(king);
    player.receiveCard(queen);
    assert(player.getHandValue() == 20);
    runGame.players.push_back(player);

    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);

    runGame.calculateTurnResult();
}

void RunGameTest::dealerHigherValue() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card queen = Card(Card::HEARTS, Card::QUEEN);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(eight);
    player.receiveCard(nine);
    runGame.players.push_back(player);

    runGame.dealer.receiveCard(king);
    runGame.dealer.receiveCard(queen);

    runGame.calculateTurnResult();
}

void RunGameTest::bothSameValue() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(eight);
    player.receiveCard(nine);
    runGame.players.push_back(player);

    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);

    runGame.calculateTurnResult();
}

void RunGameTest::playerTurn() {
    RunGame runGame = RunGame();
    Player player = Player("Bob", 0);

    runGame.playerTurn(player);
}

void RunGameTest::dealerTurn() {
    RunGame runGame = RunGame();

    runGame.dealerTurn();
}

void RunGameTest::keepPlaying() {
    RunGame runGame = RunGame();

    bool result = runGame.keepPlaying();
    assert(result == true);
}

void RunGameTest::stopPlaying() {
    RunGame runGame = RunGame();

    bool result = runGame.keepPlaying();
    assert(result == false);
}