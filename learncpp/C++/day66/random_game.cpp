#include "random.h"
#include "random_game.h"
#include <iostream>

int get_guess()
{
    while(true)
    {
        int guess{};
        std::cin>>guess;

        if(guess>= 1 && guess<=100){
            return guess;
        }
        else{
            std::cout << "Invalid guess. Try again.\n";
        }
    }
}

int get_choice()
{
    while(true){
        int choice{};
        std::cin>>choice;
        if(choice>=1 && choice<=2){
            return choice;
        }
        else{
            std::cout << "Invalid choice\n";
        }
    }
}

void guess_game(){
    bool is_playing{true};
    while (is_playing)
    {
        int random_numb {random::generate()};
        bool has_won{false};
        std::cout << "Let's play a game hoe. I have a number I am thinking of between 1-100, and you have to guess it!\n";
        std::cout << "You have 8 attempts, I'll tell you if you're too high or too low!\n\n";
        for(int count{7}; count >= 0; count--)
        {

            int guess {get_guess()};

            if (guess > random_numb){
                std::cout << "\nToo high! " << count << " attempts left\n";
            }
            else if (guess < random_numb){
                std::cout << "\nToo low! " << count << " attempts left\n";
            }
            else {
                std::cout << "\nCorrect!\n";
                has_won = true;
                break;
            }
        }
        if (has_won){
            std::cout << "Congrats! I was thinking of the number " << random_numb << '\n';
        }
        else{
            std::cout << "Aww too bad, I was thinking of the number " << random_numb << '\n';
        }

        std::cout << "\n====\nWanna play again?\n1. Yes\n2. No\n";
        int choice{get_choice()};
        
        if(choice==1)
        {
            std::cout << "Starting the game again!\n";
        }
        
        else
        {
            std::cout << "Game terminated.";
            is_playing = false;
        }
    }
}