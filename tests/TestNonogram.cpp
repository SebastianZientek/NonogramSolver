#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sstream>

#include "Nonogram.hpp"
#include "Types.hpp"

using ::testing::ElementsAre;

TEST(Nonogram, simpleNonogram)
{
    std::vector<std::vector<SideNumberType>> rows = {{3}, {1, 1, 1}, {3}, {1, 1}, {1, 1}};
    std::vector<std::vector<SideNumberType>> cols = {{1, 1}, {1, 2}, {3}, {1, 2}, {1, 1}};
    std::stringstream outputStream;
    std::string expectedOutput
        = "  X X X   \n"
          "X   X   X \n"
          "  X X X   \n"
          "  X   X   \n"
          "X       X \n";

    Nonogram nonogram(rows, cols);
    nonogram.solve();
    nonogram.print(outputStream);

    EXPECT_EQ(outputStream.str(), expectedOutput);
}