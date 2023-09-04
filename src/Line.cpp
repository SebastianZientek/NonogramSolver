#include "Line.hpp"

Line::Line(const std::vector<SideNumberType> &sideNumbers, size_t length)
    : m_knownFields(length)
    , m_length(length)
{
    Generator gen(sideNumbers, length);
    while (gen.next())
    {
        m_possibleSeqs.push_back(gen.getSeq());
    }
}

std::vector<CellsVec> &Line::getSeqs() noexcept
{
    return m_possibleSeqs;
}

void Line::prepareKnownFields()
{
    std::fill(m_knownFields.begin(), m_knownFields.end(), 0xFF);
    for (const auto &seq : m_possibleSeqs)
    {
        std::transform(seq.begin(), seq.end(), m_knownFields.begin(), m_knownFields.begin(),
                       [](auto a, auto b) { return a & b; });
    }
}
