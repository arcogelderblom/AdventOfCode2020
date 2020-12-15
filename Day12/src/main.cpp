#include <iostream>

#include "FileReader.hpp"
#include "NavigationComputer.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day12/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    NavigationComputer computer(input);
    std::cout << "Puzzle one output: " << computer.getManhattanDistance(1) << std::endl;

    std::cout << "Puzzle two output: " << computer.getManhattanDistance(2) << std::endl;
}
