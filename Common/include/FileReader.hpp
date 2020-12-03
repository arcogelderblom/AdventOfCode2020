#include <string>
#include <vector>

class FileReader {
private:
    std::string _filePath;
public:
    FileReader(std::string filePath);
    std::vector<std::string> fileToVector(std::string delimiter);
};