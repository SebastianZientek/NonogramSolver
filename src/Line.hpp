#pragma once

#include <algorithm>
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
        Generator gen(std::move(sideNumbers), length);
        generateSeqs(gen);
    }

    Line(std::vector<SideNumberType> &sideNumbers, size_t length)
        : m_knownFields(length)
        , m_length(length)
    {
        Generator gen(sideNumbers, length);
        generateSeqs(gen);
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
        auto predicate = [&buffer, patternIt](auto seq)
        {
            std::transform(seq.begin(), seq.end(), patternIt, buffer.begin(),
                           [](auto a, auto b) { return a & b; });

            return std::equal(buffer.begin(), buffer.end(), patternIt) == false;
        };

        std::erase_if(m_possibleSeqs, predicate);
    }

    std::vector<std::vector<CellType>> &getSeqs() noexcept;

private:
    std::vector<std::vector<CellType>> m_possibleSeqs;
    std::vector<CellType> m_knownFields;  // Fields that for sure should be white/black
    size_t m_length;

    void prepareKnownFields();
    void generateSeqs(Generator &gen);
};