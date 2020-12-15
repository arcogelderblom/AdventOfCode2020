#pragma once

#include <string>
#include <vector>

class BusPlanner {
private:
    std::vector<int> _busses;
public:
    BusPlanner(std::string busIds);
    long puzzleOne(int minutes);
    long long puzzleTwo();
};