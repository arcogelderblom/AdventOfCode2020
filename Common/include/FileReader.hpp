#pragma once

#include <string>
#include <vector>

class FileReader {
private:
    std::string _filePath;
public:
    FileReader(std::string filePath);
    std::vector<std::string> fileToVector(char delimiter);
    std::vector<std::string> fileToVectorDoubleNewLine();
};