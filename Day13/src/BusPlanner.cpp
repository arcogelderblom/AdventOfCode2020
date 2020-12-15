#include "BusPlanner.hpp"

#include <cmath>
#include <iostream>
#include <map>

BusPlanner::BusPlanner(std::string busIds) {
    while (busIds.find(',') != std::string::npos) {
        std::string busIdString = busIds.substr(0, busIds.find(','));
        if (busIdString != "x") {
            _busses.push_back(std::stoi(busIdString));
        }
        else {
            _busses.push_back(0);
        }
        busIds = busIds.substr(busIds.find(',') + 1);
    }
    if (busIds != "x") {
        _busses.push_back(std::stoi(busIds));
    }
    else {
        _busses.push_back(0);
    }
}

long BusPlanner::puzzleOne(int minutes) {
    std::vector<std::pair<int, int>> busIdWithTimeToWait;
    int lowestWaitTime = std::numeric_limits<int>::max();
    int fastestBusId = 0;

    for (int busId : _busses) {
        if (busId != 0) {
            int curMinutes = std::floor(minutes / busId) * busId + busId;
            busIdWithTimeToWait.push_back(std::make_pair(busId, curMinutes));
            if (curMinutes < lowestWaitTime) {
                lowestWaitTime = curMinutes;
                fastestBusId = busId;
            }
        }
    }

    return fastestBusId * (lowestWaitTime - minutes);
}

long long BusPlanner::puzzleTwo() {
    std::map<int, int> busIdWithDelta;
    for (int i = 0; i < _busses.size(); i++) {
        if (_busses[i] != 0) {
            busIdWithDelta[_busses[i]] = i;
        }
    }

    int maximumBusId = *std::max_element(_busses.begin(), _busses.end());

    std::vector<int> viableBusIds;
    for (int busId : _busses) {
        if (busId != 0) {
            viableBusIds.push_back(busId);
        }
    }

    long long startPoint;
    for (startPoint= 100000000000000; ; startPoint++) {
        if (startPoint%maximumBusId==0){
            break;
        }
    }

    for (long long minute = startPoint; ; minute += maximumBusId) {
        int amountCorrect = 0;
        for (int busId : viableBusIds) {
            if ((minute - (busIdWithDelta[maximumBusId] - busIdWithDelta[busId])) % busId == 0) {
                amountCorrect += 1;
            }
            else {
                break;
            }
        }
        if (amountCorrect == viableBusIds.size()) {
            return minute - busIdWithDelta[maximumBusId];
        }
    }
    
    return 0;
}
