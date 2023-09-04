#include "FileParser.hpp"

#include <algorithm>
#include <sstream>

#include "Types.hpp"

std::vector<SideNumbersVec> &FileParser::getSideRows()
{
    return m_sideRows;
}

std::vector<SideNumbersVec> &FileParser::getSideCols()
{
    return m_sideCols;
}

bool FileParser::parse(std::istream &stream)
{
    auto *numbersVec = &m_sideRows;
    std::string line;
    bool dashAppeared = false;

    while (std::getline(stream, line))
    {
        if (isCorrect(line) == false || (dashAppeared && line == "-"))
        {
            return false;
        }

        if (line == "-")
        {
            numbersVec = &m_sideCols;
            dashAppeared = true;
            continue;
        }

        std::istringstream ss(line);
        SideNumbersVec sideNumbers;
        SideNumberType v;
        while (ss >> v)
        {
            sideNumbers.push_back(v);
        }
        numbersVec->push_back(sideNumbers);
    }

    // Dash not appeared? Data is corrupted
    if (dashAppeared == false)
    {
        return false;
    }

    return true;
}

bool FileParser::isCorrect(std::string stringView)
{
    auto checkIfCharAllowed = [](unsigned char ch)
    { return (std::isdigit(ch) || ch == '-' || ch == '\n' || ch == ' ') == false; };

    auto correct = std::none_of(stringView.begin(), stringView.end(), checkIfCharAllowed);
    return correct;
}