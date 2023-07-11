//
// Created by Anthony Gavriel on 07/07/2023.
//

#include "../../include/Tests/RunGameTest.h"

RunGameTest::RunGameTest() = default;
void RunGameTest::gameLoop() {
    RunGame runGame = RunGame();
    runGame.initialiseGame();

    std::cout << "Assert checking for true\n";
    bool choice = runGame.gameLoop();
    assert(choice == true);

    std::cout << "Assert checking for false\n";
    choice = runGame.gameLoop();
    assert(choice == false);
}

void RunGameTest::blackjackCheck() {
    RunGame runGame = RunGame();
    Player player = Player("Bob", 0);

    std::cout << "Assert checking for tie\n";
    player.receiveCard(Card(Card::CLUBS, Card::KING));
    player.receiveCard(Card(Card::SPADES, Card::ACE));

    runGame.dealer.receiveCard(Card(Card::HEARTS, Card::ACE));
    runGame.dealer.receiveCard(Card(Card::HEARTS, Card::KING));

    bool result = runGame.blackjackCheck(player);

    assert(result == false);

    runGame = RunGame();
    player = Player("Bob", 0);
    std::cout << "Assert checking player loses\n";
    player.receiveCard(Card(Card::CLUBS, Card::KING));
    player.receiveCard(Card(Card::SPADES, Card::SEVEN));

    runGame.dealer.receiveCard(Card(Card::HEARTS, Card::ACE));
    runGame.dealer.receiveCard(Card(Card::HEARTS, Card::KING));

    result = runGame.blackjackCheck(player);
    assert(result == true);

    runGame = RunGame();
    player = Player("Bob", 0);
    std::cout << "Assert checking player wins\n";
    player.receiveCard(Card(Card::HEARTS, Card::ACE));
    player.receiveCard(Card(Card::HEARTS, Card::KING));

    runGame.dealer.receiveCard(Card(Card::SPADES, Card::SEVEN));
    runGame.dealer.receiveCard(Card(Card::CLUBS, Card::KING));

    result = runGame.blackjackCheck(player);
    assert(result == true);
}
