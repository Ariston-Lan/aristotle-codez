#include <iostream>
#include "temp_functions.h"

float get_temp()
{
    std::cout << "Enter temperature in Farenheit: " << '\n';

    float temp{};
    std::cin >> temp;

    return temp;
}

float faren_to_cels(float farenheit)
{
    float cels{(farenheit - 32)*5/9};
    return cels;
}

bool is_freezing(float farenheit)
{
    return farenheit <= 32;
}

bool is_boiling(float farenheit)
{
    return farenheit >= 212;
}

std::string get_temp_category(float F){
    if(F <= 32){
        return "Freezing/Extreme Cold";
    }
    else if(F <= 50){
        return "Cold";
    }
    else if(F <= 65){
        return "Cool/Mild";
    }
    else if(F <= 78){
        return "Comfortable/Warm";
    }
    else if(F <= 90){
        return "Hot";
    }
    else{
        return "Very Hot/Extreme";
    }
    return "No valid input detected";
}


void temperature_analyzer()
{
    float farenheit{};
    farenheit = get_temp();

    std::cout << "Temperature: " << farenheit << "F\n";
    std::cout << "Celsius: " << faren_to_cels(farenheit) << "C\n";
    std::cout << "Freezing: " << std::boolalpha << is_freezing(farenheit) << '\n';
    std::cout << "Boiling: " << is_boiling(farenheit) << '\n';
    std::cout << "Temperature Category: " << get_temp_category(farenheit) << '\n';

}