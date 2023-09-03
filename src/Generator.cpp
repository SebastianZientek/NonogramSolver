
#include "Generator.hpp"

#include <numeric>

Generator::Generator(std::vector<SideNumberType> &&sideNumbers, size_t seqSize)
    : m_sideNumbers(sideNumbers)
{
    size_t blocksWithSpaces
        = std::accumulate(sideNumbers.begin(), sideNumbers.end(), sideNumbers.size() - 1);
    size_t spacesAfterBlocks = seqSize - blocksWithSpaces;
    size_t numbers = sideNumbers.size() + spacesAfterBlocks;
    size_t length = sideNumbers.size();

    m_seq.resize(seqSize);
    m_combination.setup(numbers, length);

    next();
}

Generator::Generator(std::vector<SideNumberType> &sideNumbers, size_t seqSize)
    : m_sideNumbers(sideNumbers)
{
    size_t blocksWithSpaces
        = std::accumulate(sideNumbers.begin(), sideNumbers.end(), sideNumbers.size() - 1);
    size_t spacesAfterBlocks = seqSize - blocksWithSpaces;
    size_t numbers = sideNumbers.size() + spacesAfterBlocks;
    size_t length = sideNumbers.size();

    m_seq.resize(seqSize);
    m_combination.setup(numbers, length);

    next();
}

bool Generator::next()
{
    auto comb = m_combination.seq();
    std::vector<size_t> spaces(comb.size());
    std::adjacent_difference(comb.begin(), comb.end(), spaces.begin());

    auto blockIt = m_sideNumbers.begin();
    auto startIt = m_seq.begin();
    for (auto &s : spaces)
    {
        std::fill(startIt, startIt + s, W);
        startIt += s;
        std::fill(startIt, startIt + *blockIt, B);
        startIt += *blockIt;
        blockIt++;
    }
    std::fill(startIt, m_seq.end(), W);

    return std::exchange(m_nextAvailable, m_combination.next());
}

std::vector<CellType> &Generator::getSeq()
{
    return m_seq;
}

void Generator::init(size_t seqSize, size_t numbers, size_t length)
{
    m_seq.resize(seqSize);
    m_combination.setup(numbers, length);

    next();
}