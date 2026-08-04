#include <iostream>
int main(){
    int age;
    std::cout<<"Enter age: \n";
    std::cin>>age;
    if (age >= 18){
        std::cout << "You are an adult.\n";
    }
    else {
        std::cout << "You are a minor.\n";
    }

    for (int i = 0; i <= 10; i++)
    {
        std::cout << i << "\n";
    }
}