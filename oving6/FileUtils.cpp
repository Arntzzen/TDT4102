#include "FileUtils.h"

void writeUserInputToFile(const std::string &path)
{
    // BEGIN: 1a
    std::ofstream outputStream{path};
    if (!outputStream) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }
    
    std::string nextWord;
    std::cout << "Write the words you want to write to the file " << path << std::endl;
    while (std::cin >> nextWord) {
        if (nextWord == "quit") {
            break;
        }
        outputStream << nextWord << std::endl;
    }
    // END: 1a
}

void addLineNumbers(const std::string &filename)
{
    // BEGIN: 1b
    std::ifstream inputStream{filename};
    if (!inputStream) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }
    std::string outputName = filename + ".linum";
    std::ofstream outputStream{outputName};
    if (!outputStream) {
        std::cout << "Could not create file!" << std::endl;
        return;
    }
    std::string line;
    int lineNumber = 1;
    while (std::getline(inputStream, line)) {
        outputStream << lineNumber << " " << line << std::endl;
        lineNumber++;
    }
    // END: 1b
}