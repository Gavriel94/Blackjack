//
// Created by Anthony Gavriel on 06/07/2023.
//

#include "../../include/Tests/GameComponentsTest.h"

GameComponentsTest::GameComponentsTest() = default;

void GameComponentsTest::setupOnePlayer() {
    std::vector<Player> players = GameComponents::setupPlayers();

    assert(players.at(0).getName() == "Bob");
}

void GameComponentsTest::setupThreePlayers() {
    std::vector<Player> players = GameComponents::setupPlayers();

    assert(players.at(0).getName() == "Bob");
    assert(players.at(1).getName() == "Alice");
    assert(players.at(2).getName() == "Terry");
}

void GameComponentsTest::setupDeck() {
    Deck deckStatic = GameComponents::setupDeck();
    Deck deckInstance = Deck();

    assert(deckStatic.getSize() == deckInstance.getSize());
    assert(deckStatic.getDeck() == deckInstance.getDeck());

    deckStatic.shuffle();
    assert(deckStatic.getDeck() != deckInstance.getDeck());
}

void GameComponentsTest::setupDealer() {
    Dealer dealer = GameComponents::setupDealer();

    assert(dealer.getPlaying() == true);
}

void GameComponentsTest::printHandHelper() {
    Card ace = Card(Card::SPADES, Card::ACE);
    ace.setSpadeAscii(14);
    Card king = Card(Card::HEARTS, Card::KING);
    king.setHeartAscii(13);

    std::vector<Card> cardVector = {};
    cardVector.push_back(ace);
    cardVector.push_back(king);

    std::vector<std::vector<std::string>> cardLines;
    cardLines.reserve(cardVector.size());
    for (const auto &card: cardVector) {
        cardLines.push_back(GameComponents::printHandHelper(card.getAscii(), '\n'));
    }

    for(size_t i = 0; i < cardLines[0].size(); ++i) {
        for(const auto& card : cardLines) {
            std::cout << card[i] << " ";
        }
        std::cout << "\n";
    }
}



