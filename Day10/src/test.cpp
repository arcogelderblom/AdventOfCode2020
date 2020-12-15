#include <iostream>

#include "FileReader.hpp"
#include "AdapterStacker.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day10/test.txt");
    std::vector<std::string> adapterJolts = fileReader.fileToVector('\n');
    
    AdapterStacker adapterStacker(adapterJolts);
    
    assert(adapterStacker.getAmountDifference(1) == 22);
    assert(adapterStacker.getAmountDifference(3) == 10);
    assert(adapterStacker.getAmountDifference(1) * adapterStacker.getAmountDifference(3) == 220);

    assert(adapterStacker.getAmountOfOptions() == 19208);
}