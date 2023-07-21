/**
 * @file RunGame.cpp
 * @brief The implementation of the RunGame class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#include "../include/RunGame.h"

/**
 * @brief See declaration in RunGame.h for details.
 */
RunGame::RunGame() {
    dealer = GameComponents::setupDealer();
    deck = GameComponents::setupDeck();
    players = {};
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::runGame() {
    GameComponents::gameIntro();
    players = GameComponents::setupPlayers();

    /** Displays names entered via input back at the user to confirm correct entry. */
    std::cout << "Seated at the table we have:\n\n";
    for(const auto& player : players) {
        std::cout << "- " << player.getName() << "\n";
    }

    bool playersPlaying = true;
    while(playersPlaying) {
        gameLoop();
        if(players.empty()) {
            std::cout << "Players have run out of cash!\nThe casino wins!\n";
            playersPlaying = false;
        } else {
            playersPlaying = keepPlaying();
        }
    }
    std::cout << "\nThanks for playing!\n\n";
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::calculateTurnResult() {
    for(auto& player : players) {
        if(!player.getBust()) {
            /** For each player who is not getBust, */
            if(dealer.getBust()) {
                /** Player wins if dealer is getBust. */
                std::cout << player.getName() << " wins!\n";
                player.win();
            } else {
                /** Check for end-game by blackjack. */
                if(!blackjackCheck(player)) {
                    /** Check for end-game by hand value. */
                    valueCheck(player);
                }
            }
        } else {
            /** Bust players lose. */
            std::cout << player.getName() << " loses!\n";
            player.lose();
            /** Checks if losing player still has cash. */
            checkIfPlayerOut(player);
        }
    }
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::gameLoop() {
    /** Resets the deck */
    deck = GameComponents::setupDeck();
    deck.shuffle();

    /** Player makes their bet before card are dealt. */
    for(auto& player : players) {
        player.makeBet();
    }

    /** Dealer receives the first card */
    dealer.receiveCard(deck.removeCard());
    dealer.printHand();

    /** Each player has their turn */
    for(auto& player: players) {
        playerTurn(player);
    }

    /** The dealer has their turn and win/loss states are determined. */
    dealerTurn();
    printValues();
    calculateTurnResult();
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::playerTurn(Player& player) {
    /** Player receives two cards then decides to hit or getStick. */
    player.receiveCard(deck.removeCard());
    player.receiveCard(deck.removeCard());
    player.printHand();

    while(player.getPlaying()) {
        bool hit = player.hitOrStick();
        if(hit) {
            player.receiveCard(deck.removeCard());
            player.printHand();
            if(player.getBust()) {
                GameComponents::bustGraphic(player.getName(), player.getHandValue());
            }
            if(player.getBlackjack()) {
                GameComponents::playerBlackjack(player);
                break;
            }
        } else {
            GameComponents::stickGraphic(player.getName(), player.getHandValue());
        }
    }
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::dealerTurn() {
    while(dealer.getPlaying()) {
        dealer.receiveCard(deck.removeCard());
        dealer.printHand();
        if(dealer.getBust()) {
            GameComponents::bustGraphic("Dealer", dealer.getHandValue());
        }
        if(dealer.getBlackjack()) {
            GameComponents::dealerBlackjack(dealer);
        }
    }
}

/**
 * @brief See declaration in RunGame.h for details.
 */
bool RunGame::blackjackCheck(Player& player) {
    std::string name = player.getName();
    bool playerBlackjack = player.getBlackjack();
    bool dealerBlackjack = dealer.getBlackjack();

    if(dealerBlackjack) {
        if(playerBlackjack) {
            /** Dealer and player have blackjack. */
            std::cout << name << " ties with dealer!\n";
            return true;
        } else {
            std::cout << "Dealer has Blackjack!\n";
            std::cout << name << " loses!\n\n";
            player.lose();
            checkIfPlayerOut(player);
            return true;
        }
    }
    if(playerBlackjack) {
        /** Player has blackjack and dealer does not */
        std::cout << name << " wins with Blackjack!\n\n";
        player.win();
        return true;
    }
    return false;
}

void RunGame::valueCheck(Player& player) {
    std::string name = player.getName();
    if(player.getHandValue() > dealer.getHandValue()) {
        /** Player is closer to 21 than dealer */
        std::cout << name << " wins!\n";
        player.win();
    }
    if(player.getHandValue() == dealer.getHandValue()) {
        /** Player and dealer have the same value */
        std::cout << name << " ties with dealer!\n";
    }
    if(player.getHandValue() < dealer.getHandValue()) {
        /** Dealer is closer to 21 than player */
        std::cout << name << " loses!\n\n";
        player.lose();
        checkIfPlayerOut(player);
    }
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::checkIfPlayerOut(Player &player) {
    if(player.getCash() <= 0) {
        std::cout << player.getName() <<  " is out of cash!\n";
        std::cout << "Good thing it's not real money..\n\n";
        std::erase(players, player);
    }
}

/**
 * @brief See declaration in RunGame.h for details.
 */
bool RunGame::keepPlaying() {
    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << "\n";
        std::cout << "Type 1 to keep playing or 2 to exit game:\n";
        std::cin >> choice;
        std::cout << "\n";
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
        } else if(choice < 1 || choice > 2) {
            std::cout << "Invalid input.\n"
                         "Type 1 to keep playing or 2 to exit game:\n\n";
        } else {
            break;
        }
    }
    if(choice == 1) {
        /** Resets all game attributes to default state. */
        deck = GameComponents::setupDeck();
        for(auto& player : players) {
            player.startNewGame();
        }
        dealer.startNewGame();
        return true;
    }
    return false;
}

/**
 * @brief See declaration in RunGame.h for details.
 */
void RunGame::printValues() {
    for(auto& player: players) {
        std::cout << player.getName() << " has " << player.getHandValue() << "\n";
    }
    std::cout << "Dealer has " << dealer.getHandValue() << "\n\n";
}