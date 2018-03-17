#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "game_state.h"

constexpr int parse_game_size(const auto& state)
{
    return ((state.size() - 1) / 2 - 1) / 2;
}

template <class Get_game_state>
constexpr auto parse_board(Get_game_state&& get_game_state)
{
    constexpr auto state_str = get_game_state();
    const int size = parse_game_size(state_str);
    return state<size>{};
}

template <class Get_game_state>
constexpr auto parse_game_state(Get_game_state&& get_game_state)
{
    constexpr auto board = parse_board(get_game_state);
    return board;
}

#endif
