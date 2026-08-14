#include <iostream>
#include <limits>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool handle_cin_error()
{
    if(!std::cin){
        std::cin.clear();
        ignore_line();
        return true;
    }
    return false;
}

int get_integer()
{
    while(true)
    {
        std::cout << "Enter an integer: " << '\n';
        int input{};
        std::cin>>input;

        if(handle_cin_error()){
            std::cout << "Invalid integer. Try again.\n";
            continue;
        }

        ignore_line();
        return input;
    }
}

char get_choice()
{
    while(true)
    {
        char choice{};
        std::cin>>choice;
        if(!handle_cin_error()){
            ignore_line();
            return choice;
        }
    }
}

int main(){
    char choice {get_choice()};
    std::cout << choice << '\n';
    std::cin >> choice;
    std::cout << choice;
    
}