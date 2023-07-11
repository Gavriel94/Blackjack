//
// Created by Anthony Gavriel on 06/07/2023.
//

#ifndef BLACKJACK_TESTINGSUITE_H
#define BLACKJACK_TESTINGSUITE_H

#include <iostream>
#include "Tests/CardTest.h"
#include "Tests/DealerTest.h"
#include "Tests/DeckTest.h"
#include "Tests/GameComponentsTest.h"
#include "Tests/PlayerTest.h"
#include "Tests/RunGameTest.h"


class TestingSuite {
public:
    TestingSuite();
    void testHost();
private:
    void cardTests();
    void deckTests();
    void playerTests();
    void dealerTests();
    void gameComponentsTests();
    void runGameTests();
    void allTests();
    bool testMenu();
    std::string lineDecorator;
    void callClassTest(const std::function<void()>& test, const std::string& testName);
    void classTestHeader(const std::string& testedClass);
    void classTestFooter(const std::string& testedClass);
};


#endif //BLACKJACK_TESTINGSUITE_H
