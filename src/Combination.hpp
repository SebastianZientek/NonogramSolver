#pragma once

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

class Combination
{
public:
    void setup(size_t numbers, size_t length);
    bool next();
    std::vector<size_t> &seq();

private:
    std::vector<uint8_t> m_permutation;
    std::vector<size_t> m_combination;
    bool m_isNextExists = true;
};