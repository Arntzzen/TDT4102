#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <print>
#include "Atoi.h"

using namespace std;

int Atoi::isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int Atoi::characterToDigit(char c){
    // Forutsetter at c er et siffer ('0'...'9')
    return (c - '0'); 
}

const char* Atoi::parseInt(const char* ptr, int* outIntVal) {
    // BEGIN: 2a

    //int sign
    int sign;
    //int num
    int num;

    //Hvis første tegn i ptr er '-', sett sign til -1, så gå til neste tegn
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    } else {
        //Ellers, sett sign til +1
        sign = 1;
    }

    //Sett num til 0
    num = 0;
    //While nåværende char er en int, konverter char til tall og legg til
    //tallet i slutten av "num". Gang tallet med 10, så gå til neste tegn
    while (isDigit(*ptr)) {
        num = (num * 10) + characterToDigit(*ptr);
        ptr++;
    }
    //*outIntVal peker nå på sign * num
    *outIntVal = sign * num;

    //Returner peker til første tegn etter tallet

    return ptr; // DENNE RETURNVERDIEN KAN DERE ENDRE
    // END: 2a
}
