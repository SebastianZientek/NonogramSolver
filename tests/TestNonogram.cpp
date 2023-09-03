#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Nonogram.hpp"
#include "Types.hpp"

using ::testing::ElementsAre;

TEST(Nonogram, simpleNonogram)
{
    std::vector<std::vector<SideNumberType>> rows = {{3}, {1, 1, 1}, {3}, {1, 1}, {1, 1}};
    std::vector<std::vector<SideNumberType>> cols = {{1, 1}, {1, 2}, {3}, {1, 2}, {1, 1}};

    Nonogram nonogram(rows, cols);
    nonogram.solve();

    auto seq = nonogram.getSeq();
    ASSERT_THAT(seq, ElementsAre(W, B, B, B, W, B, W, B, W, B, W, B, B, B, W, W, B, W, B, W, B, W,
                                 W, W, B));
}