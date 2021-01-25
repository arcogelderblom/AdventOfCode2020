#include <iostream>

#include "FileReader.hpp"
#include "Bag.hpp"
#include "LuggageProcessor.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day07/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    
    LuggageProcessor processor(input);
    std::cout << "Puzzle one output: " << processor.getColorPossibilitiesFor("shiny gold") << std::endl;
    
    std::cout << "Puzzle two output: " << processor.getAmountBagsInBag("shiny gold") << std::endl;
}