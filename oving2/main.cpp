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
    int tall;
    cout << "Skriv inn et tall: ";
    cin >> tall;
    return tall;
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
    int n;
    cout << "Hvor mange tall ønsker du å summere?: ";
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int tall;
        cout << "Skriv inn tall " << i + 1 << ":";
        cin >> tall;
        sum += tall;
    }
    cout << "Summen av de " << n << " tallene er: " << sum << endl;
    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b
    int x;
    int sum = 0;
    while (1) {
        cout << "Skriv inn et tall (0 for å stoppe): ";
        cin >> x;
        if (x == 0) {
            break;
        }
        sum += x;
    }
    cout << "Summen av tallene er: " << sum << endl;
    // END: 2b
}

double inputDouble() {
    // BEGIN: 2d
    double tall;
    cout << "Skriv inn et tall: ";
    cin >> tall;
    return tall;
    // END: 2d
}

void convertNOKtoEUR() {
    // BEGIN: 2e
    cout << "Veksler NOK til EUR med ratio 10.5:1." << endl;
    double nok = inputDouble();
    while (nok < 0) {
        cout << "Tallet er negativt, skriv inn et nytt tall: ";
        cin >> nok;
    }
    double eur = nok / 10.5;
    cout << nok << "kr er " << fixed << setprecision(2) << "€" << eur << "." << endl;
    // END: 2e
}

void printMultiplicationTable() {
    // BEGIN: 2g
    int height;
    int width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    // END: 2g
}

double discriminant(double a, double b, double c) {
    // BEGIN: 3a
    double disc = pow(b, 2) - 4 * a * c;
    return disc;
    // END: 3a
}

void printRealRoots(double a, double b, double c) {
    // BEGIN: 3b
    double disc = discriminant(a, b, c);
    if (disc > 0) {
        double x1 = ((-b + sqrt(disc)) / (2 * a));
        double x2 = ((-b - sqrt(disc)) / (2 * a));
        cout << "Ligningen har 2 reelle løsninger:" << endl;
        cout << "x1 = " << x1 << setw(10) << "x2 = " << x2 << endl;
    } else if (disc == 0) {
        double x = (-b) / (2 * a);
        cout << "Ligningen har 1 reell løsning:" << endl;
        cout << "x = " << x << endl;
    } else {
        cout << "Ligningen har ingen reelle løsninger" << endl;
    }
    // END: 3b
}

void solveQuadraticEquations() {
    // BEGIN: 3c
    double a;
            double b;
            double c;
            cout << "Angi verdier for a, b og c i andregradsligningen:" << endl;
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
            cout << "c: ";
            cin >> c;
            printRealRoots(a, b, c);
    // END: 3c
}

void pythagoras() {
    // BEGIN: 4a
    // Alle deloppgaver i 4 skal løses her
    AnimationWindow win{50, 0, 1400, 800, "Pythagoras"};
    Point point1{600, 450};
    Point point2{800, 450};
    Point point3{600, 250};
    win.draw_triangle(point1, point2, point3, Color::red);
    win.draw_quad(point1, point2, Point{800, 700}, Point{600, 700}, Color::blue);
    win.draw_quad(point1, point3, Point{300, 250}, Point{300, 450}, Color::green);
    win.draw_quad(point3, point2, Point{975, 350}, Point{775, 150}, Color::yellow);
    win.wait_for_close();
    // END: 4a
}

vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    vector<int> balances;

    for (int i = 0; i <= years; i++) {
        double saldo = amount * pow((1 + static_cast<double>(rate) / 100), i);
        balances.push_back(static_cast<int>(saldo));
    }
    return balances;
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b
    cout << "År" << setw(5) << " " << "Saldo" << endl;
    for (int i = 0; i < balanceVec.size(); i++) {
        cout << i << setw(5) << " " << balanceVec[i] << endl;
    }
    // END: 5b
}

void menu() {
	while (1) {
		std::cout << "Menu\n"
			<< "0.\t Quit\n"
			<< "1.\t Skriv ut et tall - void\n"
			<< "2.\t Skriv ut et tall - int\n"
            << "3.\t Summer to tall\n"
            << "4.\t Summer n tall\n"
            << "5.\t Summer tall til du stopper\n"
            << "6.\t Skriv ut et desimaltall\n"
            << "7.\t Konverterer NOK til EUR\n"
            << "8.\t Skriver ut gangetabell\n"
            << "9.\t Finner reelle løsninger på andregradsligning\n"
            << "10.\t Tegner pythagoras læresetning\n"
            << "11.\t Renteberegning\n"
			<< "Input: ";

		int menu_choice;
		std::cin >> menu_choice;
		
		switch (menu_choice)
		{
		case 1:
			inputAndPrintInteger();
			break;
        case 2: {
            inputInteger();
            int number = inputInteger();
            cout << "Du skrev tallet " << number << endl;
            break;
        }
        case 3: {
            printSumOfInputIntegers();
            break;
        }
        case 4:
            inputIntegersAndPrintSum();
            break;
        case 5:
            inputIntegersAndPrintSumUntilStopped();
            break;
        case 6: {
            double desimaltall = inputDouble();
            cout << "Du skrev tallet: " << desimaltall << endl;
            break;
        }
        case 7:
            convertNOKtoEUR();
            break;
        case 8:
            printMultiplicationTable();
            break;
        case 9:
            solveQuadraticEquations();
            break;
        case 10:
            pythagoras();
            break;
        case 11: {
            int innskudd;
            int rente;
            int år;
            cout << "Skriv inn følgende:" << endl;
            cout << "Innskudd: ";
            cin >> innskudd;
            cout << "Rente: ";
            cin >> rente;
            cout << "antall år: ";
            cin >> år;
            vector<int> balances = calculateBalance(innskudd, rente, år);
            cout << "Saldo per år:" << endl;
            printBalance(balances);
            // for (int saldo : balances) {
            //    cout << saldo << endl;
            //}
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