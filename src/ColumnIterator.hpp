#pragma once

#include <iterator>

template <typename T, typename IT>
struct ColumnIterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    ColumnIterator(IT itStart, size_t width)
        : m_it(itStart)
        , m_width(width)
    {
    }

    reference operator*() const
    {
        return *m_it;
    }
    pointer operator->()
    {
        return m_it;
    }

    ColumnIterator &operator++()
    {
        m_it += m_width;
        return *this;
    }

    ColumnIterator operator++(int)
    {
        ColumnIterator tmp = *this;
        m_it += m_width;
        return tmp;
    }

    friend bool operator==(const ColumnIterator &a, const ColumnIterator &b)
    {
        return a.m_it == b.m_it;
    };
    friend bool operator!=(const ColumnIterator &a, const ColumnIterator &b)
    {
        return a.m_it != b.m_it;
    };

private:
    IT m_it;
    size_t m_width;
    difference_type m_offset;
    difference_type m_column;
    difference_type m_columnOffset;
};