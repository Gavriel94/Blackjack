//
// Created by Anthony Gavriel on 30/06/2023.
//

#include <iostream>

#include "CardTest.cpp"
#include "DeckTest.cpp"
#include "PlayerTest.cpp"
#include "DealerTest.cpp"
#include "GameComponentsTest.cpp"

class UnitTest {
public:
    UnitTest() = default;

    void cardTests() {
        std::string className = "Card";
        classTestHeader(className);
        callClassTest([&]() { CardTest::testGetSuit(); }, "getSuit()");
        callClassTest([&]() { CardTest::testGetValue(); }, "getValue()");
        classTestFooter(className);
        newLine();
    }

    void deckTests() {
        std::string className = "Deck";
        classTestHeader(className);
        callClassTest([&]() { DeckTest::testCreate(); }, "createDeck()");
        callClassTest([&]() { DeckTest::testShuffle(); }, "shuffleDeck()");
        callClassTest([&]() { DeckTest::testRemoveCard(); }, "removeCard()");
        classTestFooter(className);
        newLine();
    }

    void playerTests() {
        std::string  className = "Player";
        classTestHeader(className);

        callClassTest([&]() { PlayerTest::testGetName(); }, "getName()");
        callClassTest([&]() { PlayerTest::testAce(); }, "ace()");
        callClassTest([&]() { PlayerTest::testReceiveCard(); }, "receiveCard()");
        callClassTest([&]() { PlayerTest::testIsBust(); }, "isBust()");

        classTestFooter(className);
        newLine();
    }

    void dealerTests() {
        std::string className = "Dealer";
        classTestHeader(className);

        callClassTest([&]() { DealerTest::testStartGame(); }, "startGame()");
        callClassTest([&]() { DealerTest::testReceiveCard(); }, "receiveCard()");
        callClassTest([&]() { DealerTest::testHandValue(); }, "getHandValue()");
        callClassTest([&]() { DealerTest::testBlackjack(); }, "blackjack()");
        callClassTest([&]() { DealerTest::testBust(); }, "testBust()");
        callClassTest([&]() { DealerTest::testStick(); }, "testStick()");

        classTestFooter(className);
        newLine();
    }

    void gameComponentsTests() {
        std::string className = "Components";
        classTestHeader(className);

        callClassTest([&]() { GameComponentsTest::getPlayersTest(); }, "getPlayers()");
        callClassTest([&]() { GameComponentsTest::setupDeckTest(); }, "setupDeck()");
        callClassTest([&]() { GameComponentsTest::setupDealerTest(); }, "setupDealer()");

        classTestFooter(className);
        newLine();
    }

    void allTests() {
        cardTests();
        deckTests();
        playerTests();
        dealerTests();
    }

private:
    void callClassTest(const std::function<void()>& test, const std::string& testName) {
        test();
        functionFooter(testName);
    }

    void classTestHeader(const std::string& testedClass) {
        line();
        std::cout << "    Unit tests for " << testedClass << " class   \n";
        line();
    }

    void classTestFooter(const std::string& testedClass) {
        std::cout << "        " << testedClass << " tests Completed      \n";
        line();
    }

    void functionFooter(const std::string& functionName) {
        std::cout << "        " << functionName << " passed   \n";
        line();
    }

    static void line() {
        std::cout << "*----------------------------------*\n";
    }

    static void newLine() {
        std::cout << "\n";
    }
};
