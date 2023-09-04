#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sstream>

#include "FileParser.hpp"

using ::testing::ElementsAre;

TEST(FileParser, ParsingFileWithCorrectData)
{
    std::stringstream inStream;
    inStream << "6\n"
                "2 3 1\n"
                "-\n"
                "3\n"
                "1 8\n";

    FileParser parser;
    EXPECT_TRUE(parser.parse(inStream));

    ASSERT_THAT(parser.getSideRows()[0],  ElementsAre(6));
    ASSERT_THAT(parser.getSideRows()[1],  ElementsAre(2, 3, 1));

    ASSERT_THAT(parser.getSideCols()[0],  ElementsAre(3));
    ASSERT_THAT(parser.getSideCols()[1],  ElementsAre(1, 8));
}

TEST(FileParser, ParsingCorruptedFileNotAllowedChar)
{
    std::stringstream inStream;
    inStream << "6\n"
                "x 3 1\n"
                "-\n"
                "3\n"
                "1 8\n";

    FileParser parser;

    EXPECT_FALSE(parser.parse(inStream));
}

TEST(FileParser, ParsingCorruptedFileExtraDash)
{
    std::stringstream inStream;
    inStream << "6\n"
                "3 1\n"
                "-\n"
                "3\n"
                "1 8\n"
                "-";

    FileParser parser;

    EXPECT_FALSE(parser.parse(inStream));
}

TEST(FileParser, ParsingCorruptedFileMissingDash)
{
    std::stringstream inStream;
    inStream << "6\n"
                "3 1\n"
                "3\n"
                "1 8\n";

    FileParser parser;

    EXPECT_FALSE(parser.parse(inStream));
}