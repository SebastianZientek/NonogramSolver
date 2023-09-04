#pragma once

#include <ostream>
#include <vector>

#include "ColumnIterator.hpp"
#include "Line.hpp"
#include "Types.hpp"

class Nonogram
{
public:
    Nonogram(const std::vector<std::vector<SideNumberType>> &rows,
             const std::vector<std::vector<SideNumberType>> &cols)
        : m_width(cols.size())
        , m_height(rows.size())
    {
        std::for_each(rows.begin(), rows.end(),
                      [this](const auto &row) { m_rows.emplace_back(row, m_width); });

        std::for_each(cols.begin(), cols.end(),
                      [this](const auto &col) { m_cols.emplace_back(col, m_height); });
    }

    void solve();
    void print(std::ostream &stream);

private:
    std::vector<Line> m_rows;
    std::vector<Line> m_cols;
    CellsVec m_data;

    size_t m_width;
    size_t m_height;

    void processRows();
    void processCols();
};