#include "constexpr_string.h"
#include "inputs.h"
#include "parser.h"
#include "utils.h"

#include <iostream>

using utils::operator<<;

int main()
{
    constexpr auto cur_state = parse_game_state(get_game_state);
    if constexpr(index == -1)
    {
        std::cout << cur_state << std::endl;
        return 0;
    }
    constexpr auto new_state = cur_state.update(index, player);
    std::cout << new_state << std::endl;
    return 0;
}
