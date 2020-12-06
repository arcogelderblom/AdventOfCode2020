#include <iostream>

#include "FileReader.hpp"
#include "PassportValidator.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day04/input.txt");
    std::vector<std::string> input = fileReader.fileToVectorDoubleNewLine();
    for (std::string & line : input) {
        while (line.find('\n') != std::string::npos) {
            line.replace(line.find('\n'), 1, " ");   
        }
    }

    PassportValidator validator;
    int validPassports = 0;
    for (std::string passport : input) {
        if (validator.validate(passport)) {
            validPassports++;
        }
    }

    std::cout << "Puzzle one output: " << validPassports << "/" << input.size() << std::endl;

    validPassports = 0;
    for (std::string passportAsString : input) {
        if (validator.validate(passportAsString)) {
            Passport passport(passportAsString);
            if (validator.validate(passport)) {
                validPassports++;
            }
        }
    }

    std::cout << "Puzzle two output: " << validPassports << "/" << input.size() << std::endl;

}