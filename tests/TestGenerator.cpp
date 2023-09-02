#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Generator.hpp"
#include "Types.hpp"

using ::testing::ElementsAre;

TEST(Generator, NO_TEST_HERE)
{
    
}

// TEST(Generator, OneField)
// {
//     std::vector<CellType> data(5);
//     Generator nr({3}, data);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, W, B, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, B, B, B, W));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, B, B, W, W));
//     EXPECT_EQ(nr.next(), false);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, B, B, W, W));
//     EXPECT_EQ(nr.next(), false);
// }

// TEST(Generator, TwoFields)
// {
//     std::vector<CellType> data(6);
//     Generator nr({1, 2}, data);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, W, B, W, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, B, W, W, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, W, W, W, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, B, W, B, B, W));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, W, W, B, B, W));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, W, B, B, W, W));
//     EXPECT_EQ(nr.next(), false);
// }

// TEST(Generator, LongerFields)
// {
//     std::vector<CellType> data(7);
//     Generator nr({2, 2}, data);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, W, B, B, W, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, B, B, W, W, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, B, W, W, W, B, B));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, B, B, W, B, B, W));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, B, W, W, B, B, W));
//     EXPECT_EQ(nr.next(), true);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(B, B, W, B, B, W, W));
//     EXPECT_EQ(nr.next(), false);
// }

// TEST(Generator, NoFields)
// {
//     std::vector<CellType> data(6);
//     Generator nr({}, data);

//     ASSERT_THAT(nr.getSeq(), ElementsAre(W, W, W, W, W, W));
//     EXPECT_EQ(nr.next(), false);
// }