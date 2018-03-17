#include "constexpr_string.h"
#include "inputs.h"
#include "utils.h"

#include <iostream>

int main()
{
    constexpr auto game_state = get_game_state();
    std::cout << game_state << std::endl;

    return 0;
}
