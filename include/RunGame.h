/**
 * @file RunGame.h
 * @brief The declaration of the RunGame class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#ifndef BLACKJACK_RUNGAME_H
#define BLACKJACK_RUNGAME_H

#include "Deck.h"
#include "Dealer.h"
#include "GameComponents.h"

/**
 * @brief Declaration of friend class required for testing private functions.
 */
class RunGameTest;

/**
 * @class RunGame
 * @brief Functions which maneuver the game state from default to end.
 *
 * RunGame executes game states such as the players and dealers turn,
 * checking who won and restarting the game.
 */
class RunGame {
public:
    /**
     * @brief Constructor for RunGame
     *
     * On instantiation of a game, an instance of a deck and a dealer are created
     * as well as the container for new players.
     */
    RunGame();

    /**
     * @brief Setup game and run
     *
     * Sets up the game and loops it until the player either runs out of cash or exits manually.
     */
    void runGame();

    /**
     * @brief Determines the win/loss status of each player and the dealer at the end of a game.
     *
     * Iterates through each player and determines if they should receive winnings or lose their bet.
     * This function checks if the dealer and which, if any, players are bust.
     * If the dealer is bust, all players who aren't bust receive winnings.
     * If the dealer is not bust, any players who are instantly lose their bet.
     *
     * Comparisons are made between the dealer and any remaining players.
     * The blackjack status of both the dealer and players is checked.
     * If the dealer has blackjack and no players do, those players lose their bet.
     * If the dealer has blackjack and one or more player does as well, they tie and receive their bet back.
     * If neither dealer nor players have blackjack, the total value of the cards in their hand is compared.
     * Any player who is closer to 21 than the dealer receives winnings.
     * If the dealer is closer to 21 than any player, the player loses their bet.
     *
     * This function will modify the dealer and all players `cash` attributes.
     *
     * This function calls the private functions blackjackCheck() and valueCheck()
     * in order to check wins by blackjack and wins by value.
     */
    void calculateTurnResult();
private:
    /**
     * @brief Executes a complete turn of a game
     *
     * Checks if the players vector is empty, if it is it means all players have lost their cash.
     * Creates a new deck and shuffles it, deals a card to the dealer and two cards to a player.
     * Private function `playerTurn()` is used to perform player actions until their turn is complete.
     * Repeats for all players then the dealer has their turn.
     * Uses `calculateTurnResult()` to determine the winner of this game.
     */
    void gameLoop();

    /**
     * @brief Executes a players turn of the game
     *
     * This is where the player makes their bet, chooses when to hit or stick.
     * The player hits until they're either bust or choose to stick.
     * If the player has blackjack their turn is over, they cannot choose to take another card on top.
     *
     * @param player The player whose turn it is.
     */
    void playerTurn(Player& player);

    /**
     * @brief Executes the dealers turn of the game
     *
     * Where the dealer receives cards until either they have blackjack, are bust or stick when `handValue` is =>17.
     */
    void dealerTurn();

    /**
     * @brief Determines if player or dealer wins or ties by blackjack.
     *
     * @param player Player being compared against the dealer for blackjack.
     * @return True if the game is over through blackjack (player wins or ties) otherwise false.
     */
    bool blackjackCheck(Player& player);

    /**
     * @brief Determines if the player or dealer wins, ties or loses through the value of their hand.
     *
     * @param player The player whose hand is being compared to the dealer.
     */
    void valueCheck(Player& player);

    /**
     * @brief Checks if the player has run out of cash.
     *
     * If the player has run out of cash, a message is printed to the console informing the user.
     * The player is then removed from the `players` vector as they cannot continue betting.
     *
     * @param player The player whose cash is being checked.
     */
    void checkIfPlayerOut(Player& player);

    /**
     * @brief Asks the user if they would like to play another hand.
     *
     * If the user does, this function modifies the dealer and all players
     * It will reset their attributes to their default state enabling a fresh start.
     *
     * @return True if the user wants to continue, otherwise false.
     */
    bool keepPlaying();

    /**
     * @brief prints the name and hand value of the dealer and each player.
     */
    void printValues();

    /**
     * @brief The dealer in the game.
     */
    Dealer dealer;

    /**
     * @brief The deck used to play the current game.
     */
    Deck deck;

    /**
     * @brief A vector containing all the players in the current game.
     */
    std::vector<Player> players;

    /**
     * @brief Making RunGameTest a friend class allows testing of private functions.
     */
    friend class RunGameTest;
};

#endif //BLACKJACK_RUNGAME_H
