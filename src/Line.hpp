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
        for (const auto &field: m_knownFields)
        {
            if (field != E)
            {
                *outIt = field;
            }
            outIt++;
        }
    }

private:
    std::vector<std::vector<CellType>> m_possibleSeqs;
    std::vector<CellType> m_knownFields;  // Fields that for sure should be white/black

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