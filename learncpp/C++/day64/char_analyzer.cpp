#include <iostream>
#include "char_analyzer.h"

bool is_uppercase(char input)
{
    if(input >= 'A' && input <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void char_conversion(char input)
{
    if(is_uppercase(input))
    {
        std::cout << "Converted lowercase: " << static_cast<char>(input + 32) << '\n';
    }
    else
    {
        std::cout << "Converted upprcase " << static_cast<char>(input - 32) << '\n';
    }
}

void char_analyzer()
{
    std::cout << "Enter a character: \n";
    
    char input{};
    std::cin >> input;

    std::cout << "Character: " << input << '\n';
    std::cout << "Numeric code: " << static_cast<int>(input) << '\n';
    std::cout << "Is uppercase: " << std::boolalpha << is_uppercase(input) << '\n';
    char_conversion(input);

}