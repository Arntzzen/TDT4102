
#include "std_lib_facilities.h"
#include "test.h"
void menu() {
	while(1) {
		cout << "Menu:\n"
		<< "0:\t Quit\n"
		<< "1:\t Inkrementer en verdi n ganger\n"
		<< "2:\t Inkrementer en verdi n ganger med referanse\n"
		<< "3:\t Bytt om på to tall og deres variabler\n"
		<< "Input: ";
		
		int menu_choice;
		cin >> menu_choice;

		switch(menu_choice) {
		case 1:
			testCallByValue();
			break;
		case 2:
			testCallByReference();
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
	menu();
	return 0;
}
