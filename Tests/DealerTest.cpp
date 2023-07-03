//
// Created by Anthony Gavriel on 03/07/2023.
//

#include "../include/Dealer.h"
#include "../include/Card.h"

class DealerTest {
public:
    static void testStartGame() {
        Dealer dealer = Dealer();
        Player player = Player("Bob");
        Deck deck = Deck();

        deck.create();
        deck.shuffle();

        std::vector<Player> players;
        players.push_back(player);

        dealer.startGame(deck, players);

        assert(dealer.getHand().size() == 1);

        for(auto p: players) {
            assert(p.getHand().size() == 2);
        }

        dealer = Dealer();
        player = Player("Bob");
        Player player2 = Player("Alice");
        deck = Deck();

        deck.create();
        deck.shuffle();

        players = {};
        players.push_back(player);
        players.push_back(player2);

        dealer.startGame(deck, players);

        assert(dealer.getHand().size() == 1);
        for(auto p: players) {
            assert(p.getHand().size() == 2);
        }
    }

    static void testReceiveCard() {
        // Game setup
        Dealer dealer = Dealer();
        Deck deck = Deck();
        Player player1 = Player("Bob");
        Player player2 = Player("Alice");

        std::vector<Player> players;
        players.push_back(player1);
        players.push_back(player2);

        deck.create();

        Card card = deck.getDeck().at(deck.getDeck().size() -1);
        Card c = deck.removeCard();
        dealer.receiveCard(c);
        assert(dealer.getHand().at(0) == card);
    }

    static void testHandValue() {
        Dealer dealer = Dealer();
        Deck deck = Deck();
        Player player1 = Player("Bob");
        std::vector<Player> players;
        players.push_back(player1);

        deck.create();
        deck.shuffle();

        Card c = deck.removeCard();
        dealer.receiveCard(c);

        if (c.getSuit() == "Ace") {
            assert(dealer.getHandValue() == 11);
        } else {
            assert(dealer.getHandValue() == stoi(c.getValue()));
        }
    }

    static void testBlackjack() {
        Dealer dealer = Dealer();

        Card ace = Card(Card::SPADES, Card::ACE);
        Card king = Card(Card::SPADES, Card::KING);

        dealer.receiveCard(ace);
        dealer.receiveCard(king);

        assert(dealer.getBlackjack() == true);
        std::cout << "\n";
    }

    static void testBust() {
        Dealer dealer = Dealer();

        Card seven = Card(Card::SPADES, Card::SEVEN);
        Card eight = Card(Card::CLUBS, Card::EIGHT);
        Card king = Card(Card::SPADES, Card::KING);

        dealer.receiveCard(seven);
        dealer.receiveCard(eight);
        dealer.receiveCard(king);

        assert(dealer.getBust() == true);
        std::cout << "\n";
    }

    static void testStick() {
        Dealer dealer = Dealer();

        Card seven = Card(Card::SPADES, Card::SEVEN);
        Card eight = Card(Card::CLUBS, Card::EIGHT);
        Card two = Card(Card::HEARTS, Card::TWO);

        dealer.receiveCard(seven);
        dealer.receiveCard(eight);
        dealer.receiveCard(two);

        assert(dealer.getBust() == false);
        assert(dealer.getPlaying() == false);
        assert(dealer.getHandValue() == 17);
        std::cout << "\n";
    }
};
