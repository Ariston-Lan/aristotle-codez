#include <iostream>
#include "number_inspec.h"

bool is_pos(int input)
{
    return input >= 0;
}
bool is_even(int input)
{
    return input % 2 == 0;
}
void number_inspector()
{
    std::cout << "=== NUMBER INSPECTOR ===\n";
    std::cout << "Enter an integer: \n";
    
    int input{};
    std::cin >> input;

    std::cout << "Number: " << input << '\n';
    std::cout << "Hexadecimal: " << std::hex << input << '\n';
    std::cout << "Octal: " << std::oct << input << '\n' << std::dec;

    std::cout << std::boolalpha << "Is positive: " << is_pos(input) << '\n';
    std::cout << "Is even: " << is_even(input) << '\n';

}