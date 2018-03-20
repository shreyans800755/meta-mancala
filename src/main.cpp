#include "constexpr_string.h"
#include "inputs.h"
#include "parser.h"
#include "utils.h"

#include <iostream>

using utils::operator<<;

int main()
{
    constexpr auto game_state = parse_game_state(get_game_state);
    std::cout << game_state << std::endl;
    return 0;
}
