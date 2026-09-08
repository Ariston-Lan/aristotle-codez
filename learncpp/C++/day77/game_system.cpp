#include <iostream>
#include <string>
#include "game_system.h"

Gamestate::Gamestate convert_choice(int choice){
    switch(choice){
        case 1:
            return Gamestate::one;
        case 2:
            return Gamestate::two;
        case 3:
            return Gamestate::three;
        default:
            return Gamestate::fail;
        

    }
}

void game(){
    std::cout << "=== GAME STATE ===\n\n";
    bool running{true};
    while(running){
        std::cout << "1. Playing\n2. Paused\n3. Game Over\n";
        std::cout << "Enter state: ";
        
        int choice{};
        std::cin >> choice;

        Gamestate::Gamestate gamestate_choice{(convert_choice(choice))};

        switch(gamestate_choice){
            case Gamestate::one:
                std::cout << "\nYou are playing\n";
                break;
            case Gamestate::two:
                std::cout << "\nYou are Paused\n";
                break;
            case Gamestate::three:
                std::cout << "\nGame Over!\n";
                running=false;
                break;
            case Gamestate::fail:
                std::cout << "Error occurred, please choose again!\n";
                break;
            

        }

    }
}
