#include <iostream>

#include "FileReader.hpp"
#include "ImageAssembler.hpp"
#include "ImageTile.hpp"
#include "ImageProcessor.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day20/input.txt");
    std::vector<std::string> input = fileReader.fileToVectorDoubleNewLine();

    ImageAssembler assembler(input);
    assembler.assemble();
    std::vector<ImageTile> cornerTiles = assembler.getCornerTileIds();
    long long result = 1;
    for (ImageTile tile : cornerTiles) {
        result *= tile.getTileId();
    }
    std::cout << "Puzzle one output: " << result << std::endl;

    ImageProcessor processor(assembler.getImage());
    std::cout << "Puzzle two output: " << processor.getRoughWaters() << std::endl;
}
