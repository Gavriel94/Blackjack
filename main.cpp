#include <iostream>

#include "include/Card.h"
#include "include/Deck.h"

int main() {
    Deck deck;
    int deckSize = deck.getSize();
    std::cout << deckSize << std::endl;
    deck.printDeck();
    std::cout << "\n";

    if(deck.getSize() == 52) {
        std::cout << "Full deck instantiated.";
    }

    return 0;
}
