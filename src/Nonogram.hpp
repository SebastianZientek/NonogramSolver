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

    void solve()
    {
        m_data.resize(m_width * m_height, E);

        while (true)
        {
            {
                auto startIt = m_data.begin();
                for (auto &row : m_rows)
                {
                    row.removeImpossibleSequences(startIt);
                    row.paintKnownFields(startIt);
                    startIt += m_width;
                }
            }

            {
                size_t colId = 0;
                for (auto &col : m_cols)
                {
                    auto it = ColumnIterator<CellType, decltype(m_data.begin())>(
                        m_data.begin() + colId, m_width);
                    col.removeImpossibleSequences(it);
                    col.paintKnownFields(it);

                    colId++;
                }
            }

            bool isAllRowsOk = std::all_of(m_rows.begin(), m_rows.end(),
                                           [](auto &row) { return row.getSeqs().size() == 1; });
            bool isAllColsOk = std::all_of(m_cols.begin(), m_cols.end(),
                                           [](auto &col) { return col.getSeqs().size() == 1; });
            if (isAllRowsOk && isAllColsOk)
                break;
        }
    }

    void print()
    {
        for (size_t y = 0; y < m_rows.size(); ++y)
        {
            for (size_t x = 0; x < m_width; ++x)
            {
                auto cell = m_data[x + y * m_width];
                switch (cell)
                {
                case E:
                    std::cout << '_';
                    break;
                case B:
                    std::cout << 'X';
                    break;
                case W:
                    std::cout << ' ';
                    break;
                }
                std::cout << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    std::vector<Line> m_rows;
    std::vector<Line> m_cols;
    std::vector<CellType> m_data;

    size_t m_width;
    size_t m_height;
};