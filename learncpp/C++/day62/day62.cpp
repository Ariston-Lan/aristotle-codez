#include <iostream>
#include "temperature_calculations.h"

int main(){
    double cels = get_user_input();
    std::cout << "The temperature in Kelvins is " << kelvin(cels) << '\n';
    std::cout << "The temperature in Farenheit is " << farenheight(cels) << '\n';

}