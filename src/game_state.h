#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <array>

template<std::size_t N>
class state
{
public:
    constexpr state(): _pot1{std::array<int, N>{}}, _pot2{std::array<int, N>{}},
                       _score1{0}, _score2{0}
    {
    }

    constexpr state(const std::array<int, N> p1_, const std::array<int, N> p2_,
                    const int s1_, const int s2_):
                        _pot1(p1_), _pot2(p2_), _score1(s1_), _score2(s2_)
    {
    }

    constexpr int board_size() const
    {
        return N;
    }

    template<int P>
    constexpr auto score() const
    {
        static_assert(P == 1 || P == 2);
        if constexpr(P == 1)
            return _score1;
        else
            return _score2;
    }

    template<int P>
    constexpr auto pot() const
    {
        static_assert(P == 1 || P == 2);
        return P == 1 ? _pot1 : _pot2;
    }

private:
    const std::array<int, N> _pot1, _pot2;
    const int _score1, _score2;
};

#endif
