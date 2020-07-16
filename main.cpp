#include <algorithm>
#include <iostream>
#include <string>

// compute a string's lowercase form
std::string uncapitalize(const std::string& str)
{
    std::string lowered;

    std::transform(
        str.begin(), str.end(), back_inserter(lowered),
        [](unsigned char c){ return tolower(c); }
    );

    return lowered;
}

// determine whether the given string is a command to exit the REPL
bool is_exit_command(const std::string& str)
{
    auto lowered = uncapitalize(str);

    if (lowered == "q" || lowered == "quit" || lowered == "exit")
    {
        return true;
    }

    return false;
}

// strip all characters from str that are not found in exceptions
void strip_all_except(std::string& str, const std::string& exceptions)
{
    str.erase(
        std::remove_if(
            str.begin(), str.end(),
            [exceptions](char c){ return exceptions.find(c) == std::string::npos; }
        ),
        str.end()
    );
}

void eval(const std::string& commands)
{
    std::cout << commands << std::endl;
}

int main()
{
    std::cout << "brainfeed: a brainfuck interpreter\n";
    auto prompt = "\n>>> ";

    std::cout << prompt;

    std::string input;
    while (std::getline(std::cin, input))
    {
        if (is_exit_command(input))
        {
            break;
        }

        strip_all_except(input, "><+-.,[]");
        eval(input);

        std::cout << prompt;
    }

    return 0;
}