#include "include/Card.h"
#include "include/Deck.h"
#include "include/Player.h"
#include "include/Dealer.h"
#include "Tests/UnitTests.cpp"
#include "include/GameComponents.h"

void runTests(const std::string& testClass) {
    UnitTest unitTest = UnitTest();

    if(testClass == "Card") {
        unitTest.cardTests();
    } else if(testClass == "Dealer") {
        unitTest.dealerTests();
    } else if(testClass == "Deck") {
        unitTest.deckTests();
    } else if(testClass == "Player") {
        unitTest.playerTests();
    } else if(testClass == "All") {
        unitTest.allTests();
    } else {
        std::cout << "\n\nInvalid Argument " << testClass << "\n";
        std::cout << "Options for tests are:\n";
        std::cout << "- \"Card\"\n";
        std::cout << "- \"Dealer\"\n";
        std::cout << "- \"Deck\"\n";
        std::cout << "- \"Player\"\n\n";
        std::cout << "Program terminating. Please try again.";
    }
}

void runGame() {

    GameComponents game = GameComponents();
    std::vector<Player> players = game.setupPlayers();
    Deck deck = game.setupDeck();
    Dealer dealer = game.setupDealer();

    game.gameIntro();



}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        runTests(std::string(argv[1]));
    }
    else {
        runGame();
    }

    return 0;
}


