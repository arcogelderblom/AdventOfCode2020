#include <iostream>

#include "FileReader.hpp"
#include "TobogganRide.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day03/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    TobogganRide ride;
    std::cout << "Puzzle one output: " << ride.countTrees(input, 3, 1) << std::endl;

    std::vector<std::pair<int, int>> options {{1,1}, 
                                              {3,1}, 
                                              {5,1}, 
                                              {7,1}, 
                                              {1,2}};
    long total = 1; // start with 1 so it has no influence in multiplication
    for (std::pair<int,int> option : options) {
        total *= ride.countTrees(input, option.first, option.second);
    }
    std::cout << "Puzzle two output: " << total << std::endl;
}