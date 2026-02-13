
#include "std_lib_facilities.h"
#include "test.h"
#include "utilities.h"

void menu() {
	while(1) {
		cout << "Menu:\n"
		<< "0:\t Quit\n"
		<< "1:\t Inkrementer en verdi n ganger\n"
		<< "2:\t Inkrementer en verdi n ganger med referanse\n"
		<< "3:\t Bytt om på to tall og deres variabler\n"
		<< "4:\t Skriv ut en students navn, studieretning og alder\n"
		<< "5:\t Sjekk om studenten går det studieprogrammet\n"
		<< "6:\t Generer en string med tilfeldige bokstaver\n"
		<< "7:\t Få en tilfeldig string på 8 bokstaver\n"
		<< "8:\t Les input til string!\n"	// Har gjort til og med oppgave 3c)
		<< "Input: ";
		
		int menu_choice;
		cin >> menu_choice;

		switch(menu_choice) {
		case 1:
			testCallByValue();
			break;
		case 2:
			testCallByReference();
			break;
		case 3:
			int a;
			int b;
			cout << "a: ";
			cin >> a;
			cout << "b: ";
			cin >> b;
			swapNumbers(a, b);
			cout << "a = " << a << endl;
			cout << "b = " << b;
			break;
		case 4: {
			Student stud;
			cout << "Navn: ";
			cin >> stud.name;
			cout << "Studieretning: ";
			cin >> stud.studyProgram;
			cout << "Alder: ";
			cin >> stud.age;
			printStudent(stud);
			break;
		}
		case 5: {
			Student stud;
			string retning;
			cout << "Definer studieprogram: ";
			cin >> stud.studyProgram;
			cout << "Skriv inn studieretning som skal sjekkes mot: ";
			cin >> retning;
			isInProgram(stud, retning);
			break;
		}
		case 6: {
			int antallTegn;
			char upperLim;
			char lowerLim;
			cout << "Skriv inn antall tegn: ";
			cin >> antallTegn;
			cout << "Skriv inn bokstaven i øvre grense: ";
			cin >> upperLim;
			cout << "Skriv inn bokstaven i nedre grense: ";
			cin >> lowerLim;
			cout << randomizeString(antallTegn, upperLim, lowerLim);
			break;
		}
		case 7:
			testString();
			break;
		case 8: {		// Har gjort til og med oppgave 3c)
			int n;
			char upperLim;
			char lowerLim;
			cout << "Definer lengde n: ";
			cin >> n;
			cout << "Definer bokstav for øvre grense: ";
			cin >> upperLim;
			cout << "Definer bokstav for nedre grense: ";
			cin >> lowerLim;
			cout << readInputToString(n, upperLim, lowerLim);
		}
		default:
			return;
			break;
		}
	}
}
int main()
{

	// Her kan du teste koden og funksjonene dine, 
	// Ingenting som skrives her blir automatisk rettet, du tester her for din egen del
	menu();			// Har gjort til og med oppgave 3c)
	return 0;
}
