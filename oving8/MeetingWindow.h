#pragma once

#include "AnimationWindow.h"
#include "Meeting.h"
#include "Person.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include "widgets/DropdownList.h"

#include <string>
#include <vector>
#include <functional>


// Meeting GUI
class MeetingWindow : public TDT4102::AnimationWindow
{
	public:
	// BEGIN 5c
	
	// END 5c

	MeetingWindow(TDT4102::Point position, int width, int height, const std::string& title);
	
	// Avslutt knapp
	// BEGIN 5e
	
	// END 5e

	// Callback-funksjoner
	// BEGIN 5d
	
	// END 5d


	// Person
	// BEGIN 6a
	
	// END 6a

	// BEGIN 6b
	
	// END 6b


	// Personer
	// BEGIN 6c
	
	// END 6c

	int dummyArgument;

	// Hjelpefunksjoner og variabler
	void attachPersonWidget(TDT4102::Widget& pw);
	std::vector<std::reference_wrapper<TDT4102::Widget>> personWidgets;
};
