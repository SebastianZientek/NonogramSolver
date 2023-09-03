#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ColumnIterator.hpp"
#include "Types.hpp"

TEST(ColumnIterator, IteratingOverFirstDataColumn)
{
    std::vector<CellType> data = {0, 1, 2, 3, 4, 5};
    ColumnIterator<CellType, decltype(data.begin())> columnIterator(data.begin(), 3);

    EXPECT_EQ(*columnIterator, 0);

    columnIterator++;
    EXPECT_EQ(*columnIterator, 3);
}

TEST(ColumnIterator, IteratingOverFirstDataColumnPreincrementation)
{
    std::vector<CellType> data = {0, 1, 2, 3, 4, 5};
    ColumnIterator<CellType, decltype(data.begin())> columnIterator(data.begin(), 3);

    EXPECT_EQ(*columnIterator, 0);

    ++columnIterator;
    EXPECT_EQ(*columnIterator, 3);
}

TEST(ColumnIterator, IteratingOverMiddleDataColumn)
{
    std::vector<CellType> data = {0, 1, 2, 3, 4, 5};
    ColumnIterator<CellType, decltype(data.begin())> columnIterator(data.begin() + 1, 3);

    EXPECT_EQ(*columnIterator, 1);

    columnIterator++;
    EXPECT_EQ(*columnIterator, 4);
}

TEST(ColumnIterator, IteratingOverLastDataColumn)
{
    std::vector<CellType> data = {0, 1, 2, 3, 4, 5};
    ColumnIterator<CellType, decltype(data.begin())> columnIterator(data.begin() + 2, 3);

    EXPECT_EQ(*columnIterator, 2);

    columnIterator++;
    EXPECT_EQ(*columnIterator, 5);
}

TEST(ColumnIterator, IteratingWhenDataIsNotDividableByColumnLength)
{
    std::vector<CellType> data = {0, 1, 2, 3, 4, 5, 6};
    ColumnIterator<CellType, decltype(data.begin())> columnIterator(data.begin() + 1, 3);

    EXPECT_EQ(*columnIterator, 1);

    columnIterator++;
    EXPECT_EQ(*columnIterator, 4);
}
