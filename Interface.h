#pragma once

#include <string>

namespace Interface {

    // commands to manage with console interface
    enum class Command {YES, NO, REG, LOGIN, CHANGE, ROOM, USER, NAME, PASSWORD, ALL,
                        QUIT, INFO, NO_COMMAND};

    Command get_command(std::string &str);

    // function using to check password requirements
    bool char_is_A_simbol(char ch);
    bool char_is_a_simbol(char ch);
    bool char_is_num_simbol(char ch);
    bool char_is_spec_simbol(char ch);

}
