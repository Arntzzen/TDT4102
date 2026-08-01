//handout oving 2

#include "std_lib_facilities.h"
#include "AnimationWindow.h"


void inputAndPrintInteger() {
    // BEGIN: 1b

    // END: 1b
}

int inputInteger() {
    // BEGIN: 1c
    return 0;
    // END: 1c  
}

void printSumOfInputIntegers() {
    // BEGIN: 1d

    // END: 1d
}

bool isOdd(int n) {
    // BEGIN: 1f
    return 0;
    // END: 1f
}

void inputIntegersAndPrintSum() {
    // BEGIN: 2a

    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b
    int tall = 0;
    int sum = 0;
    std::cout << "Skriv inn et heltall. 0 vil avslutte programmet og skrive ut summen" << endl;
    std::cin >> tall;
    while (tall != 0) {
        sum += tall;
        std::cout << "Skriv inn neste tall" << endl;
        std::cin >> tall;
    }
    std::cout << "Summen av tallene du skrev inn er: " << sum << endl;
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
    // if (a == b == c) {
    //     std::cout << "Summen blir minus og ikke gyldig" << endl;
    //     return 0;
    // }
    double result = sqrt((b,2) - 4 * a * c);
    // std::cout << a << endl;
    // return a;
    std::cout << result << endl;
    return result;
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
    // BEGIN: 4
    // Alle deloppgaver i 4 skal løses her
    int winPosX = 150;
    int winPosY = 100;
    TDT4102::AnimationWindow window(winPosX, winPosY, 1000, 1000, "Pytagoras");
    TDT4102::Point vertex0 {450, 250};
    TDT4102::Point vertex1 {450, 450};
    TDT4102::Point vertex2 {650, 450};
    TDT4102::Color cTri = TDT4102::Color::black;
    window.draw_triangle(vertex0, vertex1, vertex2, cTri);
    TDT4102::Point square0 {450, 250};
    TDT4102::Point square1 {650, 50};
    TDT4102::Point square2 {850, 250};
    TDT4102::Point square3 {650, 450};
    TDT4102::Color cBigSquare = TDT4102::Color::blue;
    window.draw_quad(square0, square1, square2, square3, cBigSquare);
    TDT4102::Point square4 {450, 450};
    TDT4102::Point square5 {450, 650};
    TDT4102::Point square6 {650, 650};
    TDT4102::Point square7 {650, 450};
    TDT4102::Color cSmallSquare0 = TDT4102::Color::red;
    window.draw_quad(square4, square5, square6, square7, cSmallSquare0);
    TDT4102::Point square8 {450, 250};
    TDT4102::Point square9 {250, 250};
    TDT4102::Point square10 {250, 450};
    TDT4102::Point square11 {450, 450};
    TDT4102::Color cSmallSquare1 = TDT4102::Color::green;
    window.draw_quad(square8, square9, square10, square11, cSmallSquare1);
    window.wait_for_close();
    // END: 4
}

vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    std::vector<int> balance = {amount};
    double saldo;
    for (int i = 1; i < years; i++) {
        saldo = amount * pow(1 + static_cast<double>(rate) / 100, i);
        balance.push_back(static_cast<int>(saldo));
    }
    std::cout << balance[1] << endl;
    std::cout << balance[2] << endl;
    return balance;
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b

    // END: 5b
}

void menu() {
    while (1) {
        std::cout << "Menu\n"
        << "0.\t Quit\n"
        << "1.\t Summer fritt antall tall\n"
        << "2.\t abc-formelen. legg in tall for a, b og c\n"
        << "3.\t Tegn pytagoras læresetning\n"
        << "4.\t Beregner balanse (og skriver ut noen år)\n"
        << "Input: "
        << endl;

        int menu_choice;
        std::cin >> menu_choice;

        double a = 0;
        double b = 0;
        double c = 0;

        switch (menu_choice) {
        case 1:
            inputIntegersAndPrintSumUntilStopped();
            break;
        case 2:
            std::cout << "Skriv inn tall for a, b og c: " << endl;
            std::cin >> a >> b >> c;
            discriminant(a, b, c);
            break;
        case 3:
            pythagoras();
        case 4:
            int amount;
            int rate;
            int years;
            std::cout << "Skriv inn beløp: ";
            std::cin >> amount;
            std::cout << "Skriv inn årlig rente: ";
            std::cin >> rate;
            std::cout << "Skriv inn antall år: ";
            std::cin >> years;
            calculateBalance(amount, rate, years);
        default:
            return;
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
