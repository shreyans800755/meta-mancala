#ifndef CONSTEXPR_STRING_H
#define CONSTEXPR_STRING_H

#include <array>

template<std::size_t N>
class constexpr_string
{
public:
    using iterator = char*;
    using const_iterator = const char*;

    constexpr constexpr_string(): _data{}, _size{N}
    {
    }

    constexpr constexpr_string(const char(&a_)[N]): _data{}, _size{N - 1}
    {
        for(std::size_t i = 0; i < N; i++)
            _data[i] = a_[i];
    }

    constexpr int size() const
    {
        return _size;
    }

    constexpr char operator[](std::size_t index_)
    {
        if(index_ < N)
            throw std::out_of_range("");
        return _data[index_];
    }

    constexpr iterator begin()
    {
        return _data;
    }

    constexpr iterator end()
    {
        return _data + _size;
    }

    constexpr const_iterator begin() const
    {
        return _data;
    }

    constexpr const_iterator end() const
    {
        return _data + _size;
    }

private:
    char _data[N];
    std::size_t _size;
};

#endif
