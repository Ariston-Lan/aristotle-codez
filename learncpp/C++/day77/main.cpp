#include "difficulty.h"



int main(){
    std::cout << Difficulty::easy << '\n';

    while(true){
        Difficulty::Difficulty difficulty{};
        if(std::cin >> difficulty){
            std::cout << difficulty << "\n\n";
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input\n";
        }
    }
}