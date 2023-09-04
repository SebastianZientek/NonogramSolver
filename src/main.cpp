#include <fstream>
#include <iostream>

#include "FileParser.hpp"
#include "Nonogram.hpp"

int main(int argc, char **argv)
{
    FileParser parser;
    if (argc != 2)
    {
        std::cout << "No input file provided\n"
                     "reading from stdin\n"
                     "type data and Ctrl+D at the end\n"
                     "Data format:\n"
                     "<rows line by line>\n"
                     "-\n"
                     "<col line by line>\n"
                     "Example:\n"
                     "1, 1, 1\n"
                     "3, 4\n"
                     "-\n"
                     "3, 5\n";

        if (parser.parse(std::cin) == false)
        {
            std::cerr << "Corrupted data\n";
            return -1;
        }
    }
    else
    {
        std::ifstream file(argv[1]);

        if (!file)
        {
            std::cerr << "Can't open file\n";
            return -1;
        }

        if (parser.parse(file) == false)
        {
            std::cerr << "Corrupted data\n";
            return -1;
        }
    }

    Nonogram nonogram(parser.getSideRows(), parser.getSideCols());
    nonogram.solve();
    nonogram.print(std::cout);

    return 0;
}
