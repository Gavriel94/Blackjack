//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../include/RunGame.h"

RunGame::RunGame() {
    dealer = GameComponents::setupDealer();
    deck = GameComponents::setupDeck();
    players = {};
}

void RunGame::initialiseGame() {
    GameComponents::gameIntro();
    players = GameComponents::setupPlayers();

    std::cout << "Seated at the table we have:\n\n";
    for(const auto& player : players) {
        std::cout << "- " << player.getName() << "\n";
    }

    bool playersPlaying = true;
    while(playersPlaying) {
        playersPlaying = gameLoop();
    }
    std::cout << "\nThanks for playing!\n\n";
}

bool RunGame::blackjackCheck(Player& player) {
    bool playerBlackjack = player.getBlackjack();
    bool dealerBlackjack = dealer.getBlackjack();

    if(dealerBlackjack) {
        if(playerBlackjack) {
            // dealer and player have blackjack
            std::cout << "Tie between " << player.getName() << " and Dealer.\n\n";
            return false;
        } else {
            std::cout << player.getName() << " loses!\n\n";
            player.loseBet();
            checkIfPlayerOut(player);
            return true;
        }
    }
    if(playerBlackjack) {
        // player has blackjack, dealer does not
        std::cout << player.getName() << " wins with Blackjack!\n\n";
        player.receiveWinnings();
        return true;
    }
    return false;
}

void RunGame::valueCheck(Player& player) {
    std::string name = player.getName();
    if(player.getHandValue() > dealer.getHandValue()) {
        std::cout << name << " wins!\n";
        player.receiveWinnings();
    }
    if(player.getHandValue() == dealer.getHandValue()) {
        std::cout << name << " ties with dealer!\n";
    }
    if(player.getHandValue() < dealer.getHandValue()) {
        std::cout << name << " loses!\n\n";
        player.loseBet();
        checkIfPlayerOut(player);
    }
}

void RunGame::checkWin() {
    for(auto& player : players) {
        // if players aren't bust
        if(!player.getBust()) {
            if(dealer.getBust()) {
                //if dealer is bust player wins
                std::cout << player.getName() << " wins!\n";
                player.receiveWinnings();
            } else {
                //check for blackjack wins
                if(!blackjackCheck(player)) {
                    //check for wins by value
                    valueCheck(player);
                }
            }
        } else {
            //player is bust so they lose
            std::cout << player.getName() << " loses!\n";
            player.loseBet();
            //checks if player has run out of cash
            checkIfPlayerOut(player);
        }
    }
}

void RunGame::playerTurn(Player& player) {
    // bets are made before receiving the cards
    player.makeBet();
    // player receives 2 cards before they're given options to hit or stick
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
            player.stick();
        }
    }
}

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

bool RunGame::gameLoop() {

    if(players.empty()) {
        std::cout << "No more players, the casino wins!\n\n";
        return false;
    } else {
        // Dealer receives first card
        dealer.receiveCard(deck.removeCard());
        dealer.printHand();

        for(auto& player: players) {
            playerTurn(player);
        }
        dealerTurn();
        printValues();
        checkWin();
    }

    return keepPlaying();
}

void RunGame::printValues() {
    for(auto& player: players) {
        std::cout << player.getName() << " has " << player.getHandValue() << "\n";
    }
    std::cout << "Dealer has " << dealer.getHandValue() << "\n\n";
}

bool RunGame::keepPlaying() {
    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << "\n";
        std::cout << "Type 1 to keep playing or 2 to exit game:\n";
        std::cin >> choice;
        std::cout << "\n";
        if(std::cin.fail()) {
            std::cin.clear(); // clear fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(choice < 1 || choice > 2) {
            std::cout << "Invalid input.\n"
                         "Type 1 to keep playing or 2 to exit game:\n\n";
        } else {
            break;
        }
    }
    if(choice == 1) {
        deck = GameComponents::setupDeck();
        for(auto& player : players) {
            player.startNewGame();
        }
        dealer.startNewGame();
        return true;
    }
    return false;
}

void RunGame::checkIfPlayerOut(Player &player) {
    if(player.getCash() <= 0) {
        std::cout << player.getName() <<  " is out of cash!\n";
        std::cout << "Good thing it's not real money..\n\n";
        std::erase(players, player);
    }
}