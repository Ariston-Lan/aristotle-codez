#include <iostream>
#include "num_analyzer.h"

bool is_even(int input)
{
    return input%2 == 0;
}

int get_larger(int input1, int input2)
{
    if(input1 > input2){
        return input1;
    }
    else if(input1 < input2){
        return input2;
    }
}

void num_analyzer()
{
    std::cout << "Enter first integer: \n";
    int input1 {};
    std::cin >> input1;

    std::cout << "Enter second integer: \n";
    int input2 {};
    std::cin >> input2;

    std::cout << "Sum: " << input1 + input2 << '\n';
    std::cout << "Difference: " << input1 - input2 << '\n';
    std::cout << "Product: " << input1*input2 << '\n';
    std::cout << "Quotient " << input1/input2 << '\n';
    std::cout << "Remainder: " << input1%input2 << '\n';
    if (is_even(input1)){
        std::cout << input1 << " is even\n";
    }
    else{
        std::cout << input1 << " is odd\n";
    }


    if (is_even(input2)){
        std::cout << input2 << " is even\n";
    }
    else{
        std::cout << input2 << " is odd\n";
    }

    std::cout << get_larger(input1, input2) << " is larger.\n";


    std::cout << std::boolalpha << "Both numbers are positive: " << (input1>0 && input2>0) << '\n';
    std::cout << "At least one number is negative: " << (input1<0 || input2<0) << '\n';

    std::cout << "Larger number using the conditional operator: " << ((input1>input2) ? input1 : input2);
}