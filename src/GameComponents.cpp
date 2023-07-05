//
// Created by Anthony Gavriel on 03/07/2023.
//

#include <sstream>
#include "../include/GameComponents.h"

GameComponents::GameComponents() {
    cardsGraphic = "     _____\n"
                   "    |A .  | _____\n"
                   "    | /.\\ ||A ^  | _____\n"
                   "    |(_._)|| / \\ ||A _  | _____\n"
                   "    |  |  || \\ / || ( ) ||A_ _ |\n"
                   "    |____V||  .  ||(_'_)||( v )|\n"
                   "           |____V||  |  || \\ / |\n"
                   "                  |____V||  .  |\n"
                   "                         |____V|\n\n";

    blackjackGraphic = "   ______________________________________\n"
                       "   /   _______________________________    \\\n"
                       "  |   |            __ __              |   |\n"
                       "  | _ |    /\\     ) _) /''''',        |   |\n"
                       "  |(.)|   <  >    \\ ) // '  `,        |   |\n"
                       "  | ` |    \\/       \\/// ~ |~:    +   |   |\n"
                       "  |   |             ///*\\  ' :    |   |   |\n"
                       "  |   |            ///***\\_~.'    |   |   |\n"
                       "  |   |  .'.    __///````,,..\\_   |   |   |\n"
                       "  |   |   ` \\ _/* +_\\#\\\\~\\ooo/ \\  |   |   |\n"
                       "  |   |     |/:\\ + *\\_\\#\\~\\so/!!\\ |   |   |\n"
                       "  |   |    _\\_::\\ * + \\-\\#\\\\o/!!!\\|   |   |\n"
                       "  |   |   / <_=::\\ + */_____@_!!!_|   |   |\n"
                       "  |   |  <__/_____\\ */( /\\______ _|   |   |\n"
                       "  |   |   |_   _ __\\/_)/* \\   ._/  >  |   |\n"
                       "  |   |   | !!! @     /* + \\::=_>_/   |   |\n"
                       "  |   |   |\\!!!/o\\\\#\\_\\ + * \\::_\\     |   |\n"
                       "  |   |   | \\!!/os\\~\\#_\\_* + \\:/|     |   |\n"
                       "  |   |   |  \\_/ooo\\~\\\\#_\\+_*/- \\     |   |\n"
                       "  |   |   |    \\''``,,,,///      .`.  |   |\n"
                       "  |   |   |     ,.- ***///        '   |   |\n"
                       "  |   |   |    : ~  \\*///             |   |\n"
                       "  |   |   +    : |   \\//\\             |   |\n"
                       "  |   |        ,~  ~ //_( \\     /\\    | ; |\n"
                       "  |   |        ,'  ` /_(__(    <  >   |(_)|\n"
                       "  |   |********BLACKJACK********\\/    |   |\n"
                       "  |   |_______________________________|   |\n"
                       "   \\______________________________________/\n";
}

std::string GameComponents::getBustGraphic(std::string name, int value) {
    std::string bustGraphic = "           '.  \\ | /  ,'\n"
                  "              `. `.' ,'\n"
                  "             ( .`.|,' .)\n"
                  "              -- BUST --\n"
                  "             " + name +  ": " + std::to_string(value) +"  \n";
    return bustGraphic;
}

std::string GameComponents::getCardsGraphic() {
    return cardsGraphic;
}

std::string GameComponents::getBlackjackGraphic() {
    return blackjackGraphic;
}

void GameComponents::gameIntro() {
    std::string line = "*----------------------------------*\n";

    std::cout << line << "|       Welcome to Blackjack!      |\n" << line;

    std::cout << cardsGraphic;
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
        Player player = Player(name.substr(0, 7));
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