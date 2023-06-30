#include <iostream>

#include "include/Card.h"
#include "include/Deck.h"

int main() {
    Deck deck;
    int deckSize = deck.getSize();
    std::cout << deckSize << std::endl;
    deck.printDeck();

    return 0;
}
