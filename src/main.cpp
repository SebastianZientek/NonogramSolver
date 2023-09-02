#include <array>
#include <bitset>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>

#include "Combination.hpp"
#include "Generator.hpp"
#include "Types.hpp"

int main(int argc, char **argv)
{
    std::vector<std::vector<SideNumberType>> sideRows{
        {3, 3}, {2, 4, 2}, {1, 2, 1}, {1, 1}, {2, 2}, {3, 3}, {3, 3}, {6}, {4}, {2},
    };

    std::vector<std::vector<SideNumberType>> sideCols{
        {5}, {2, 3}, {1, 3}, {2, 3}, {2, 3}, {2, 3}, {2, 3}, {1, 3}, {2, 3}, {5},
    };

    Generator gen({3, 2, 6}, 15);

    while (gen.next())
    {
        for (auto a : gen.getSeq())
        {
            std::cout << a << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
