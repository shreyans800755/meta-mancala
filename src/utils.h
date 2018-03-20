#ifndef MANCALA_UTILS_H
#define MANCALA_UTILS_H

#include "constexpr_string.h"
#include "game_state.h"

#include <iostream>


namespace utils
{

    // This struct is only for debugging
    template <class T>
    struct debugger
    {
        [[deprecated]] constexpr void write()
        {
        }
    };

    // This function provides debugging functionality
    template <class T>
    constexpr void debug()
    {
        debugger<T>().write();
    }

    template <class T>
    constexpr void swap(T& a, T& b)
    {
        auto tmp = std::move(a);
        a = std::move(b);
        b = std::move(tmp);
    }

    template <std::size_t N>
    constexpr void reverse(std::array<int, N>& c)
    {
        for(std::size_t i = 0, j = N - 1; i < j; i++, j--)
            swap(c[i], c[j]);
    }

    template <std::size_t N>
    std::ostream& operator<<(std::ostream &os, const constexpr_string<N> &s)
    {
        for(const auto& i: s)
            os << i;
        return os;
    }

    template <std::size_t N>
    std::ostream& operator<<(std::ostream &os, const state<N> &s)
    {
        os << "  ";
        const auto s1 = s.template score<1>(), s2 = s.template score<2>();
        const auto p1 = s.template pot<1>(), p2 = s.template pot<2>();
        for(auto it = p1.cend() - 1; it >= p1.cbegin(); it--)
            os << *it << ' ';
        os << std::endl << s1 << std::string(s.board_size()*2 + 1, ' ') << s2
           << std::endl << "  ";
        for(const auto i: p2)
            os << i << ' ';
        return os;
    }

}

#endif
