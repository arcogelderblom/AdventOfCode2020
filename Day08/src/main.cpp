#include <iostream>

#include "FileReader.hpp"
#include "GameConsole.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day08/input.txt");
    std::vector<std::string> bootcode = fileReader.fileToVector('\n');
    
    GameConsole console(bootcode);
    console.findLoop();
    std::cout << "Puzzle one output: " << console.getAccumulator() << std::endl;
    
    console.fixLoop();
    console.play();
    std::cout << "Puzzle two output: " << console.getAccumulator() << std::endl;
}