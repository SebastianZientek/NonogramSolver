#pragma once

#include <cstdint>
#include <vector>

enum Field
{
    E = 0b00000000,
    B = 0b00000001,
    W = 0b00000010
};

using CellType = uint8_t;
using CellsVec = std::vector<CellType>;
using SideNumberType = size_t;
using SideNumbersVec = std::vector<SideNumberType>;
