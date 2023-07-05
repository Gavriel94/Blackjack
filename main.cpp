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
    } else if(testClass == "GameComponents") {
      unitTest.gameComponentsTests();
    } else if(testClass == "All") {
        unitTest.allTests();
    } else {
        std::cout << "\n\nInvalid Argument \"" << testClass << "\"\n\n";
        std::cout << "Options for tests are:\n";
        std::cout << "- \"Card\"\n";
        std::cout << "- \"Dealer\"\n";
        std::cout << "- \"Deck\"\n";
        std::cout << "- \"Player\"\n";
        std::cout << "\"GameComponents\"\n\n";
        std::cout << "Program terminating. Please try again.";
    }
}

/**
 * Increases readability
 */
void lineBreak() {
    std::cout << "\n";
}

void runGame() {
    GameComponents game = GameComponents();
    Deck deck = game.setupDeck();
    Dealer dealer = game.setupDealer();

    game.gameIntro();
    lineBreak();

    std::vector<Player> players = game.setupPlayers();
    std::cout << "Seated at the table we have:\n\n";
    for(auto player : players) {
        std::cout << "- " << player.getName() << "\n";
    }
    lineBreak();

    dealer.startGame(deck, players);


    dealer.printHand();
    lineBreak();

    for(auto& player: players) {
        while(player.getPlaying()) {
            player.printHand();
            bool hit = player.hitOrStick();
            if(hit) {
                Card card = deck.removeCard();
                player.receiveCard(card);
                player.printHand();
                if(player.isBust()) {
                    std::cout << game.getBustGraphic();
                }
                if(player.getBlackjack()) {
                    std::cout << game.getBlackjackGraphic();
                    break;
                }
            } else {
                player.stick();
                player.printHand();
            }
        }
    }

    while(dealer.getPlaying()) {
        Card card = deck.removeCard();
        dealer.receiveCard(card);
        dealer.printHand();
        if(dealer.getBust()) {
            std::cout << game.getBustGraphic();
        }
        if(dealer.getBlackjack()) {
            std::cout << game.getBlackjackGraphic();
            break;
        }
    }

    // all hands played, now tally up scores

    for(auto& player: players) {
        std::cout << player.getName() << " has " << player.getHandValue() << "\n";
    }
    std::cout << "Dealer has " << dealer.getHandValue() << "\n";
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


