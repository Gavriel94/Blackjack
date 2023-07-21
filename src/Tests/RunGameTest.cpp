/**
 * @file RunGameTest.cpp
 * @brief The implementation of the RunGameTest class and its functions.
 * @author Anthony Gavriel
 * @date 07/07/2023
 */

#include "../../include/Tests/RunGameTest.h"

/**
 * @brief Default constructor for RunGameTest.
 */
RunGameTest::RunGameTest() = default;

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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
    assert(runGame.dealer.getBlackjack() == true);

    bool result = runGame.blackjackCheck(player);
    assert(result == true);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::blackjackWin() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::SPADES, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    float currentCash = player.getCash();
    player.makeBet();
    player.receiveCard(king),
    player.receiveCard(ace);

    runGame.players.push_back(player);
    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);

    bool result = runGame.blackjackCheck(player);

    /** Ensures player wins and receives cash */
    assert(player.getBlackjack() == true);
    assert(result == true);
    assert(player.getCash() > currentCash);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::blackjackLoss() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::SPADES, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    float currentCash = player.getCash();
    player.makeBet();
    player.receiveCard(eight);
    player.receiveCard(nine);

    runGame.players.push_back(player);
    runGame.dealer.receiveCard(king);
    runGame.dealer.receiveCard(ace);

    bool result = runGame.blackjackCheck(player);

    /** Ensures dealer wins and player loses cash */
    assert(runGame.dealer.getBlackjack() == true);
    assert(result == true);
    assert(player.getCash() < currentCash);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

    assert(player.getHandValue() == runGame.dealer.getHandValue());
    runGame.calculateTurnResult();
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::valueWin() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);
    Card seven = Card(Card::HEARTS, Card::SEVEN);

    float currentCash = player.getCash();
    player.makeBet();
    player.receiveCard(eight);
    player.receiveCard(nine);

    runGame.players.push_back(player);
    runGame.dealer.receiveCard(seven);
    runGame.dealer.receiveCard(nine);
    runGame.calculateTurnResult();

    /** Ensures player wins and receives cash */
    assert(player.getHandValue() > runGame.dealer.getHandValue());
    assert(runGame.players.at(0).getCash() > currentCash);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

    /** Ensures dealer wins and player loses cash */
    assert(player.getHandValue() < runGame.dealer.getHandValue());
    assert(runGame.players.at(0).getCash() < currentCash);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::bothHaveBlackjack() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card ace = Card(Card::HEARTS, Card::ACE);

    player.receiveCard(king);
    player.receiveCard(ace);
    runGame.players.push_back(player);

    assert(player.getBlackjack() == true);

    runGame.dealer.receiveCard(king);
    runGame.dealer.receiveCard(ace);

    assert(runGame.dealer.getBlackjack() == true);

    runGame.calculateTurnResult();
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::playerHigherValue() {
    Player player = Player("Bob", 0);
    RunGame runGame = RunGame();
    Card king = Card(Card::DIAMONDS, Card::KING);
    Card queen = Card(Card::HEARTS, Card::QUEEN);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card nine = Card(Card::DIAMONDS, Card::NINE);

    player.receiveCard(king);
    player.receiveCard(queen);
    runGame.players.push_back(player);

    assert(player.getHandValue() == 20);

    runGame.dealer.receiveCard(eight);
    runGame.dealer.receiveCard(nine);

    runGame.calculateTurnResult();
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

/**
 * @brief See declaration in RunGameTest.h for details.
 */
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

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::playerTurn() {
    RunGame runGame = RunGame();
    Player player = Player("Bob", 0);

    runGame.playerTurn(player);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::dealerTurn() {
    RunGame runGame = RunGame();

    runGame.dealerTurn();
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::keepPlaying() {
    RunGame runGame = RunGame();

    bool result = runGame.keepPlaying();
    assert(result == true);
}

/**
 * @brief See declaration in RunGameTest.h for details.
 */
void RunGameTest::stopPlaying() {
    RunGame runGame = RunGame();

    bool result = runGame.keepPlaying();
    assert(result == false);
}