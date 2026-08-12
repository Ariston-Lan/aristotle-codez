#include "stats.h"
#include <iostream>
namespace stats

{
    int streak {};
    int best_streak {};
    int wins {};
    int losses {};
    int games_played{};


    void record_game()
    {
        games_played++;
    }
    void record_win()
    {
        record_game();
        wins++;
        streak++;
        (streak>best_streak) ? best_streak = streak : 0;
    }
    void record_loss()
    {
        record_game();
        losses++;
        (streak>best_streak) ? best_streak = streak : 0;
        streak=0;
    }

    void show_stats(){
        std::cout << "Games played: " << games_played << '\n';
        std::cout << "Wins: " << wins << '\n';
        std::cout << "Losses: " << losses << '\n';
        std::cout << "Streak: " << streak << '\n';
        std::cout << "Best Streak: " << best_streak << '\n';

    }
    
    void run()
    {
        bool running {true};
        while (running){
            std::cout << "=== GAME TRACKER ===\n\n";
            std::cout << R"(
                1. Record win
                2. Record loss
                3. View stats
                4. Quit)" << '\n';
            
            int choice{};
            std::cin >> choice;

            if(choice == 1){
                record_win();
                std::cout << "Win logged!\n";
            }
            else if(choice == 2){
                record_loss();
                std::cout << "Loss logged!\n";
            }
            else if(choice == 3){
                show_stats();
            }
            else if(choice == 4){
                running = {false};
                std::cout << "Program terminated";
            }
        }
    }
}