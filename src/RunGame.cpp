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
    for(auto player : players) {
        std::cout << "- " << player.getName() << "\n";
    }

    bool playersPlaying = true;
    while(playersPlaying) {
        playersPlaying = gameLoop();
    }
    std::cout << "\n\nThanks for playing!\n\n";
}

bool RunGame::gameLoop() {
    dealer.startGame(deck, players);


    dealer.printHand();
    std::cout << "\n";

    for(auto& player: players) {
        while(player.getPlaying()) {
            player.printHand();
            bool hit = player.hitOrStick();
            if(hit) {
                Card card = deck.removeCard();
                player.receiveCard(card);
                if(player.isBust()) {
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

    while(dealer.getPlaying()) {
        Card card = deck.removeCard();
        dealer.receiveCard(card);
        dealer.printHand();
        if(dealer.getBust()) {
            GameComponents::bustGraphic("Dealer", dealer.getHandValue());
        }
        if(dealer.getBlackjack()) {
            GameComponents::dealerBlackjack(dealer);
            break;
        }
    }

    // all hands played, now tally up scores

    for(auto& player: players) {
        std::cout << player.getName() << " has " << player.getHandValue() << "\n";
    }
    std::cout << "Dealer has " << dealer.getHandValue() << "\n";

    int choice = 0;
    while(choice < 1 || choice > 2) {
        std::cout << "\n";
        std::cout << "Type 1 to keep playing or 2 to exit game:\n";
        std::cin >> choice;
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