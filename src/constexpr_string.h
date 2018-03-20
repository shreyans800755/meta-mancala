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

    constexpr constexpr_string(const char* a, std::size_t size):
        _data{}, _size{size}
    {
        const std::size_t new_size = std::min(size, N);
        for(std::size_t i = 0; i < new_size; i++)
            _data[i] = a[i];
    }

    constexpr std::size_t length() const
    {
        return _size;
    }

    constexpr std::size_t size() const
    {
        return N;
    }

    constexpr char operator[](std::size_t index_) const
    {
        if(index_ >= _size)
            throw std::out_of_range("");
        return _data[index_];
    }

    constexpr const constexpr_string<N> replace_all(const char old_,
                                              const char new_)
    {
        for(auto& i: _data)
            if(i == old_)
                i = new_;
        return *this;
    }

    constexpr const constexpr_string<N> trim() const
    {
        const int first = find_not(' ');
        const int last = rfind_not(' ');
        const std::size_t size = last - first + 1;
        return constexpr_string{_data + first, size};
    }

    constexpr std::size_t find(const char c, const std::size_t start = 0) const
    {
        for(std::size_t i = start; i < N && i < _size; i++)
            if(_data[i] == c)
                return i;
        return N;
    }

    constexpr std::size_t rfind(const char c) const
    {
        for(std::size_t i = _size - 1; i >= 0; i--)
            if(_data[i] == c)
                return i;
        return N;
    }

    constexpr std::size_t find_not(const char c,
                                   const std::size_t start = 0) const
    {
        for(std::size_t i = start; i < N && i < _size; i++)
            if(_data[i] != c)
                return i;
        return N;
    }

    constexpr std::size_t rfind_not(const char c) const
    {
        for(std::size_t i = _size - 1; i >= 0; i--)
            if(_data[i] != c)
                return i;
        return N;
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
    const std::size_t _size;
};

#endif
