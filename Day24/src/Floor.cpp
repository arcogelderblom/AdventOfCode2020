#include "Floor.hpp"

#include "HexTileCoordinate.hpp"

Floor::Floor(const std::vector<std::string> & instructions) {
    HexTile startingTile(_startingCoordinate);
    _floor[_startingCoordinate] = startingTile;
    for (const std::string & instruction : instructions) {
        applyInstruction(instruction);
    }
}

void Floor::applyInstruction(std::string instruction) {
    HexTile * currentTile = &_floor[_startingCoordinate];
    while (!instruction.empty()) {
        // get current instruction
        std::string currentInstruction;
        if (instruction[0] == 'e' || instruction[0] == 'w') {
            currentInstruction = instruction.substr(0, 1);
            instruction = std::string(instruction.begin() + 1, instruction.end());
        }
        else {
            currentInstruction = instruction.substr(0, 2);
            instruction = std::string(instruction.begin() + 2, instruction.end());
        }
        HexTileCoordinate newCoordinate = currentTile->getCoordinate();
        if (currentInstruction == "e") {
            if (currentTile->e == nullptr) {
                newCoordinate._q += 1;
                newCoordinate._s -= 1;
                if (_floor.find(newCoordinate) == _floor.end()) {
                    HexTile newTile(newCoordinate);
                    _floor[newCoordinate] = newTile;
                }
                currentTile->e = &_floor[newCoordinate];
            }
            currentTile = currentTile->e;
        }
        else if (currentInstruction == "se") {
            if (currentTile->se == nullptr) {
                newCoordinate._r += 1;
                newCoordinate._s -= 1;
                if (_floor.find(newCoordinate) == _floor.end()) {
                    HexTile newTile(newCoordinate);
                    _floor[newCoordinate] = newTile;
                }
                currentTile->se = &_floor[newCoordinate];
            }
            currentTile = currentTile->se;
        }
        else if (currentInstruction == "sw") {
            if (currentTile->sw == nullptr) {
                newCoordinate._q -= 1;
                newCoordinate._r += 1;
                if (_floor.find(newCoordinate) == _floor.end()) {
                    HexTile newTile(newCoordinate);
                    _floor[newCoordinate] = newTile;
                }
                currentTile->sw = &_floor[newCoordinate];
            }
            currentTile = currentTile->sw;
        }
        else if (currentInstruction == "w") {
            if (currentTile->w == nullptr) {
                newCoordinate._q -= 1;
                newCoordinate._s += 1;
                if (_floor.find(newCoordinate) == _floor.end()) {
                    HexTile newTile(newCoordinate);
                    _floor[newCoordinate] = newTile;
                }
                currentTile->w = &_floor[newCoordinate];
            }
            currentTile = currentTile->w;
        }
        else if (currentInstruction == "nw") {
            if (currentTile->nw == nullptr) {
                newCoordinate._r -= 1;
                newCoordinate._s += 1;
                if (_floor.find(newCoordinate) == _floor.end()) {
                    HexTile newTile(newCoordinate);
                    _floor[newCoordinate] = newTile;
                }
                currentTile->nw = &_floor[newCoordinate];
            }
            currentTile = currentTile->nw;
        }
        else if (currentInstruction == "ne") {
            if (currentTile->ne == nullptr) {
                newCoordinate._q += 1;
                newCoordinate._r -= 1;
                if (_floor.find(newCoordinate) == _floor.end()) {
                    HexTile newTile(newCoordinate);
                    _floor[newCoordinate] = newTile;
                }
                currentTile->ne = &_floor[newCoordinate];
            }
            currentTile = currentTile->ne;
        }
    }
    currentTile->flip();
}
#include <iostream>
void Floor::processDays(int days) {
    for (int day = 1; day <= days; day++) {
        std::map<HexTileCoordinate, HexTile> newFloor = _floor;
        for (std::pair<HexTileCoordinate, HexTile> coordinate : _floor) {
            HexTile currentTile = _floor[coordinate.first];
            checkAdjacentTiles(currentTile, newFloor);
        }
        _floor = newFloor;
        std::cout << "Day " << day << ": " << getBlackTiles().size() << std::endl;
    }
}

