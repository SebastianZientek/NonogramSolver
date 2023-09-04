#pragma once

#include <istream>
#include <string>
#include <vector>

#include "Types.hpp"

/*
    Parsing data for Nonogram,

    Data format:
    <rows line by line>
    -
    <col line by line>

    Example:
    1, 1, 1
    3, 4
    -
    3, 5
*/

class FileParser
{
public:
    std::vector<SideNumbersVec> &getSideRows();
    std::vector<SideNumbersVec> &getSideCols();
    bool parse(std::istream &stream);

private:
    std::vector<SideNumbersVec> m_sideRows;
    std::vector<SideNumbersVec> m_sideCols;

    bool isCorrect(std::string stringView);
};