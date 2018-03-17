#ifndef INPUTS_H
#define INPUTS_H

constexpr auto get_game_state = []() constexpr
    {
        auto game_state = constexpr_string(
            #include "../current_state.txt"
        );
        return game_state;
    };

#endif
