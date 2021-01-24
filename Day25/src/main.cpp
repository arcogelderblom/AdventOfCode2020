#include <iostream>

#include "FileReader.hpp"
#include "Crypto.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day25/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    Crypto crypto;
    long loopSize = crypto.calculateLoopSize(std::stoll(input[0]));
    long long value = 1;
    for (int loop = 0; loop < loopSize; loop++) {
        crypto.performLoop(value, std::stoll(input[1]));
    }
    std::cout << "Puzzle one output: " << value << std::endl;
}
