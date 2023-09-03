#pragma once

#include <vector>

#include "Combination.hpp"
#include "Types.hpp"

class Generator
{
public:
    Generator(std::vector<SideNumberType> &&sideNumbers, size_t seqSize);
    Generator(std::vector<SideNumberType> &sideNumbers, size_t seqSize);

    bool next();
    std::vector<CellType> &getSeq();

private:
    std::vector<SideNumberType> m_sideNumbers;
    std::vector<CellType> m_seq;
    Combination m_combination;
    bool m_nextAvailable = true;

    void init(size_t seqSize, size_t numbers, size_t length);
};