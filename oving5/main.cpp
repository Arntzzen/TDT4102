#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
int main()
{
	// Her skal du teste koden din underveis for å sikre deg at den funker slik forventet
	CardDeck c;
	// c.print();
	c.shuffle();
	// c.print();
	std::cout << c.drawCard().toString() << endl;
	return 0;
}