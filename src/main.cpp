#include <algorithm>
#include <array>
#include <bitset>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>

#include "ColumnIterator.hpp"
#include "Combination.hpp"
#include "Generator.hpp"
#include "Line.hpp"
#include "Types.hpp"

int main(int argc, char **argv)
{
    // std::vector<std::vector<SideNumberType>> sideRows{
    //     {3, 3}, {2, 4, 2}, {1, 2, 1}, {1, 1}, {2, 2}, {3, 3}, {3, 3}, {6}, {4}, {2},
    // };

    // std::vector<std::vector<SideNumberType>> sideCols{
    //     {5}, {2, 3}, {1, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {1, 3}, {2, 3}, {5},
    // };

    std::vector<std::vector<SideNumberType>> sideRows{
        {5},
        {3, 3},
        {2, 5},
        {1, 4, 2},
        {5, 2},
        {9, 1},
        {3, 4},
        {1, 2, 4, 1},
        {4, 5, 2},
        {3, 4, 2},
        {2, 2, 1},
        {5, 3, 1},
        {3, 4, 3},
        {6, 2},
        {4, 4, 1},
        {1, 1, 2, 1, 1},
        {3, 1, 1},
        {2, 8},
        {2},
        {10}
    };

    std::vector<std::vector<SideNumberType>> sideCols{
        {2, 3},
        {2, 4},
        {1, 10},
        {2, 5, 6},
        {1, 3, 4, 3},
        {1, 3, 3, 7},
        {1, 4, 3, 1, 1},
        {6, 2, 2, 3, 1},
        {3, 1, 3, 1, 2, 1, 1},
        {2, 1, 2, 1, 1, 1, 1},
        {2, 4, 2, 1, 1, 1},
        {2, 2, 1, 2, 1, 1},
        {3, 2, 1, 1},
        {4, 2, 1, 1},
        {10, 1}
    };

    std::vector<Line> rows;
    std::vector<Line> cols;

    std::for_each(sideRows.begin(), sideRows.end(),
                  [&rows, &sideCols](auto &sideRow)
                  { rows.emplace_back(std::move(sideRow), sideCols.size()); });

    std::for_each(sideCols.begin(), sideCols.end(),
                  [&cols, &sideRows](auto &sideCol)
                  { cols.emplace_back(std::move(sideCol), sideRows.size()); });

    std::vector<CellType> data(rows.size() * cols.size(), E);

    while (true)
    {
        {
            auto startIt = data.begin();
            for (auto &row : rows)
            {
                row.removeImpossibleSequences(startIt);
                row.paintKnownFields(startIt);
                startIt += cols.size();
            }
        }

        {
            size_t colId = 0;
            for (auto &col : cols)
            {
                auto it = ColumnIterator<CellType, decltype(data.begin())>(data.begin() + colId,
                                                                           cols.size());
                col.removeImpossibleSequences(it);
                col.paintKnownFields(it);

                colId++;
            }
        }

        for (size_t y = 0; y < rows.size(); ++y)
        {
            for (size_t x = 0; x < cols.size(); ++x)
            {
                auto cell = data[x + y * cols.size()];
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

        std::cout << "\n\n";

        bool isAllRowsOk = std::all_of(rows.begin(), rows.end(),
                                       [](auto &row) { return row.getSeqs().size() == 1; });
        bool isAllColsOk = std::all_of(cols.begin(), cols.end(),
                                       [](auto &col) { return col.getSeqs().size() == 1; });
        if (isAllRowsOk && isAllColsOk)
            break;
    }

    return 0;
}
