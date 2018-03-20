#ifndef PARSER_H
#define PARSER_H

#include "game_state.h"
#include "utils.h"

#include <iostream>
#include <tuple>

template <class Get_game_state>
constexpr int parse_game_size(Get_game_state&& get_game_state)
{
    constexpr auto state_str = get_game_state().replace_all('\n', ' ').trim();
    if constexpr (state_str.size() == 0)
        return 0;
    std::size_t next = state_str.find(' ');
    std::size_t sz = 1;
    while(next != state_str.size())
    {
        while(next < state_str.length() && state_str[next] == ' ')
            next++;
        sz++, next = state_str.find(' ', next);
    }
    return sz / 2 - 1;
}

template <class Get_game_state, int N>
constexpr auto parse_state(Get_game_state&& get_game_state)
{
    constexpr auto state_str = get_game_state().replace_all('\n', ' ');

    std::array<int, N> p1{}, p2{};
    int score1 = 0, score2 = 0;

    auto first = state_str.find_not(' ');
    for(auto i = 0; i < N; i++)
    {
        while(state_str[first] != ' ')
            p1[i] = (p1[i] * 10) + (state_str[first] - '0'), first++;
        first = state_str.find_not(' ', first);
    }
    utils::reverse(p1);

    while(state_str[first] != ' ')
        score1 = (score1 * 10) + (state_str[first] - '0'), first++;

    first = state_str.find_not(' ', first);
    while(state_str[first] != ' ')
        score2 = (score2 * 10) + (state_str[first] - '0'), first++;

    first = state_str.find_not(' ', first);
    for(auto i = 0; i < N; i++)
    {
        while(state_str[first] != ' ')
            p2[i] = (p2[i] * 10) + (state_str[first] - '0'), first++;
        first = state_str.find_not(' ', first);
    }

    return std::make_tuple(p1, p2, score1, score2);
}

template <class Get_game_state>
constexpr auto parse_board(Get_game_state&& get_game_state)
{
    constexpr auto size = parse_game_size(get_game_state);
    constexpr auto game = parse_state<Get_game_state, size>(get_game_state);
    return state<size>(std::get<0>(game), std::get<1>(game),
                       std::get<2>(game), std::get<3>(game));
}

template <class Get_game_state>
constexpr auto parse_game_state(Get_game_state&& get_game_state)
{
    constexpr auto board = parse_board(get_game_state);
    return board;
}

#endif
