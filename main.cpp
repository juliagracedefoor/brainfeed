#include "string_util.hpp"
#include "tape_machine.hpp"
#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

enum class command
{
    exit,
    reset,
    none
};

// determine whether the given input is a command, and if so, what type
command command_type(const std::string & str)
{
    auto lowered = string_util::uncapitalize(str);

    if (lowered == "q" || lowered == "quit" || lowered == "exit")
    {
        return command::exit;
    }

    if (lowered == "r" || lowered == "reset")
    {
        return command::reset;
    }

    return command::none;
}

int main()
{
    bf::tape_machine tape;
    auto prompt = ">>> ";

    std::cout << "brainfeed: a brainfuck interpreter\n\n"
              << prompt;

    auto exit = false;
    std::string input;

    while (std::getline(std::cin, input))
    {
        switch (command_type(input))
        {
            case (command::exit):
                exit = true;
                break;

            case (command::reset):
                tape.reset();
                break;

            case (command::none):
                string_util::strip_all_except(input, tape.symbols);

                auto parse_char = [&](const char & c) {
                    try
                    {
                        tape.eval(c);
                    }
                    catch (const std::runtime_error & e)
                    {
                        std::cout << e.what() << "\n";
                    }
                };

                std::for_each(input.begin(), input.end(), parse_char);

                break;
        }

        if (exit)
        {
            break;
        }

        /*
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        */

        std::cout << "\n\n"
                  << prompt;
    }

    return 0;
}