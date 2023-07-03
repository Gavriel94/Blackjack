//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/GameComponents.h"

class GameComponentsTest {
public:
    static void getPlayersTest() {
        GameComponents gameComponents = GameComponents();

        std::cout << "assert(players.at(0).getName() == \"Bob\")\n";
        std::vector<Player> players = gameComponents.setupPlayers();
        assert(players.at(0).getName() == "Bob");

        players = {};

        std::cout << "assert(players.at(0).getName() == \"Bob\")\n";
        std::cout << "assert(players.at(1).getName() == \"Alice\")\n";
        std::cout << "assert(players.at(2).getName() == \"Terry\")\n";

        players = gameComponents.setupPlayers();
        assert(players.at(0).getName() == "Bob");
        assert(players.at(1).getName() == "Alice");
        assert(players.at(2).getName() == "Terry");
    }

    static void setupDeckTest() {
        GameComponents gameComponents = GameComponents();

        Deck deck = gameComponents.setupDeck();
        Deck freshDeck = Deck();
        freshDeck.create();

        // game components deck should be shuffled
        assert(deck.getDeck() != freshDeck.getDeck());
        assert(deck.getSize() == 52);
    }

    static void setupDealerTest() {
        GameComponents gameComponents = GameComponents();
        Dealer dealer = gameComponents.setupDealer();

        assert(dealer.getPlaying() == true);
    }
};