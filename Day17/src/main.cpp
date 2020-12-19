#include <iostream>

#include "FileReader.hpp"
#include "ConwayCubesV1.hpp"
#include "ConwayCubesV2.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day17/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    
    ConwayCubesV1 conwayCubes(input);
    conwayCubes.cycle(6);
    std::cout << "Puzzle one output: " << conwayCubes.getActiveCubes() << std::endl;

    ConwayCubesV2 conwayCubesV2(input);
    conwayCubesV2.cycle(6);
    std::cout << "Puzzle two output: " << conwayCubesV2.getActiveCubes() << std::endl;
}
