#include <iostream>
#include <algorithm>

#include "FileReader.hpp"

std::vector<int> stringVecToIntVec(std::vector<std::string> input) {
    std::vector<int> result;
    for (std::string line : input) {
        result.push_back(std::stoi(line));
    }
    return result;
}

int puzzleOne(std::vector<int> input) {
    std::sort(input.begin(), input.end());

    for (int i = input.size()-1; i >= 0; i--) {
        for (int number : input) {
            if (input[i] + number == 2020) {
                return input[i] * number;
            }
            else if (input[i] + number > 2020) {
                break;
            }
        }
    }

    return 0;
}

int puzzleTwo(std::vector<int> input) {
    for (int i = 0; i < input.size()-3; i++) {
        for (int j = i+1; j < input.size()-2; j++) {
            for (int k = input.size()-1; k >= j; k--) {
                if (input[i] + input[j] + input[k] == 2020) {
                    return input[i] * input[j] * input[k];
                }
            }
        }
    }

    return 0;
}

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day01/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    
    std::cout << "Puzzle one: " << puzzleOne(stringVecToIntVec(input)) << std::endl;
    std::cout << "Puzzle two: " << puzzleTwo(stringVecToIntVec(input)) << std::endl;

    return 0;
}