//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/GameComponents.h"

GameComponents::GameComponents() = default;

void GameComponents::gameIntro() {
    std::string line = "*----------------------------------*\n";

    std::cout << line << "|       Welcome to Blackjack!      |\n" << line;
}

std::vector<Player> GameComponents::setupPlayers() {
    std::vector<Player> players;
    std::cout << "How many players are there?\n"
                 "Enter a number between 1-4:\n";
    int choice = 0;
    int numPlayers = 0;
    std::cin >> choice;
    switch (choice) {
        case 1:
            numPlayers = 1;
            break;
        case 2:
            numPlayers = 2;
            break;
        case 3:
            numPlayers = 3;
            break;
        case 4:
            numPlayers = 4;
            break;
        default:
            std::cout << "Please enter a number between 1-4:\n";
            std::cin >> choice;
    }

    if(numPlayers == 1) {
        std::cout << "\n\nWhat's the players name?\n";
        std::string name;
        std::cin >> name;
        Player player = Player(name);
        players.push_back(player);
        std::cout << "\n";
    } else if(numPlayers == 2) {
        std::cout << "\n\nWhat's player 1's name?\n";
        std::string player1Name;
        std::cin >> player1Name;
        Player player1 = Player(player1Name);
        players.push_back(player1);

        std::cout << "\n\nWhat's player 2's name?\n";
        std::string player2Name;
        std::cin >> player2Name;
        Player player2 = Player(player2Name);
        players.push_back(player2);

        std::cout << "\n";
    } else if(numPlayers == 3) {
        std::cout << "\n\nWhat's player 1's name?\n";
        std::string player1Name;
        std::cin >> player1Name;
        Player player1 = Player(player1Name);
        players.push_back(player1);

        std::cout << "\n\nWhat's player 2's name?\n";
        std::string player2Name;
        std::cin >> player2Name;
        Player player2 = Player(player2Name);
        players.push_back(player2);

        std::cout << "\n\nWhat's player 3's name?\n";
        std::string player3Name;
        std::cin >> player3Name;
        Player player3 = Player(player3Name);
        players.push_back(player3);

        std::cout << "\n";
    } else if(numPlayers == 4){
        std::cout << "\n\nWhat's player 1's name?\n";
        std::string player1Name;
        std::cin >> player1Name;
        Player player1 = Player(player1Name);
        players.push_back(player1);

        std::cout << "\n\nWhat's player 2's name?\n";
        std::string player2Name;
        std::cin >> player2Name;
        Player player2 = Player(player2Name);
        players.push_back(player2);

        std::cout << "\n\nWhat's player 3's name?\n";
        std::string player3Name;
        std::cin >> player3Name;
        Player player3 = Player(player3Name);
        players.push_back(player3);

        std::cout << "\n\nWhat's player 4's name?\n";
        std::string player4Name;
        std::cin >> player4Name;
        Player player4 = Player(player4Name);
        players.push_back(player4);
    }
    return players;
}

Deck GameComponents::setupDeck() {
    Deck deck = Deck();
    deck.create();
    deck.shuffle();
    return deck;
}

Dealer GameComponents::setupDealer() {
    Dealer dealer = Dealer();
    return dealer;
}