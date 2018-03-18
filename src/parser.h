#ifndef PARSER_H
#define PARSER_H

#include "utils.h"

#include <iostream>

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

template <class Get_game_state>
constexpr auto parse_board(Get_game_state&& get_game_state)
{
    constexpr int size = parse_game_size(get_game_state);
    return state<size>{};
}

template <class Get_game_state>
constexpr auto parse_game_state(Get_game_state&& get_game_state)
{
    constexpr auto board = parse_board(get_game_state);
    return board;
}

#endif
