#include <iostream>

#include "FileReader.hpp"
#include "Calculator.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day18/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    
    long long sum = 0;
    for (std::string expression : input) {
        Calculator calculator(expression);
        sum += calculator.getAnswer(1);
    }
    std::cout << "Puzzle one output: " << sum << std::endl;

    sum = 0;
    for (std::string expression : input) {
        Calculator calculator(expression);
        sum += calculator.getAnswer(2);
    }
    std::cout << "Puzzle two output: " << sum << std::endl;
}
