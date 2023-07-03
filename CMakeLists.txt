cmake_minimum_required(VERSION 3.25)
project(Blackjack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Blackjack main.cpp include/Card.h src/Card.cpp include/Deck.h src/Deck.cpp include/Player.h src/Player.cpp Tests/UnitTests.cpp Tests/CardTest.cpp Tests/DeckTest.cpp Tests/PlayerTest.cpp include/Dealer.h src/Dealer.cpp Tests/DealerTest.cpp include/GameComponents.h src/GameComponents.cpp Tests/GameComponentsTest.cpp)
