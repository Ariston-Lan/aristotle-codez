#include <iostream>


void sample_analyzer(){
    std::cout << "How many samples? ";
    unsigned int sample_amount{};
    std::cin >> sample_amount;

    double sample_total{};
    for (int i{1}; i <= sample_amount; i++){
        std::cout << "Enter sample " << i << ": ";
        double sample{};
        std::cin >> sample;
        sample_total += sample;

    }
    std::cout << "=== RESULTS ===\n\n";
    std::cout << "Samples: " << sample_amount << '\n';
    std::cout << "Total: " << sample_total << '\n';
    std::cout << "Average: " << sample_total/sample_amount << '\n';
}

int main(){
    sample_analyzer();
}