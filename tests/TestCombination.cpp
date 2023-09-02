#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Combination.hpp"

using ::testing::ElementsAre;

TEST(Combination, BasicTest)
{
    Combination combination;
    combination.setup(4, 3);

    EXPECT_EQ(combination.next(), true);
    ASSERT_THAT(combination.seq(), ElementsAre(0, 1, 2));

    EXPECT_EQ(combination.next(), true);
    ASSERT_THAT(combination.seq(), ElementsAre(0, 1, 3));

    EXPECT_EQ(combination.next(), true);
    ASSERT_THAT(combination.seq(), ElementsAre(0, 2, 3));

    EXPECT_EQ(combination.next(), true);
    ASSERT_THAT(combination.seq(), ElementsAre(1, 2, 3));

    EXPECT_EQ(combination.next(), false);
}