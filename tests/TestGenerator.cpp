#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Generator.hpp"
#include "Types.hpp"

using ::testing::ElementsAre;

TEST(Generator, OneField)
{
    Generator gen({3}, 5);

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, B, B, W, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, B, B, B, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, W, B, B, B));

    EXPECT_EQ(gen.next(), false);
}

TEST(Generator, TwoFields)
{
    Generator gen({1, 2}, 6);

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, W, B, B, W, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, W, W, B, B, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, W, W, W, B, B));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, B, W, B, B, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, B, W, W, B, B));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, W, B, W, B, B));

    EXPECT_EQ(gen.next(), false);
}

TEST(Generator, LongerFields)
{
    Generator gen({2, 2}, 7);

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, B, W, B, B, W, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, B, W, W, B, B, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(B, B, W, W, W, B, B));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, B, B, W, B, B, W));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, B, B, W, W, B, B));

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, W, B, B, W, B, B));

    EXPECT_EQ(gen.next(), false);
}

TEST(Generator, NoFields)
{
    Generator gen({}, 6);

    EXPECT_EQ(gen.next(), true);
    ASSERT_THAT(gen.getSeq(), ElementsAre(W, W, W, W, W, W));

    EXPECT_EQ(gen.next(), false);
}