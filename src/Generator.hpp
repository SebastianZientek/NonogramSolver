#pragma once

#include <vector>

#include "Combination.hpp"
#include "Types.hpp"

class Generator
{
public:
    Generator(const std::vector<SideNumberType> &sideNumbers, size_t seqSize);

    bool next();
    CellsVec &getSeq();

private:
    std::vector<SideNumberType> m_sideNumbers;
    CellsVec m_seq;
    Combination m_combination;
    bool m_nextAvailable = true;
};