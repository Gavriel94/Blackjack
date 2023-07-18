//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../../include/Tests/DealerTest.h"

DealerTest::DealerTest() = default;

void DealerTest::receiveCard() {
    Dealer dealer = Dealer();
    Card card = Card(Card::CLUBS, Card::EIGHT);
    dealer.receiveCard(card);
    assert(dealer.getHand().at(0) == card);
}

void DealerTest::handValue() {
    Dealer dealer = Dealer();
    Deck deck = Deck();

    Card c = deck.removeCard();
    dealer.receiveCard(c);

    if(c.getValue() == "Ace") {
        assert(dealer.getHandValue() == 11);
    } else {
        assert(dealer.getHandValue() == std::stoi(c.getValue()));
    }
}

void DealerTest::blackjack() {
    Dealer dealer = Dealer();

    Card ace = Card(Card::SPADES, Card::ACE);
    Card king = Card(Card::SPADES, Card::KING);

    dealer.receiveCard(ace);
    dealer.receiveCard(king);

    assert(dealer.getBlackjack() == true);
    std::cout << "\n\n";
}

void DealerTest::bust() {
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

void DealerTest::stick() {
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