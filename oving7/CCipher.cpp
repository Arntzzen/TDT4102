#include "CCipher.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

DeCipher::DeCipher(const std::filesystem::path& filename) {
    std::ifstream fileStream{filename, std::ios::binary}; // std::ios::binary for å unngå rare newline-konverteringer på Windows
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
    }

    decodedMessage = new char[maxDecodedMessageLength];

    // Leser inn hele CSV-filen i én stor buffer.
    // Denne "dump hele fila i minnet"-metoden er ofte mye raskere
    // enn å lese ord for ord / linje for linje med strømmer.
    // (Ikke pensum, men nyttig å se at det finnes.)
    fileContentsSizeInBytes = std::filesystem::file_size(filename);
    csvFileContents = new char[fileContentsSizeInBytes];
    fileStream.read(csvFileContents, fileContentsSizeInBytes);
}

DeCipher::~DeCipher() {
    delete[] csvFileContents;
    delete[] decodedMessage;
}


void DeCipher::jumpToStartOfNextLine() {
    // BEGIN: 4b

    // END: 4b
}

void DeCipher::jumpToStartOfNextOddLine() {
    // BEGIN: 4c

    // END: 4c
}

void DeCipher::getLastWordOnCurrentLine(char*& lastWord, int& lengthOfWord) {
    // BEGIN: 4d

    // END: 4d
}

void DeCipher::decodeCipher(int ROTKey){
    // BEGIN: 4e

    // END: 4e
}

std::string DeCipher::getDecodedMessage() {
    // Må legge inn en nullterminator slik at std::string tolker C-stringen riktig
    decodedMessage[nextDecodedCharacterIndex] = '\0';
    return std::string(decodedMessage);
}

void DeCipher::benchmarkSpeed() {
    std::cout << "Running benchmark.." << std::endl;
    std::chrono::time_point<std::chrono::steady_clock> pointers_startTime = std::chrono::steady_clock::now();
    decodeCipher(99);
    std::chrono::time_point<std::chrono::steady_clock> pointers_endTime = std::chrono::steady_clock::now();
    double timeInSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(pointers_endTime - pointers_startTime).count() / 1000000000.0;
    std::cout << "Time taken to decode message using pointers: " << timeInSeconds << " seconds" << std::endl;

    std::chrono::time_point<std::chrono::steady_clock> strings_startTime = std::chrono::steady_clock::now();
    std::ifstream inStream{"csv/cipher.csv"};
    std::string line;
    std::string decodedMessage;
    while(std::getline(inStream, line)) {
        std::stringstream lineStream;
        lineStream << line;

        // Henter siste ord i linja (det som kommer etter siste komma)
        std::string word;
        while(std::getline(lineStream, word, ',')) {
            // Gjør ingenting: vi vil bare at "word" skal ende opp som siste felt
        }

        if(word.size() % 2 == 0) {
            // Vi dekoder ikke her (poenget er å sammenligne hastighet, ikke resultat)
            decodedMessage += word;
        }

        // Vi vil kaste annenhver linje, så vi leser én ekstra linje her
        std::getline(inStream, line);
    }

    std::chrono::time_point<std::chrono::steady_clock> strings_endTime = std::chrono::steady_clock::now();
    timeInSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(strings_endTime - strings_startTime).count() / 1000000000.0;
    std::cout << "Time taken to decode message using strings: " << timeInSeconds << " seconds" << std::endl;

    std::cout << decodedMessage << std::endl;
}