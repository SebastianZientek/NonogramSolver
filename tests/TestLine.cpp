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

TEST(Line, RemovingImpossibleSequences)
{
    Line line({3, 3}, 9);

    std::vector<CellType> pattern = {E, E, B, B, W, E, E, E, E};
    line.removeImpossibleSequences(pattern.begin());

    ASSERT_THAT(line.getSeqs()[0], ElementsAre(W, B, B, B, W, B, B, B, W));
    ASSERT_THAT(line.getSeqs()[1], ElementsAre(W, B, B, B, W, W, B, B, B));
}