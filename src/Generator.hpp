#pragma once

#include <cassert>
#include <numeric>
#include <vector>
#include <numeric>

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

    template <typename T>
    void init(T &&sideNumbers, size_t seqSize)
    {
        auto blocksNum = std::max(sideNumbers.size(), static_cast<size_t>(1));
        size_t blocksWithSpaces
            = std::accumulate(sideNumbers.begin(), sideNumbers.end(), blocksNum - 1);

        assert(blocksWithSpaces <= seqSize && "definied blocks are bigger than line size");

        size_t spacesAfterBlocks = seqSize - blocksWithSpaces;
        size_t numbers = sideNumbers.size() + spacesAfterBlocks;
        size_t length = sideNumbers.size();

        m_seq.resize(seqSize);
        m_combination.setup(numbers, length);

        next();
    }
};