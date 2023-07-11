//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/GameComponents.h"

/**
 * Constructor for GameComponents object
 */
GameComponents::GameComponents() = default;

void GameComponents::displayRules() {
    std::cout << "rules here";
}

/**
 * ASCII art of an explosion representing `bust` which includes the players name and hand value
 *
 * @param name players name who went bust
 * @param value value of the hand which caused them to go bust
 * @return
 */
 void GameComponents::bustGraphic(const std::string& name, int value) {
    std::cout << "\n'.  \\ | /  ,'\n"
                 "  `. `.' ,'\n"
                 " ( .`.|,' .)\n"
                 "  -- BUST --\n"
                 "  " + name +  ": " + std::to_string(value) +" \n\n";
}

/**
 * ASCII art of an ace of each suit in a row
 *
 * @return a string of ASCII art depicting 4 aces in a row
 * */
void GameComponents::cardsGraphic() {
    std::cout << "     _____\n"
                 "    |A .  | _____\n"
                 "    | /.\\ ||A ^  | _____\n"
                 "    |(_._)|| / \\ ||A _  | _____\n"
                 "    |  |  || \\ / || ( ) ||A_ _ |\n"
                 "    |____V||  .  ||(_'_)||( v )|\n"
                 "           |____V||  |  || \\ / |\n"
                 "                  |____V||  .  |\n"
                 "                         |____V|\n\n";
}

/**
 *
 *
 * @return
 * */
void GameComponents::playerBlackjack(const Player &player) {
    player.printHand();
    std::cout << "************************************\n"
                 "*             BLACKJACK            *\n"
                 "************************************\n";
}

void GameComponents::dealerBlackjack(const Dealer &dealer) {
    dealer.printHand();
    std::cout << "************************************\n"
                 "*             BLACKJACK            *\n"
                 "************************************\n";
}

void GameComponents::gameIntro() {
    std::string line = "*----------------------------------*\n";

    std::cout << line << "|       Welcome to Blackjack!      |\n" << line;

    cardsGraphic();
    std::cout << "\n";
}

std::vector<Player> GameComponents::setupPlayers() {
    std::vector<Player> players;
    int numPlayers = 0;

    while(numPlayers < 1 || numPlayers > 4) {
        std::cout << "How many players are there?\n"
                     "Enter a number between 1-4:\n";
        std::cin >> numPlayers;
        if(std::cin.fail()) {
            std::cin.clear(); // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the bad input
        } else if(numPlayers < 1 || numPlayers > 4) {
            std::cout << "Invalid input.\n"
                         "Please enter a number between 1-4.\n\n";
        }
    }
    std::cout << "\n";

    for(int i = 0; i < numPlayers; i++) {
        std::cout << "Enter player " << i+1 << "'s name (up to 7 characters):\n";
        std::string name;
        std::cin >> name;
        Player player = Player(name.substr(0, 7), i);
        players.push_back(player);
        std::cout << "\n";
    }
    std::cout << "\n";
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

std::vector<std::string> GameComponents::printHandHelper(const std::string &card, char delim)  {
    std::vector<std::string> cards;
    std::stringstream ss(card);
    std::string item;
    while(getline(ss, item, delim)) {
        cards.push_back(item);
    }
    return cards;
}