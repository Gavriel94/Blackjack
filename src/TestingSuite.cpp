//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../include/TestingSuite.h"

TestingSuite::TestingSuite() {
    lineDecorator = "*----------------------------------*\n";
}

bool TestingSuite::testMenu() {
    int choice = 0;
    while(choice < 1 || choice > 7) {
        std::cout << "You can test the following classes by typing in their corresponding number:\n\n";
        std::cout << "1 - Card Class\n";
        std::cout << "2 - Deck Class\n";
        std::cout << "3 - Player Class\n";
        std::cout << "4 - Dealer Class\n";
        std::cout << "5 - GameComponents Class\n";
        std::cout << "6 - Test all classes\n";
        std::cout << "7 - Exit test mode\n";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(choice < 1 || choice > 7) {
            std::cout << "Invalid input.\n\n";
        } else {
            break;
        }
    }

    switch(choice) {
        case 1:
            cardTests();
            return true;
        case 2:
            deckTests();
            return true;
        case 3:
            playerTests();
            return true;
        case 4:
            dealerTests();
            return true;
        case 5:
            gameComponentsTests();
            return true;
        case 6:
            allTests();
            return true;
        case 7:
            return false;
    }
    return false;
}

void TestingSuite::testHost() {
    std::cout << lineDecorator;
    std::cout << "   Welcome to the Testing Suite\n";
    std::cout << lineDecorator;
    std::cout << "\n";

    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << "\n";
        std::cout << "Type 1 to see the test menu or 2 to exit test mode:\n";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear(); // clear fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(choice < 1 || choice > 2) {
            std::cout << "Invalid input.\n"
                         "Type 1 to see the test menu or 2 to exit test mode:\n\n";
        } else {
            break;
        }
    }
    if(choice == 1) {
        bool testingMode = true;
        while(testingMode) {
            testingMode = testMenu();
        }
    }
    std::cout << "\nHave a nice day!\n";
}

void TestingSuite::cardTests() {
    std::string className = "Card";
    classTestHeader(className);
    callClassTest([&]() { CardTest::getSuit(); }, "getSuit()");
    callClassTest([&]() { CardTest::getValue(); }, "getValue()");
    classTestFooter(className);
}

void TestingSuite::deckTests() {
    std::string className = "Deck";
    classTestHeader(className);
    callClassTest([&]() { DeckTest::create(); }, "createDeck()");
    callClassTest([&]() { DeckTest::shuffle(); }, "shuffleDeck()");
    callClassTest([&]() { DeckTest::removeCard(); }, "removeCard()");
    classTestFooter(className);
}

void TestingSuite::playerTests() {
    std::string  className = "Player";
    classTestHeader(className);

    callClassTest([&]() { PlayerTest::getName(); }, "getName()");
    callClassTest([&]() { PlayerTest::ace(); }, "ace()");
    callClassTest([&]() { PlayerTest::receiveCard(); }, "receiveCard()");
    callClassTest([&]() { PlayerTest::isBust(); }, "isBust()");

    classTestFooter(className);
}

void TestingSuite::dealerTests() {
    std::string className = "Dealer";
    classTestHeader(className);

    callClassTest([&]() { DealerTest::startGame(); }, "startGame()");
    callClassTest([&]() { DealerTest::receiveCard(); }, "receiveCard()");
    callClassTest([&]() { DealerTest::handValue(); }, "getHandValue()");
    callClassTest([&]() { DealerTest::blackjack(); }, "blackjack()");
    callClassTest([&]() { DealerTest::bust(); }, "testBust()");
    callClassTest([&]() { DealerTest::stick(); }, "testStick()");

    classTestFooter(className);
}

void TestingSuite::gameComponentsTests() {
    std::string className = "Components";
    classTestHeader(className);

    callClassTest([&]() { GameComponentsTest::setupPlayers(); }, "getPlayers()");
    callClassTest([&]() { GameComponentsTest::setupDeck(); }, "setupDeck()");
    callClassTest([&]() { GameComponentsTest::setupDealer(); }, "setupDealer()");
    callClassTest([&]() { GameComponentsTest::printHandHelper(); }, "printHandHelper()");

    classTestFooter(className);
}

void TestingSuite::allTests() {
    cardTests();
    deckTests();
    playerTests();
    dealerTests();
    gameComponentsTests();
}

void TestingSuite::callClassTest(const std::function<void()>& test, const std::string& testName) {
    test();
    std::cout << "        " << testName << " passed   \n";
    std::cout << lineDecorator;
}

void TestingSuite::classTestHeader(const std::string& testedClass) {
    std::cout << lineDecorator;
    std::cout << "    Unit tests for " << testedClass << " class   \n";
    std::cout << lineDecorator;
}

void TestingSuite::classTestFooter(const std::string& testedClass) {
    std::cout << "        " << testedClass << " tests Completed      \n";
    std::cout << lineDecorator;
    std::cout << "\n";
}