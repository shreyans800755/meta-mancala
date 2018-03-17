#ifndef MANCALA_UTILS_H
#define MANCALA_UTILS_H

#include "constexpr_string.h"
#include "game_state.h"

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

#endif
