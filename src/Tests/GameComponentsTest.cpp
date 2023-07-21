/**
 * @file GameComponentsTest.cpp
 * @brief The implementation of the GameComponentsTest class and its functions.
 * @author Anthony Gavriel
 * @date 06/07/2023
 */

#include "../../include/Tests/GameComponentsTest.h"

/**
 * @brief Default constructor for GameComponentsTest.
 */
GameComponentsTest::GameComponentsTest() = default;

/**
 * @brief See declaration in GameComponentsTest.h for details.
 */
void GameComponentsTest::setupOnePlayer() {
    std::vector<Player> players = GameComponents::setupPlayers();

    assert(players.at(0).getName() == "Bob");
}

/**
 * @brief See declaration in GameComponentsTest.h for details.
 */
void GameComponentsTest::setupThreePlayers() {
    std::vector<Player> players = GameComponents::setupPlayers();

    assert(players.at(0).getName() == "Bob");
    assert(players.at(1).getName() == "Alice");
    assert(players.at(2).getName() == "Terry");
}

/**
 * @brief See declaration in GameComponentsTest.h for details.
 */
void GameComponentsTest::setupDeck() {
    Deck deckStatic = GameComponents::setupDeck();
    Deck deckInstance = Deck();

    assert(deckStatic.getSize() == deckInstance.getSize());
    assert(deckStatic.getDeck() == deckInstance.getDeck());

    deckStatic.shuffle();
    assert(deckStatic.getDeck() != deckInstance.getDeck());
}

/**
 * @brief See declaration in GameComponentsTest.h for details.
 */
void GameComponentsTest::setupDealer() {
    Dealer dealer = GameComponents::setupDealer();

    assert(dealer.getPlaying() == true);
}

/**
 * @brief See declaration in GameComponentsTest.h for details.
 */
void GameComponentsTest::printHandHelper() {
    Card ace = Card(Card::SPADES, Card::ACE);
    ace.setSpadeAscii(14);
    Card king = Card(Card::HEARTS, Card::KING);
    king.setHeartAscii(13);

    std::vector<Card> cardVector = {};
    cardVector.push_back(ace);
    cardVector.push_back(king);


    /**
     * For each card in their hand:
     * - Use printHandHelper() to get a line of the card.
     * - Append each line to cardLines.
     */
    std::vector<std::vector<std::string>> cardLines;
    cardLines.reserve(cardVector.size());
    for (const auto &card: cardVector) {
        cardLines.push_back(GameComponents::printHandHelper(card.getAscii(), '\n'));
    }

    /**
     * - For each line, iterate over ASCII representations in cardLines.
     * - Print the i-th line of the card.
     * - Continue until all lines are completed, resulting in side-by-side cards.
     */
    for(size_t i = 0; i < cardLines[0].size(); ++i) {
        for(const auto& card : cardLines) {
            std::cout << card[i] << " ";
        }
        std::cout << "\n";
    }
}



