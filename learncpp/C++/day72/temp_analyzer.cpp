#include <iostream>
#include "temp_analyzer.h"



void temp_analyzer()
{
    using Temperature = double;
    std::cout << "=== TEMPERATURE SENSOR ANALYZER ===\n\n";
    std::cout << "How many samples? ";
    unsigned int sample_amount{};
    std::cin >> sample_amount;

    double sample_total{};
    for(int i{1}; i <= sample_amount; i++)
    {
        std::cout << "Enter sample " << i << ": ";
        Temperature sample{};
        std::cin >> sample;

        sample_total += sample;
    }
    std::cout << "\nEnter calibration factor: ";
    double cal_factor{};
    std::cin >> cal_factor;

    std::cout << "=== SENSOR REPORT ===\n\n";

    std::cout << "Samples: " << sample_amount << '\n';

    std::cout << "Raw total: " << sample_total << '\n';

    Temperature raw_average{sample_total/sample_amount};

    std::cout << "Raw average: " << raw_average << '\n';

    Temperature cal_average{raw_average*cal_factor};

    std::cout << "Calibrated average " << cal_average << '\n';

    std::cout << "Whole-degree reading: " << static_cast<int>(cal_average) << '\n';
}