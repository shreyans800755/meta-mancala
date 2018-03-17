#ifndef MANCALA_UTILS_H
#define MANCALA_UTILS_H

#include "constexpr_string.h"

template <std::size_t N>
std::ostream& operator<<(std::ostream &os, const constexpr_string<N> &s)
{
    for(const auto& i: s)
        os << i;
    return os;
}

#endif
