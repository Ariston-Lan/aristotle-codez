#include <iostream>
#include <limits>
#include <cstdlib>
#include "num_stats.h"


void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool handle_cin_error()
{
    if(!std::cin){
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }
    }

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
        std::cout << "Accepted!\n";
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

int check_smallest(int current_smallest, int input)
{
    if(input<current_smallest){
        current_smallest = input;
        return current_smallest;
    }
    return current_smallest;
}

int check_largest(int current_largest, int input)
{
    if(input>current_largest){
        current_largest = input;
        return current_largest;
    }
    return current_largest;
}

void num_stats(){
    bool is_running{true};
    std::cout << "=== Number Statistics ===\n\n";
    //All variables used within the "print results" portion
    //Probably better to put these all in a function, but right now just wanted to get the project done
    //Also input1 is called input1 to differentiate from input2 which is in the while loop. This isn't needed, I just like it visually.
    int count{};
    int sum{};

    int input1{get_integer()};
    count++;
    sum += input1;
    int largest{input1};
    int smallest{input1};

    while(is_running)
    {
        std::cout << "Enter another integer? (y/n)\n";
        char choice{get_choice()};
        if(choice == 'y' || choice=='Y'){
            int input2{get_integer()};
            count++;
            sum += input2;
            largest = check_largest(largest, input2);
            smallest = check_smallest(smallest, input2);
        }
        else if(choice =='n' || choice=='N'){
            is_running = false;
            std::cout << "Getting your results shortly!\n\n";
        }
        else{
            std::cout << "Invalid input. Try again.\n";
        }
    }

    std::cout << "\n\n=== Results ===\n\n";
    std::cout << "Numbers entered: " << count << '\n';
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Smallest: " << smallest << '\n';
    std::cout << "Largest: " << largest << '\n';
    std::cout << "Average: " << sum/count << '\n';

}