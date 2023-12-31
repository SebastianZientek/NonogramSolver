#pragma once

#include <algorithm>
#include <vector>

#include "Generator.hpp"
#include "Types.hpp"

class Line
{
public:
    Line(const std::vector<SideNumberType> &sideNumbers, size_t length);

    void paintKnownFields(auto begin)
    {
        prepareKnownFields();

        auto outIt = begin;
        for (const auto &field : m_knownFields)
        {
            if (field != E)
            {
                *outIt = field;
            }
            outIt++;
        }
    }

    void removeImpossibleSequences(auto patternIt)
    {
        CellsVec buffer(m_length);
        auto predicate = [&buffer, patternIt](auto seq)
        {
            std::transform(seq.begin(), seq.end(), patternIt, buffer.begin(),
                           [](auto a, auto b) { return a & b; });

            return std::equal(buffer.begin(), buffer.end(), patternIt) == false;
        };

        std::erase_if(m_possibleSeqs, predicate);
    }

    std::vector<CellsVec> &getSeqs() noexcept;

private:
    std::vector<CellsVec> m_possibleSeqs;
    CellsVec m_knownFields;  // Fields that for sure should be white/black
    size_t m_length;

    void prepareKnownFields();
};