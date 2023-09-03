#pragma once

#include <cstdint>

using CellType = uint8_t;
using SideNumberType = size_t;

enum Field{
    E = 0b00000000,
    B = 0b00000001,
    W = 0b00000010
};