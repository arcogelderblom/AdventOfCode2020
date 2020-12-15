#include <iostream>

#include "FileReader.hpp"
#include "Decoder.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day14/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    Decoder decoder(input, 1);
    std::cout << "Puzzle one output: " << decoder.getSumOfMemoryValues() << std::endl;

    Decoder decoder2(input, 2);
    std::cout << "Puzzle two output: " << decoder2.getSumOfMemoryValues() << std::endl;
}
