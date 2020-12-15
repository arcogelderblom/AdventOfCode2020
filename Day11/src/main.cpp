#include <iostream>

#include "FileReader.hpp"
#include "FloorPlan.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day11/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    std::vector<std::string> input2 = input;

    FloorPlan floorPlan(input);
    std::cout << "Puzzle one output: " << floorPlan.getOccupiedSeatsAmount(1) << std::endl;

    FloorPlan floorPlan2(input2);
    std::cout << "Puzzle two output: " << floorPlan2.getOccupiedSeatsAmount(2) << std::endl;
}
