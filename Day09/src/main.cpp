#include <iostream>

#include "FileReader.hpp"
#include "XMASEncryptor.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day09/input.txt");
    std::vector<std::string> XMASdata = fileReader.fileToVector('\n');
    
    XMASEncryptor encryptor(XMASdata);
    std::cout << "Puzzle one output: " << encryptor.getIncorrectNumber() << std::endl;
    
    std::cout << "Puzzle two output: " << encryptor.getEncryptionWeakness() << std::endl;
}