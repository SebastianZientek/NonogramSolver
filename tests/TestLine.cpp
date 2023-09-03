#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Line.hpp"
#include "Types.hpp"

using ::testing::ElementsAre;

TEST(Line, PaintingKnownFieldsTwoOverlapingBlocksWithoutWhiteBlocks)
{
    Line line({4, 3}, 10);
    std::vector<CellType> painted(10);
    line.paintKnownFields(painted.begin());

    ASSERT_THAT(painted, ElementsAre(E, E, B, B, E, E, E, B, E, E));
}

TEST(Line, PaintingKnownFieldsWithWhiteBlocks)
{
    Line line({2, 4, 2}, 10);
    std::vector<CellType> painted(10);
    line.paintKnownFields(painted.begin());

    ASSERT_THAT(painted, ElementsAre(B, B, W, B, B, B, B, W, B, B));
}