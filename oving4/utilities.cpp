#include "utilities.h"
#include <random>

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;

	return startValue;
}

// BEGIN: 1d
/*returverdi*/int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
	for (int i = 0; i < numTimes; i++)
		startValue += increment;

	return startValue;
}
// END: 1d

// BEGIN: 1e
/*returverdi*/void swapNumbers(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// END: 1e

// BEGIN: 2b
void printStudent(const Student& stud) {
	cout << "Navn: " << stud.name << endl;
	cout << "Studieretning: " << stud.studyProgram << endl;
	cout << "Alder: " << stud.age << endl;
}
// END: 2b

// BEGIN: 2c
bool isInProgram(const Student& stud, const string& retning) {
	if (stud.studyProgram == retning) {
		cout << "Studenten går på studieprogrammet!\n";
		return 1;
	}
	cout << "Studenten går ikke på studieprogrammet!\n";
	return stud.studyProgram == retning;
}
// END: 2c


// BEGIN: 3a
string randomizeString(int antallTegn, char upperLim, char lowerLim) {
	random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lowerLim, upperLim);
	string randomString;
	for (int i = 0; i < antallTegn; i++) {
		char c = static_cast<char>(distribution(generator));
		randomString += c;
	}
	return randomString;
}
// END: 3a

// BEGIN: 3c
string readInputToString(int n, char upperLim, char lowerLim) {
	string input;
	cout << "Skriv inn ordet: ";
	while(1) {
		cin >> input;
		if (input.length() != n) {
			cout << "Feil lengde, prøv igjen\n";
			continue;
		}
		bool ok = true;
		for (char c : input) {
			char cLower = tolower(c);
			if (cLower < tolower(lowerLim) || cLower > tolower(upperLim)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			for (char& c : input) {
				c = tolower(c);
			}
			return input;
		}
	}
}
// END: 3c

// BEGIN: 3d
///*returverdi*/ countChar(/*param 1: string, param 2: char*/)
// END: 3d
