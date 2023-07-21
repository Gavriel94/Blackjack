/**
 * @file TestingSuite.cpp
 * @brief The implementation of the TestingSuite class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#include "../include/TestingSuite.h"

/**
 * @brief Constructor initialising the border for text boxes.
 */
TestingSuite::TestingSuite() {
    boxBorder = "*----------------------------------*\n";
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::testHost() {
    std::cout << boxBorder;
    std::cout << "   Welcome to the Testing Suite\n";
    std::cout << boxBorder;
    std::cout << "\n";

    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << "\n";
        std::cout << "Type 1 to see the test menu or 2 to exit test mode:\n";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear the fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
        } else if(choice < 1 || choice > 2) {
            std::cout << "Invalid input.\n"
                         "Type 1 to see the test menu or 2 to exit test mode:\n\n";
        } else {
            break;
        }
    }
    /** Wraps the menu in a loop so user can execute multiple tests */
    if(choice == 1) {
        bool testingMode = true;
        while(testingMode) {
            testingMode = testMenu();
        }
    }
    std::cout << "\nHave a nice day!\n";
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
bool TestingSuite::testMenu() {
    int choice = 0;
    while(choice < 1 || choice > 7) {
        std::cout << "You can test the following classes by typing in their corresponding number:\n\n";
        std::cout << "1 - Card Class\n";
        std::cout << "2 - Deck Class\n";
        std::cout << "3 - Player Class\n";
        std::cout << "4 - Dealer Class\n";
        std::cout << "5 - GameComponents Class\n";
        std::cout << "6 - RunGame Class\n";
        std::cout << "7 - Test all classes\n";
        std::cout << "8 - Exit test mode\n";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear the fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
        } else if(choice < 1 || choice > 8) {
            std::cout << "Invalid input.\n\n";
        } else {
            break;
        }
    }
    for(int i = 0; i < 100; i++) {
        std::cout << "\n";
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
            runGameTests();
            return true;
        case 7:
            allTests();
            return true;
        case 8:
            return false;
    }
    return false;
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::cardTests() {
    std::string className = "Card";
    classTestHeader(className);
    callClassTest([&]() { CardTest::getSuit(); }, "getSuit()", "");
    callClassTest([&]() { CardTest::getValue(); }, "getValue()", "");
    callClassTest([&]() { CardTest::ascii(); }, "ascii()", "Visual test.\nInspect cards.");
    classTestFooter(className);
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::dealerTests() {
    std::string className = "Dealer";
    classTestHeader(className);

    callClassTest([&]() { DealerTest::receiveCard(); }, "receiveCard()", "");
    callClassTest([&]() { DealerTest::handValue(); }, "getHandValue()", "");
    callClassTest([&]() { DealerTest::blackjack(); }, "blackjack()", "");
    callClassTest([&]() { DealerTest::getBust(); }, "testBust()", "");
    callClassTest([&]() { DealerTest::getStick(); }, "testStick()", "");

    classTestFooter(className);
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::deckTests() {
    std::string className = "Deck";
    classTestHeader(className);
    callClassTest([&]() { DeckTest::create(); }, "createDeck()", "");
    callClassTest([&]() { DeckTest::shuffle(); }, "shuffleDeck()", "");
    callClassTest([&]() { DeckTest::removeCard(); }, "removeCard()", "");
    classTestFooter(className);
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::gameComponentsTests() {
    std::string className = "GameComponents";
    classTestHeader(className);

    callClassTest([&]() { GameComponentsTest::setupOnePlayer(); }, "setupOnePlayer()", "Set 1 player.\nUse name \"Bob\"");
    callClassTest([&]() { GameComponentsTest::setupThreePlayers(); }, "setupThreePlayers()", "Set 3 players.\nUse names \"Bob\", \"Alice\", \"Terry\"");
    callClassTest([&]() { GameComponentsTest::setupDeck(); }, "setupDeck()", "");
    callClassTest([&]() { GameComponentsTest::setupDealer(); }, "setupDealer()", "");
    callClassTest([&]() { GameComponentsTest::printHandHelper(); }, "printHandHelper()", "Visual test.\nInspect cards.");

    classTestFooter(className);
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::playerTests() {
    std::string  className = "Player";
    classTestHeader(className);

    callClassTest([&]() { PlayerTest::aceIsOne(); }, "aceIsOne()", "Ace must be 1.");
    callClassTest([&]() { PlayerTest::aceIsEleven(); }, "aceIsEleven()", "Ace must be 11.");
    callClassTest([&]() { PlayerTest::receiveCard(); }, "receiveCard()", "");
    callClassTest([&]() { PlayerTest::getHandValue(); }, "getHandValue()", "");
    callClassTest([&]() { PlayerTest::getBust(); }, "isBust()", "");
    callClassTest([&]() { PlayerTest::printHand(); }, "printHand()", "Visual test.\nInspect cards.");
    callClassTest([&]() { PlayerTest::makeBet(); }, "makeBet()", "");
    callClassTest([&]() { PlayerTest::blackjackWin(); }, "blackjackWin()", "Ace must be 11.");
    callClassTest([&]() { PlayerTest::standardWin(); }, "standardWin()", "");
    callClassTest([&]() { PlayerTest::hit(); }, "hit()", "Select `hit`.");
    callClassTest([&]() { PlayerTest::stick(); }, "stick()", "Select `stick`.");
    callClassTest([&]() { PlayerTest::comparePlayers(); }, "comparePlayers()", "");

    classTestFooter(className);
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::runGameTests() {
    std::string className = "RunGame";
    classTestHeader(className);

    callClassTest([&]() { RunGameTest::blackjackTie(); }, "blackjackTie()", "Ace must be 11.\nEnsure the message: \"Bob ties with dealer! \" is displayed.");
    callClassTest([&]() { RunGameTest::blackjackWin(); }, "blackjackWin()", "Ace must be 11.\nEnsure the message: \"Bob wins with Blackjack!\" is displayed.");
    callClassTest([&]() { RunGameTest::blackjackLoss(); }, "blackjackLoss()", "Ensure the message: \"Bob loses!\" is displayed.");
    callClassTest([&]() { RunGameTest::valueTie(); }, "valueTie()", "Ensure the message: \"Bob ties with dealer!\" is displayed.");
    callClassTest([&]() { RunGameTest::valueWin(); }, "valueWin()", "Ensure the message: \"Bob wins!\" is displayed.");
    callClassTest([&]() { RunGameTest::valueLoss(); }, "valueLoss()", "Ensure the message: \"Bob loses!\" is displayed.");
    callClassTest([&]() { RunGameTest::playerIsBust(); }, "playerIsBust()", "Ensure the message: \"Bob loses!\" is displayed.");
    callClassTest([&]() { RunGameTest::dealerIsBust(); }, "dealerIsBust()", "Ensure the message: \"Bob wins!\" is displayed.");
    callClassTest([&]() { RunGameTest::playerHasBlackjack(); }, "playerHasBlackjack()", "Ace must be 11.\nEnsure the message: \"Bob wins with Blackjack!\" is displayed.");
    callClassTest([&]() { RunGameTest::dealerHasBlackjack(); }, "dealerHasBlackjack()", "Ensure the message: \"Dealer has Blackjack!\nBob loses!\" is displayed.");
    callClassTest([&]() { RunGameTest::bothHaveBlackjack(); }, "bothHaveBlackjack()", "Ensure the message: \"Bob ties with dealer!\" is displayed.");
    callClassTest([&]() { RunGameTest::playerHigherValue(); }, "playerHigherValue()", "Ensure the message: \"Bob wins!\" is displayed.");
    callClassTest([&]() { RunGameTest::dealerHigherValue(); }, "dealerHigherValue()", "Ensure the message: \"Bob loses!\" is displayed.");
    callClassTest([&]() { RunGameTest::bothSameValue(); }, "bothSameValue()", "Ensure the message: \"Bob ties with dealer!\" is displayed.");
    callClassTest([&]() { RunGameTest::playerTurn(); }, "playerTurn()", "No actions required. Just observe the outcome.");
    callClassTest([&]() { RunGameTest::dealerTurn(); }, "dealerTurn()", "No actions required. Just observe the outcome.");
    callClassTest([&]() { RunGameTest::keepPlaying(); }, "keepPlaying()", "Select the option to keep playing.");
    callClassTest([&]() { RunGameTest::stopPlaying(); }, "stopPlaying()", "Select the option to stop playing.");

    classTestFooter(className);
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::allTests() {
    cardTests();
    deckTests();
    playerTests();
    dealerTests();
    gameComponentsTests();
    classTestFooter("All");
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::callClassTest(
        const std::function<void()>& test,
        const std::string& testName,
        const std::string& message
        ) {
    std::cout << boxBorder;
    if(message.size() > 1) {
        std::cout << message << "\n\n";
    }
    test(); /** Execute test */
    std::cout << "        " << testName << " passed   \n";
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::classTestHeader(const std::string& testedClass) {
    std::cout << boxBorder;
    std::cout << "    Unit tests for " << testedClass << " class   \n";
}

/**
 * @brief See declaration in TestingSuite.h for details.
 */
void TestingSuite::classTestFooter(const std::string& testedClass) {
    std::cout << boxBorder;
    std::cout << "     " << testedClass << " tests Completed      \n";
    std::cout << boxBorder;
    std::cout << "\n";
}