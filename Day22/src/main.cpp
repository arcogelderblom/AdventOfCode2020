#include <iostream>

#include <sstream>

#include "FileReader.hpp"
#include "CombatGame.hpp"
#include "RecursiveCombatGame.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day22/input.txt");
    std::vector<std::string> input = fileReader.fileToVectorDoubleNewLine();

    CombatGame combatGame(input);
    std::cout << "Puzzle one output: " << combatGame.getWinningPlayerScore() << std::endl;

    RecursiveCombatGame recursiveCombatGame(input);
    std::cout << "Puzzle two output: " << recursiveCombatGame.getWinningPlayerScore() << std::endl;
}
