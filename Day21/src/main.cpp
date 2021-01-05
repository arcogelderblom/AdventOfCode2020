#include <iostream>

#include "FileReader.hpp"
#include "GroceryList.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day21/input.txt");
    std::vector<std::string> input = fileReader.fileToVector('\n');

    GroceryList groceryList(input);
    std::cout << "Puzzle one output: " << groceryList.getAmountOfNonAllergensInProducts() << std::endl;
    std::cout << "Puzzle two output: " << groceryList.getCanonicalDangerousIngredientList() << std::endl;
}
