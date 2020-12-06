#include <iostream>

#include "FileReader.hpp"
#include "FormsProcessor.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day06/input.txt");
    std::vector<std::string> input = fileReader.fileToVectorDoubleNewLine();
    
    FormsProcessor processor;
    int sum = 0;
    for (std::string groupAnswers : input) {
        sum += processor.processGroup(groupAnswers, false);
    }

    std::cout << "Puzzle one output: " << sum << std::endl;

    sum = 0;
    for (std::string groupAnswers : input) {
        sum += processor.processGroup(groupAnswers, true);
    }
    std::cout << "Puzzle two output: " << sum << std::endl;
}