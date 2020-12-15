#include <iostream>

#include "FileReader.hpp"
#include "AdapterStacker.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day10/input.txt");
    std::vector<std::string> adapterJolts = fileReader.fileToVector('\n');
    
    AdapterStacker adapterStacker(adapterJolts);
    std::cout << "Puzzle one output: " << adapterStacker.getAmountDifference(1) * adapterStacker.getAmountDifference(3) << std::endl;
    
    std::cout << "Puzzle two output: " << adapterStacker.getAmountOfOptions() << std::endl;
}