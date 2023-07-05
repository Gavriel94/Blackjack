//
// Created by Anthony Gavriel on 01/07/2023.
//

#include "../include/Player.h"

class PlayerTest {
public:
    static void testGetName() {
        Player bob = Player("Bob");
        Player alice = Player("Alice");

        assert(bob.getName() == "Bob");
        assert(alice.getName() == "Alice");
    }

    static void testAce() {
        Player bob = Player("Bob");

        int value = 0;
        std::cout << "\n";
        std::cout << "assert(value == 1)\n";
        value = bob.ace();
        assert(value == 1);
        std::cout << "\n";
        value = 0;
        std::cout << "assert(value == 11)\n";
        value = bob.ace();
        assert(value == 11);
        std::cout << "\n";
    }

    /**
     *
     * Tests receiveCard() and also:
     * - getHand()
     * - getBlackjack()
     * - isPlaying()
     * - getHandValue()
     *
     */
    static void testReceiveCard() {
        Player bob = Player("Bob");

        Card ace = Card(Card::SPADES, Card::ACE);
        Card king = Card(Card::HEARTS, Card::KING);

        std::vector<Card> testHand = {ace};

        std::cout << "\n";
        std::cout << "Testing for blackjack\n";
        std::cout << "assert(value == 11)\n";
        bob.receiveCard(ace);
        std::cout << "\n";

        assert(bob.getHand() == testHand);

        testHand.push_back(king);
        std::cout << "\n";
        bob.receiveCard(king);
        std::cout << "\n";
        assert(bob.getHand() == testHand);
        assert(bob.getBlackjack() == true);
        assert(bob.getPlaying() == false);
        assert(bob.getHandValue() == 21);

        testHand.clear();

        Player alice = Player("Alice");

        Card seven = Card(Card::CLUBS, Card::SEVEN);
        alice.receiveCard(seven);
        assert(alice.getPlaying() == true);
        assert(alice.getHandValue() == 7);
        std::cout << "\n";
    }

    static void testIsBust() {
        Player bob = Player("Bob");

        bob.receiveCard(Card(Card::HEARTS, Card::JACK));
        assert(bob.getHandValue() == 10);
        bob.receiveCard(Card(Card::HEARTS, Card::JACK));
        assert(bob.getHandValue() == 20);
        bob.receiveCard(Card(Card::HEARTS, Card::JACK));
        assert(bob.getHandValue() == 30);
        assert(bob.getPlaying() == false);
        assert(bob.isBust() == true);
    }
};