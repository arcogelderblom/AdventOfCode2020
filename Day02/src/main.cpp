#include <iostream>

#include "FileReader.hpp"
#include "PasswordValidator.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day02/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    int validPasswords = 0;
    PasswordValidator validator;
    for (std::string line : input) {
        if (validator.checkValidityPuzzleOne(line)) {
            validPasswords++;
        }
    }

    std::cout << "Puzzle one output: " << validPasswords << std::endl;

    validPasswords = 0; // reset variable
    for (std::string line : input) {
        if (validator.checkValidityPuzzleTwo(line)) {
            validPasswords++;
        }
    }
    std::cout << "Puzzle two output: " << validPasswords << std::endl;
}