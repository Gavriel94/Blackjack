cmake_minimum_required(VERSION 3.25)
project(Blackjack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Blackjack main.cpp include/Card.h src/Card.cpp include/Deck.h src/Deck.cpp include/Player.h src/Player.cpp src/Tests/CardTest.cpp include/Dealer.h src/Dealer.cpp include/GameComponents.h src/GameComponents.cpp include/TestingSuite.h src/TestingSuite.cpp include/Tests/CardTest.h include/Tests/DealerTest.h src/Tests/DealerTest.cpp include/Tests/DeckTest.h src/Tests/DeckTest.cpp include/Tests/GameComponentsTest.h src/Tests/GameComponentsTest.cpp include/Tests/PlayerTest.h src/Tests/PlayerTest.cpp include/RunGame.h src/RunGame.cpp include/Tests/RunGameTest.h src/Tests/RunGameTest.cpp)
