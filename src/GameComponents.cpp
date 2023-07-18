/**
 * @file GameComponents.cpp
 * @brief The implementation of the GameComponents class and its functions.
 * @author Anthony Gavriel
 * @date 03/07/2023
 */

#include "../include/GameComponents.h"

/**
 * @brief See declaration in GameComponents.h for details.
 */
std::vector<Player> GameComponents::setupPlayers() {
    std::vector<Player> players;
    int numPlayers = 0;

    /** Loop is infinite until input is valid. */
    while(numPlayers < 1 || numPlayers > 4) {
        std::cout << "How many players are there?\n"
                     "Enter a number between 1-4:\n";
        std::cin >> numPlayers;
        if(std::cin.fail()) {
            std::cin.clear(); /** Clear the fail state. */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /** Ignore the bad input. */
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

/**
 * @brief See declaration in GameComponents.h for details
 */
Deck GameComponents::setupDeck() {
    Deck deck = Deck();
    return deck;
}

/**
 * @brief See declaration in GameComponents.h for details
 */
Dealer GameComponents::setupDealer() {
    Dealer dealer = Dealer();
    return dealer;
}

/**
 * @brief See declaration in GameComponents.h for details
 */
std::vector<std::string> GameComponents::printHandHelper(const std::string &card, char delim)  {
    std::vector<std::string> cards;
    std::stringstream ss(card);
    std::string item;
    while(getline(ss, item, delim)) {
        cards.push_back(item);
    }
    return cards;
}

void GameComponents::displayRules() {
    std::cout << "rules here";
}

/**
 * @brief See declaration in GameComponents.h for details
 */
void GameComponents::gameIntro() {
    std::string line = "*----------------------------------*\n";

    std::cout << line << "|       Welcome to Blackjack!      |\n" << line;

    cardsGraphic();
    std::cout << "\n";
}

/**
 * @brief See declaration in GameComponents.h for details
 */
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
 * @brief See declaration in GameComponents.h for details
 */
 void GameComponents::bustGraphic(const std::string& name, int value) {
    std::cout << "\n'.  \\ | /  ,'\n"
                 "  `. `.' ,'\n"
                 " ( .`.|,' .)\n"
                 "  -- BUST --\n"
                 "  " + name +  ": " + std::to_string(value) +" \n\n";
}

/**
 * @brief See declaration in GameComponents.h for details
 */
void GameComponents::stickGraphic(const std::string& name, int handValue) {
    std::string line = "*----------------------------------*\n";

    std::cout << line;
    std::cout << "         " << name << " sticks with " << handValue << "             \n";
    std::cout << line;
}

/**
 * @brief See declaration in GameComponents.h for details
 */
void GameComponents::playerBlackjack(const Player &player) {
    player.printHand();
    std::cout << "************************************\n"
                 "*             BLACKJACK            *\n"
                 "************************************\n\n";
}

/**
 * @brief See declaration in GameComponents.h for details
 */
void GameComponents::dealerBlackjack(const Dealer &dealer) {
    dealer.printHand();
    std::cout << "************************************\n"
                 "*             BLACKJACK            *\n"
                 "************************************\n\n";
}

GameComponents::GameComponents() = default;
