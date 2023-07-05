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

    static void testPrintHandHelper() {
        GameComponents gameComponents = GameComponents();

        Card ace = Card(Card::SPADES, Card::ACE);
        ace.setSpadeAscii(14);
        Card king = Card(Card::HEARTS, Card::KING);
        king.setHeartAscii(13);

        std::vector<Card> cardVector = {};
        cardVector.push_back(ace);
        cardVector.push_back(king);

        std::vector<std::vector<std::string>> cardLines;
        for (const auto &card: cardVector) {
            cardLines.push_back(gameComponents.printHandHelper(card.getAscii(), '\n'));
        }

        for(size_t i = 0; i < cardLines[0].size(); ++i) {
            for(const auto& card : cardLines) {
                std::cout << card[i] << " ";
            }
            std::cout << "\n";
        }
    }
};