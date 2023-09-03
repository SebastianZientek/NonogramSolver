#pragma once

#include <algorithm>
#include <iostream>  // TODO: remove
#include <utility>
#include <vector>

#include "Generator.hpp"
#include "Types.hpp"

class Line
{
public:
    Line(std::vector<SideNumberType> &&sideNumbers, size_t length)
        : m_knownFields(length)
        , m_length(length)
    {
        Generator gen(std::forward<std::vector<SideNumberType>>(sideNumbers), length);

        while (gen.next())
        {
            m_possibleSeqs.push_back(gen.getSeq());
        }
    }

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
        std::vector<CellType> buffer(m_length);
        std::erase_if(m_possibleSeqs,
                      [&buffer, patternIt](auto seq)
                      {
                          std::transform(seq.begin(), seq.end(), patternIt, buffer.begin(),
                                         [](auto a, auto b) { return a & b; });

                          return std::equal(buffer.begin(), buffer.end(), patternIt) == false;
                      });
    }

    std::vector<std::vector<CellType>> &getSeqs() noexcept
    {
        return m_possibleSeqs;
    }

private:
    std::vector<std::vector<CellType>> m_possibleSeqs;
    std::vector<CellType> m_knownFields;  // Fields that for sure should be white/black
    size_t m_length;

    void prepareKnownFields()
    {
        std::fill(m_knownFields.begin(), m_knownFields.end(), 0xFF);
        for (const auto &seq : m_possibleSeqs)
        {
            std::transform(seq.begin(), seq.end(), m_knownFields.begin(), m_knownFields.begin(),
                           [](auto a, auto b) { return a & b; });
        }
    }
};