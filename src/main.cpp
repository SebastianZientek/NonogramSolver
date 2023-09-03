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
#include "Nonogram.hpp"
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
        {5},          {3, 3},          {2, 5},    {1, 4, 2}, {5, 2},    {9, 1},    {3, 4},
        {1, 2, 4, 1}, {4, 5, 2},       {3, 4, 2}, {2, 2, 1}, {5, 3, 1}, {3, 4, 3}, {6, 2},
        {4, 4, 1},    {1, 1, 2, 1, 1}, {3, 1, 1}, {2, 8},    {2},       {10}};

    std::vector<std::vector<SideNumberType>> sideCols{{2, 3},
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
                                                      {10, 1}};

    Nonogram nonogram(sideRows, sideCols);
    nonogram.solve();
    nonogram.print();

    return 0;
}
