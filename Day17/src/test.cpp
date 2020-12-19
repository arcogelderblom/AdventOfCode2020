#include <iostream>

#include "FileReader.hpp"
#include "ConwayCubesV1.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day17/test.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    
    ConwayCubesV1 conwayCubes(input);
    conwayCubes.cycle(6);
    assert(conwayCubes.getActiveCubes() == 112);
}
