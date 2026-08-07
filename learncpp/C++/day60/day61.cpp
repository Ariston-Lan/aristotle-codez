#include <iostream>

int main()
{
    
    std::cout << "Enter a number: \n";
    int num1;
    std::cin >> num1;

    std::cout << "Enter another number: \n";
    int num2;
    std::cin >> num2;

    std::cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
    std::cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";
    
}