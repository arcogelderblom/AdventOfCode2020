#include <iostream>

#include "FileReader.hpp"
#include "Bag.hpp"
#include "LuggageProcessor.hpp"

int main(void) {
    std::vector<std::string> input {"light red bags contain 1 bright white bag, 2 muted yellow bags.",
                                    "dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
                                    "bright white bags contain 1 shiny gold bag.",
                                    "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
                                    "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
                                    "dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
                                    "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
                                    "faded blue bags contain no other bags.",
                                    "dotted black bags contain no other bags."};

    LuggageProcessor processor(input);
    assert(processor.getColorPossibilitiesFor("shiny gold") == 4);

    // sum = 0;
    // for (std::string groupAnswers : input) {
    //     sum += processor.processGroup(groupAnswers, true);
    // }
    // std::cout << "Puzzle two output: " << sum << std::endl;
}