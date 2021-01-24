#include <iostream>

#include <sstream>

#include "FileReader.hpp"
#include "Floor.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day24/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    Floor floor(input);
    std::cout << "Puzzle one output: " << floor.getBlackTiles().size() << std::endl;
    floor.processDays(100);
    std::cout << "Puzzle two output: " << floor.getBlackTiles().size() << std::endl;
}
