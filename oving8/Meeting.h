#pragma once

#include "Person.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

// BEGIN 4a
enum class Campus {};
// END 4a

// BEGIN 4b

// END 4b


// FJERN KOMMENTAR NAAR DU SKAL BRUKE
/*
const std::unordered_map<Campus, std::string> campusToString {
	{ Campus::trh, "Trondheim" },
	{ Campus::aal, "Aalesund" },
	{ Campus::gjo, "Gjovik"}
};

const std::unordered_map<std::string, Campus> stringToCampus {
	{ "Trondheim", Campus::trh },
	{ "Aalesund", Campus::aal },
	{ "Gjovik", Campus::gjo }
};
*/

class Meeting
{
private:
	// BEGIN 4c
	
	// END 4c
public:
	// BEGIN 4d
	
	// END 4d

	// BEGIN 4e
	
	// END 4e
	
	Meeting(int day, int startTime, int endTime, Campus location, const std::string& subject, Person* leader);

	// BEGIN 4h
	
	// END 4h

	// BEGIN 4i
	
	// END 4i

	// Vi ønsker ikke å tillate kopiering av Meeting-objekter
	Meeting(const Meeting&) = delete;
	Meeting& operator=(const Meeting&) = delete;
};

// BEGIN 4j

// END 4j