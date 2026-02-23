#pragma once
#include "Card.h"
#include <vector>

// BEGIN: 3a
class CardDeck {
public:
    std::vector<Card> cards;
    CardDeck();
    void print();
    void shuffle();
    Card drawCard();
private:
    void swap(int a, int b);
};
// END: 3a
