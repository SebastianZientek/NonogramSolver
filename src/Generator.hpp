#pragma once

#include <cassert>
#include <numeric>
#include <vector>

#include "Combination.hpp"
#include "Types.hpp"

class Generator
{
public:
    Generator(const std::vector<SideNumberType> &sideNumbers, size_t seqSize);

    bool next();
    std::vector<CellType> &getSeq();

private:
    std::vector<SideNumberType> m_sideNumbers;
    std::vector<CellType> m_seq;
    Combination m_combination;
    bool m_nextAvailable = true;
};