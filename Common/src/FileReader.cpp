#include "FileReader.hpp"

#include <iostream>
#include <fstream>

FileReader::FileReader(std::string filePath): 
    _filePath(filePath)
{}

std::vector<std::string> FileReader::fileToVector(char delimiter) {
    std::vector<std::string> result;
    std::string line;
    std::ifstream myfile (_filePath);
    if (myfile.is_open()) {
        while (std::getline(myfile,line, delimiter)) {
            result.push_back(line);
        }
        myfile.close();
    }
    return result;
}

std::vector<std::string> FileReader::fileToVectorDoubleNewLine() {
    std::vector<std::string> result; 
    std::string line;
    std::string completeLine;
    std::ifstream myfile (_filePath);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            std::getline(myfile,line);

            if (line == "" || line == "\0")  {
                result.push_back(completeLine);
                completeLine = "";
            }
            else {
                if (completeLine.empty()) {
                    completeLine = line;
                }
                else {
                    completeLine += "\n" + line;
                }
            }
        }
                result.push_back(completeLine);
        myfile.close();
    }
    return result;
}
