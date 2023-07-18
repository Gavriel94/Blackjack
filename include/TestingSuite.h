/**
 * @file TestingSuite.h
 * @brief The declaration of the TestingSuite class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_TESTINGSUITE_H
#define BLACKJACK_TESTINGSUITE_H

#include <iostream>

#include "Tests/CardTest.h"
#include "Tests/DealerTest.h"
#include "Tests/DeckTest.h"
#include "Tests/GameComponentsTest.h"
#include "Tests/PlayerTest.h"
#include "Tests/RunGameTest.h"
/**
 * @class TestingSuite
 * @brief Enables users to run tests for all or specific classes.
 *
 * The testing suite is accessed by passing the arg "test" when loading the game through the CLI:
 * $ ./Blackjack test
 * Used for testing logic in functions for all classes involved in the game.
 * The user cannot access the game from the testing suite. They have to terminate and reload the application.
 *
 * All classes have tests to ensure their functionality works as intended.
 * The user is able to test functions from:
 * - Card
 * - Dealer
 * - Deck
 * - GameComponents
 * - Player
 * - RunGame
 */
class TestingSuite {
public:
    /**
     * @brief Constructor for TestingSuite.
     */
    TestingSuite();

    /**
     * @brief Displays options for user to either run tests or to terminate application.
     */
    void testHost();
private:
    /**
     * @brief Tests for the Card class.
     *
     * Displays a text box informing the user the following tests are for the Card class.
     * Displays the output of all tests.
     * Displays a text box informing the user the tests for the Card class are completed.
     *
     * All tests are defined in CardTest.h.
     */
    void cardTests();

    /**
     * @brief Tests for the Dealer class.
     *
     * Displays a text box informing the user the following tests are for the Dealer class.
     * Displays the output of all tests.
     * Displays a text box informing the user the tests for the Dealer class are completed.
     *
     * All tests are defined in DealerTest.h.
     */
        void dealerTests();

    /**
     * @brief Tests for the Deck class.
     *
     * Displays a text box informing the user the following tests are for the Deck class.
     * Displays the output of all tests.
     * Displays a text box informing the user the tests for the Deck class are completed.
     *
     * All tests are defined in DeckTest.h.
     */
    void deckTests();

    /**
     * @brief Tests for the GameComponents class.
     *
     * Displays a text box informing the user the following tests are for the GameComponents class.
     * Displays the output of all tests and user input required for assertions.
     * Displays a text box informing the user the tests for the GameComponents class are completed.
     *
     * All tests are defined in GameComponentsTest.h.
     */
    void gameComponentsTests();

    /**
     * @brief Tests for the Player class.
     *
     * Displays a text box informing the user the following tests are for the Player class.
     * Displays the output of all tests and user input required for assertions.
     * Displays a text box informing the user the tests for the Player class are completed.
     *
     * All tests are defined in PlayerTest.h.
     */
    void playerTests();

    /**
     * @brief Tests for the RunGame class.
     *
     * Displays a text box informing the user the following tests are for the RunGame class.
     * Displays the output of all tests and user input required for assertions.
     * Displays a text box informing the user the tests for the RunGame class are completed.
     *
     * All tests are defined in RunGameTest.h.
     */
    void runGameTests();

    /**
     * @brief Combines all tests into one function.
     *
     * Displays a text box informing the user which class is being tested.
     * Displays the output of all tests and user input required for assertions.
     * Displays a text box informing informing the user when tests for each class are completed.
     */
    void allTests();

    /**
     * @brief List of classes available to test.
     *
     * Allows the user to select tests for all or specific classes, or to exit test mode.
     * Once a test has been run, the player has the option to run more tests or to exit the application.
     *
     * @return True if the user wants to run more tests, false if the user wants to exit the application.
     */
    bool testMenu();

    /**
     * @brief Executes a test and displays the outcome.
     *
     * Used as a lambda function to call static test functions.
     *
     * It calls the std::function object passed to it as a parameter.
     * The function must be void and throw an exception if there is an error.
     * This function displays the name of the test and information about the test if it is defined.
     *
     * @param test The function (test) which needs to be executed.
     * @param testName The name of the test.
     * @param message Message for the user to be displayed above the test, if required.
     */
    void callClassTest(const std::function<void()>& test, const std::string& testName, const std::string &message);

    /**
     * @brief A header, displayed in the terminal, informing the user which class is being tested.
     *
     * @param testedClass The class being tested.
     */
    void classTestHeader(const std::string& testedClass);

    /**
     * @brief A footer, displayed in the terminal, informing the user the tests for a class have been completed.
     *
     * @param testedClass The class whose tests are completed.
     */
    void classTestFooter(const std::string& testedClass);

    /**
     * @brief Line used to decorate text boxes.
     */
    std::string boxBorder;
};


#endif //BLACKJACK_TESTINGSUITE_H
