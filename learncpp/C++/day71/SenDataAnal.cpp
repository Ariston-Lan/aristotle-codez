#include <iostream>



void temp_analyzer(){
    std::cout << "=== Temperature Sensor Analyzer ===\n";
    std::cout << "How many samples would you like to enter?: ";
    unsigned int sample_amount{};
    std::cin >> sample_amount;
}