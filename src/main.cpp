#include <array>
#include <bitset>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>

#include "Combination.hpp"
#include "Generator.hpp"
#include "Line.hpp"
#include "Types.hpp"

int main(int argc, char **argv)
{
    std::vector<std::vector<SideNumberType>> sideRows{
        {3, 3}, {2, 4, 2}, {1, 2, 1}, {1, 1}, {2, 2}, {3, 3}, {3, 3}, {6}, {4}, {2},
    };

    std::vector<std::vector<SideNumberType>> sideCols{
        {5}, {2, 3}, {1, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {1, 3}, {2, 3}, {5},
    };

    Line line({4, 3}, 10);

    std::vector<CellType> painted(15);
    line.paintKnownFields(painted.begin());

    for (const auto &seq : painted)
    {
        switch (seq)
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

    return 0;
}
