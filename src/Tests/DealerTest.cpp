/**
 * @file DealerTest.cpp
 * @brief The implementation of the DealerTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */


#include "../../include/Tests/DealerTest.h"

/**
 * @brief Default constructor for DealerTest.
 */
DealerTest::DealerTest() = default;

/**
 * @brief See declaration in DealerTest.h for details.
 */
void DealerTest::receiveCard() {
    Dealer dealer = Dealer();
    Card card = Card(Card::CLUBS, Card::EIGHT);
    dealer.receiveCard(card);
    assert(dealer.getHand().at(0) == card);
}

/**
 * @brief See declaration in DealerTest.h for details.
 */
void DealerTest::handValue() {
    Dealer dealer = Dealer();
    Deck deck = Deck();

    deck.shuffle();
    Card c = deck.removeCard();
    dealer.receiveCard(c);

    if(c.getValue() == "Ace") {
        assert(dealer.getHandValue() == 11);
    } else {
        assert(dealer.getHandValue() == std::stoi(c.getValue()));
    }

    dealer = Dealer(); /** Reset dealer. */
    dealer.receiveCard(Card(Card::HEARTS, Card::KING));
    dealer.receiveCard(Card(Card::SPADES, Card::EIGHT));
    assert(dealer.getHandValue() == 18);
}

/**
 * @brief See declaration in DealerTest.h for details.
 */
void DealerTest::blackjack() {
    Dealer dealer = Dealer();

    Card ace = Card(Card::SPADES, Card::ACE);
    Card king = Card(Card::SPADES, Card::KING);

    dealer.receiveCard(ace);
    dealer.receiveCard(king);

    assert(dealer.getBlackjack() == true);
    std::cout << "\n\n";
}

/**
 * @brief See declaration in DealerTest.h for details.
 */
void DealerTest::getBust() {
    Dealer dealer = Dealer();

    Card seven = Card(Card::SPADES, Card::SEVEN);
    Card eight = Card(Card::CLUBS, Card::EIGHT);
    Card king = Card(Card::SPADES, Card::KING);

    dealer.receiveCard(seven);
    dealer.receiveCard(eight);
    dealer.receiveCard(king);

    assert(dealer.getBust() == true);
    std::cout << "\n\n";
}

/**
 * @brief See declaration in DealerTest.h for details.
 */
void DealerTest::getStick() {
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
    std::cout << "\n\n";
}