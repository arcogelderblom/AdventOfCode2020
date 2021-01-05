#include <iostream>

#include <sstream>

#include "FileReader.hpp"
#include "MessageProcessor.hpp"

int main(void) {
    FileReader fileReader("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day19/input.txt");
    std::vector<std::string> input = fileReader.fileToVectorDoubleNewLine();
    std::vector<std::string> rules, messages;
    
    std::stringstream ssRules(input[0]);
    std::string rule;
    while(std::getline(ssRules,rule)){
        rules.push_back(rule);
    }

    std::stringstream ssMessages(input[1]);
    std::string message;
    while(std::getline(ssMessages,message)){
        messages.push_back(message);
    }
    MessageProcessor processor(rules);
    std::cout << "Puzzle one output: " << processor.getMatchingMessages(messages, 0, false).size() << std::endl;

    FileReader fileReader2("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2020/Day19/input2.txt");
    std::vector<std::string> input2 = fileReader2.fileToVectorDoubleNewLine();
    
    std::stringstream ssRules2(input2[0]);
    rules = std::vector<std::string>();
    while(std::getline(ssRules2,rule)){
        rules.push_back(rule);
    }

    std::stringstream ssMessages2(input2[1]);
    messages = std::vector<std::string>();
    while(std::getline(ssMessages2,message)){
        messages.push_back(message);
    }
    MessageProcessor processor2(rules);
    std::cout << "Puzzle two output: " << processor2.getMatchingMessages(messages, 0, true).size() << std::endl;
    // for (std::string msg : processor2.getMatchingMessages(messages, 0)) {
    //     std::cout << msg << std::endl;
    // }
}
