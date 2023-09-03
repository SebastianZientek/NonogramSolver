#pragma once

#include <vector>

#include "ColumnIterator.hpp"
#include "Line.hpp"

class Nonogram
{
public:
    Nonogram(size_t width, size_t height)
        : m_width(width)
        , m_height(height)
    {
    }

    template <typename T>
    void addRow(T &&sideNumbers)
    {
        m_rows.emplace_back(std::forward<T>(sideNumbers), m_width);
    }

    template <typename T>
    void addCol(T &&sideNumbers)
    {
        m_cols.emplace_back(std::forward<T>(sideNumbers), m_height);
    }

    void solve();
    void print();

private:
    std::vector<Line> m_rows;
    std::vector<Line> m_cols;
    std::vector<CellType> m_data;

    size_t m_width;
    size_t m_height;

    void processRows();
    void processCols();
};