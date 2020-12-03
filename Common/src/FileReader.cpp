#include "FileReader.hpp"

#include <iostream>
#include <fstream>

FileReader::FileReader(std::string filePath): 
    _filePath(filePath)
{}

std::vector<std::string> FileReader::fileToVector(std::string delimiter) {
    std::string line;
    std::vector<std::string> result;
    std::ifstream myfile (_filePath);
    if (myfile.is_open()) {
        if (delimiter == "\n") {
            while (std::getline(myfile,line)) {
                result.push_back(line);
            }
        }
        myfile.close();
    }
    return result;
}
