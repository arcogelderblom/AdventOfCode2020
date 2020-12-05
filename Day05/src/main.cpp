#include <iostream>

#include "FileReader.hpp"
#include "BoardingPassScanner.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day05/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');
    
    BoardingPassScanner scanner;
    int highestSeatId = 0;
    for (std::string boardingPass : input) {
        int id = scanner.getSeatId(boardingPass);
        if (id > highestSeatId) {
            highestSeatId = id;
        }
    }

    std::cout << "Puzzle one output: " << highestSeatId << std::endl;

    std::vector<int> seatIds;
    for (std::string boardingPass : input) {
        seatIds.push_back(scanner.getSeatId(boardingPass));
    }

    std::sort(seatIds.begin(), seatIds.end());
    int mySeatId = seatIds[0];
    for (int i = 0; i < seatIds.size(); i++) {
        if (mySeatId + i != seatIds[i]) {
            mySeatId += i;
            break;
        }
    }
    std::cout << "Puzzle two output: " << mySeatId << std::endl;
}