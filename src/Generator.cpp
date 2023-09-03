
#include "Generator.hpp"

// Generator::Generator(std::vector<SideNumberType> &&sideNumbers, size_t seqSize)
//     : m_sideNumbers(sideNumbers)
// {
//     init(std::move(sideNumbers), seqSize);
// }

Generator::Generator(const std::vector<SideNumberType> &sideNumbers, size_t seqSize)
    : m_sideNumbers(sideNumbers)
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
