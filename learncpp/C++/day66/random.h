#pragma once

#include <random>
namespace random
{
    inline std::random_device rd{};

    inline std::seed_seq ss{
        rd(), rd(), rd(), rd(),
        rd(), rd(), rd(), rd(),
        rd(), rd(), rd(), rd()
    };

    inline std::mt19937 mt{ss};

    inline std::uniform_int_distribution num_range(1, 100);

    inline int generate(){
        return num_range(mt);
    }
    
}