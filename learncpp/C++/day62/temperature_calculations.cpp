#include "temperature_calculations.h"
#include <iostream>

double farenheight(double cels){
    double f {cels * 1.8 + 32};
    return f;
}

double kelvin(double cels){
    double k {cels + 273.15};
    return k;
}

double get_user_input(){
    std::cout << "=== Temperature Converter ===\n\n";
    double cels {};
    std::cout << "Enter the temperature in celsius: \n";
    std::cin >> cels;
    return cels;
}
