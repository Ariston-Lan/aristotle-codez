#include <iostream>
#include "gen_stat_kit.h"

void stat_tool(){
    std::cout << "=== Generic Statistics Toolkit ===\n\n";

    std::cout << "Enter three integer values:\n";
    int num1{}, num2{}, num3{};
    std::cin >> num1;
    std::cin >> num2;
    std::cin >> num3;

    std::cout << "Integer results:\n";
    std::cout << "Maximum: " << getMax(num1, num2, num3) << '\n';
    std::cout << "Minimum: " << getMin(num1, num2, num3) << '\n';
    std::cout << "Average: " << getAverage(num1, num2, num3) <<  '\n';

    std::cout << "Enter three decimal values:\n";
    double dec1{}, dec2{}, dec3{};
    std::cin >> dec1;
    std::cin >> dec2;
    std::cin >> dec3;

    std::cout << "Double results:\n";
    std::cout << "Maximum: " << getMax(dec1, dec2, dec3) << '\n';
    std::cout << "Minimum: " << getMin(dec1,dec2,dec3) << '\n';
    std::cout << "Average: " << getAverage(dec1,dec2,dec3) << '\n';

    std::cout << "Scaling Demonstration:\n";
    std::cout << "First int scaled by 2: " << scaleValue<2>(num1) << '\n';
    std::cout << "First decimal scaled by 5: " << scaleValue<5>(dec1) << '\n';


}