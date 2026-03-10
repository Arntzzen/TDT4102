#include "MeetingWindow.h"
#include <iostream>

MeetingWindow::MeetingWindow(TDT4102::Point position, int width, int height, const std::string& title):
	// BEGIN 5a
	AnimationWindow{},
	// END 5a

	// BEGIN 5e
	
	// END 5e

	// BEGIN 6a
	#define FOUR_A
	// END 6a
	
	// BEGIN 6b
	#define FOUR_B
	// END 6b

	dummyArgument{0}

{
	// Felles
	// BEGIN 5f
	
	// END 5f

	// BEGIN 5g
	
	// END 5g
	
	// BEGIN 6d
	
	// END 6d


	// Ny person
	#ifndef FOUR_A
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	#endif

	#ifndef FOUR_B
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);
	#endif
}

// Callbackfunksjoner
// BEGIN 5d

// END 5d

// BEGIN 6c

// END 6c


void MeetingWindow::attachPersonWidget(TDT4102::Widget& pw)
{
	add(pw);
	personWidgets.emplace_back(std::ref(pw));
}