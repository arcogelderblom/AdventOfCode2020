#include <iostream>

#include "FileReader.hpp"
#include "BusPlanner.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day13/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    BusPlanner planner(input[1]);
    std::cout << "Puzzle one output: " << planner.puzzleOne(std::stoi(input[0])) << std::endl;
    std::cout << "Puzzle two output: " << planner.puzzleTwo() << std::endl;
}
