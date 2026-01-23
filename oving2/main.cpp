//handout oving 2

#include "std_lib_facilities.h"
#include "AnimationWindow.h"


void inputAndPrintInteger() {
    // BEGIN: 1b
    int tall;
    cout << "Skriv inn et tall: ";
    cin >> tall;
    cout << "du skrev tallet " << tall << endl;
    // END: 1b
}

int inputInteger() {
    // BEGIN: 1c
    int tall2;
    cout << "Skriv inn et tall: ";
    cin >> tall2;
    return tall2;
    // END: 1c  
}

void printSumOfInputIntegers() {
    // BEGIN: 1d
    int tall1 = inputInteger();
    int tall2 = inputInteger();
    int sum = tall1 + tall2;
    cout << "Summen av tallene: " << sum << endl;
    // END: 1d
}

bool isOdd(int n) {
    // BEGIN: 1f
    if ((n % 2) == 0) {
        return false;
    } else {
        return true;
    }
    // END: 1f
}

void inputIntegersAndPrintSum() {
    // BEGIN: 2a

    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b

    // END: 2b
}

double inputDouble() {
    // BEGIN: 2d
    return 0;
    // END: 2d
}

void convertNOKtoEUR() {
    // BEGIN: 2e

    // END: 2e
}

void printMultiplicationTable() {
    // BEGIN: 2g

    // END: 2g
}

double discriminant(double a, double b, double c) {
    // BEGIN: 3a
    return 0;
    // END: 3a
}

void printRealRoots(double a, double b, double c) {
    // BEGIN: 3b

    // END: 3b
}

void solveQuadraticEquations() {
    // BEGIN: 3c

    // END: 3c
}

void pythagoras() {
    // BEGIN: 4a
    // Alle deloppgaver i 4 skal løses her
    // END: 4a
}

vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    return {};
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b

    // END: 5b
}

void menu() {
	while (1) {
		std::cout << "Menu\n"
			<< "0.\t quit\n"
			<< "1.\t Skriv ut et tall - void\n"
			<< "2.\t Skriv ut et tall - int\n"
            << "3.\t Summer to tall\n"
			<< "Input: ";

		int menu_choice;
		std::cin >> menu_choice;
		
		switch (menu_choice)
		{
		case 1:
			inputAndPrintInteger();
			break;
        case 2: {
            int number = inputInteger();
            cout << "Du skrev tallet " << number << endl;
            break;
        }
        case 3: {
            printSumOfInputIntegers();
            break;
        }
		default:
			return; // quit program
			break;
		}
	}
}

int main() {
    // Oppgave 1a
    // Her kan du teste funksjonene dine ved hjelp av menysystem som beskrevet. 
    // NB: Denne delen av koden blir IKKE automatisk rettet.
    menu();
    return 0;
}
