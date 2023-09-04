#include "Combination.hpp"

#include <algorithm>
#include <utility>

void Combination::setup(size_t numbers, size_t length)
{
    m_permutation.resize(numbers, 0);
    m_combination.resize(length);

    std::fill(m_permutation.begin(), m_permutation.begin() + length, 1);
}

bool Combination::next()
{
    size_t combId = 0;
    for (size_t permId = 0; permId < m_permutation.size(); ++permId)
    {
        if (m_permutation[permId] == 1)
        {
            m_combination[combId++] = permId;
        }
    }

    bool nextExists = std::prev_permutation(m_permutation.begin(), m_permutation.end());
    return std::exchange(m_isNextExists, nextExists);
}

std::vector<size_t> &Combination::seq()
{
    return m_combination;
}