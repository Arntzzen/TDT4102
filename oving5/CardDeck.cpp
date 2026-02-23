#include "CardDeck.h"
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

// BEGIN: 3b
CardDeck::CardDeck() {
    for (int s = 1; s <=4; s++) {
        for (int r = 2; r <= 14; r++) {
            cards.push_back(Card(
                static_cast<Suit>(s),
                static_cast<Rank>(r)
            ));
        }
    }
}
// END: 3b

// BEGIN: 3c
void CardDeck::swap(int a, int b) {
    std::swap(cards[a], cards[b]);
}
// END: 3c

// BEGIN: 3d
void CardDeck::print() {
    for (int i = 0; i <=51; i++) {
        cout << cards[i].toString() << endl;
    }
}
// END: 3d

// BEGIN: 3e
void CardDeck::shuffle() {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, 51);
    for (int i = 0; i <= 50/2; i++) {
        int num1 = distribution(generator);
        int num2 = distribution(generator);
        std::swap(cards[num1], cards[num2]);
    }
}
// END: 3e

// BEGIN: 3f
Card CardDeck::drawCard() {
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}
// END: 3f
