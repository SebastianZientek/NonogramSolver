#include "Nonogram.hpp"

void Nonogram::processRows()
{
    auto startIt = m_data.begin();
    for (auto &row : m_rows)
    {
        row.removeImpossibleSequences(startIt);
        row.paintKnownFields(startIt);
        startIt += m_width;
    }
}

void Nonogram::processCols()
{
    size_t colId = 0;
    for (auto &col : m_cols)
    {
        auto it
            = ColumnIterator<CellType, decltype(m_data.begin())>(m_data.begin() + colId, m_width);
        col.removeImpossibleSequences(it);
        col.paintKnownFields(it);

        colId++;
    }
}

void Nonogram::solve()
{
    m_data.resize(m_width * m_height, E);

    while (true)
    {
        processRows();
        processCols();

        bool isAllRowsOk = std::all_of(m_rows.begin(), m_rows.end(),
                                       [](auto &row) { return row.getSeqs().size() == 1; });
        bool isAllColsOk = std::all_of(m_cols.begin(), m_cols.end(),
                                       [](auto &col) { return col.getSeqs().size() == 1; });
        if (isAllRowsOk && isAllColsOk)
            break;
    }
}

void Nonogram::print(std::ostream &stream)
{
    auto toChar = [](const auto &cell)
    {
        switch (cell)
        {
        case E:
            return '_';
        case B:
            return 'X';
        case W:
            return ' ';
        }
        return '?';
    };

    for (size_t y = 0; y < m_rows.size(); ++y)
    {
        for (size_t x = 0; x < m_width; ++x)
        {
            auto cell = m_data[x + y * m_width];
            stream << toChar(cell) << ' ';
        }
        stream << '\n';
    }
}