void Floor::checkAdjacentTiles(HexTile currentTile, std::map<HexTileCoordinate, HexTile> & newFloor, int depth) {
    int maxDepth = 1;
    std::vector<TileColor> neighbouringColors;
    HexTileCoordinate newCoordinate = currentTile.getCoordinate();
    if (currentTile.e == nullptr) {
        newCoordinate._q += 1;
        newCoordinate._s -= 1;
        if (_floor.find(newCoordinate) == _floor.end()) {
            neighbouringColors.push_back(TileColor::White);
            HexTile newTile(newCoordinate);
            newFloor[newCoordinate] = newTile;
            if (depth < maxDepth) {
                checkAdjacentTiles(newTile, newFloor, depth+1);
            }
            currentTile.e = &newFloor[newCoordinate];
        }
        else {
            currentTile.e = &_floor[newCoordinate];
            neighbouringColors.push_back(currentTile.e->getColor());
        }
    }
    else {
        neighbouringColors.push_back(currentTile.e->getColor());
    }

    newCoordinate = currentTile.getCoordinate();
    if (currentTile.se == nullptr) {
        newCoordinate._r += 1;
        newCoordinate._s -= 1;
        if (_floor.find(newCoordinate) == _floor.end()) {
            neighbouringColors.push_back(TileColor::White);
            HexTile newTile(newCoordinate);
            newFloor[newCoordinate] = newTile;
            if (depth < maxDepth) {
                checkAdjacentTiles(newTile, newFloor, depth+1);
            }
            currentTile.se = &newFloor[newCoordinate];
        }
        else {
            currentTile.se = &_floor[newCoordinate];
            neighbouringColors.push_back(currentTile.se->getColor());
        }
    }
    else {
        neighbouringColors.push_back(currentTile.se->getColor());
    }

    newCoordinate = currentTile.getCoordinate();
    if (currentTile.sw == nullptr) {
        newCoordinate._q -= 1;
        newCoordinate._r += 1;
        if (_floor.find(newCoordinate) == _floor.end()) {
            neighbouringColors.push_back(TileColor::White);
            HexTile newTile(newCoordinate);
            newFloor[newCoordinate] = newTile;
            if (depth < maxDepth) {
                checkAdjacentTiles(newTile, newFloor, depth+1);
            }
            currentTile.sw = &newFloor[newCoordinate];
        }
        else {
            currentTile.sw = &_floor[newCoordinate];
            neighbouringColors.push_back(currentTile.sw->getColor());
        }
    }
    else {
        neighbouringColors.push_back(currentTile.sw->getColor());
    }

    newCoordinate = currentTile.getCoordinate();
    if (currentTile.w == nullptr) {
        newCoordinate._q -= 1;
        newCoordinate._s += 1;
        if (_floor.find(newCoordinate) == _floor.end()) {
            neighbouringColors.push_back(TileColor::White);
            HexTile newTile(newCoordinate);
            newFloor[newCoordinate] = newTile;
            if (depth < maxDepth) {
                checkAdjacentTiles(newTile, newFloor, depth+1);
            }
            currentTile.w = &newFloor[newCoordinate];
        }
        else {
            currentTile.w = &_floor[newCoordinate];
            neighbouringColors.push_back(currentTile.w->getColor());
        }
    }
    else {
        neighbouringColors.push_back(currentTile.w->getColor());
    }

    newCoordinate = currentTile.getCoordinate();
    if (currentTile.nw == nullptr) {
        newCoordinate._r -= 1;
        newCoordinate._s += 1;
        if (_floor.find(newCoordinate) == _floor.end()) {
            neighbouringColors.push_back(TileColor::White);
            HexTile newTile(newCoordinate);
            newFloor[newCoordinate] = newTile;
            if (depth < maxDepth) {
                checkAdjacentTiles(newTile, newFloor, depth+1);
            }
            currentTile.nw = &newFloor[newCoordinate];
        }
        else {
            currentTile.nw = &_floor[newCoordinate];
            neighbouringColors.push_back(currentTile.nw->getColor());
        }
    }
    else {
        neighbouringColors.push_back(currentTile.nw->getColor());
    }

    newCoordinate = currentTile.getCoordinate();
    if (currentTile.ne == nullptr) {
        newCoordinate._q += 1;
        newCoordinate._r -= 1;
        if (_floor.find(newCoordinate) == _floor.end()) {
            neighbouringColors.push_back(TileColor::White);
            HexTile newTile(newCoordinate);
            newFloor[newCoordinate] = newTile;
            if (depth < maxDepth) {
                checkAdjacentTiles(newTile, newFloor, depth+1);
            }
            currentTile.ne = &newFloor[newCoordinate];
        }
        else {
            currentTile.ne = &_floor[newCoordinate];
            neighbouringColors.push_back(currentTile.ne->getColor());
        }
    }
    else {
        neighbouringColors.push_back(currentTile.ne->getColor());
    }

    int amountBlack = std::count_if(neighbouringColors.begin(), neighbouringColors.end(), [](TileColor tileColor){ return tileColor == TileColor::Black; });
    if (currentTile.getColor() == TileColor::Black && (amountBlack == 0 || amountBlack > 2)) {
        currentTile.flip();
    }
    else if (currentTile.getColor() == TileColor::White && amountBlack == 2) {
        currentTile.flip();
    }

    newFloor[currentTile.getCoordinate()] = currentTile;
}

std::vector<HexTile*> Floor::getBlackTiles() {
    std::vector<HexTile*> result;
    for (std::pair<HexTileCoordinate, HexTile> coordinateTilePair : _floor) {
        if (coordinateTilePair.second.getColor() == TileColor::Black) {
            result.push_back(&coordinateTilePair.second);
        }
    }
    return result;
}
