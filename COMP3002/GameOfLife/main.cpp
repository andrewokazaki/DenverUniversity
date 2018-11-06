#include <iostream>
#include <string>
#include <thread>

#include "GameOfLife.h"

bool animate_or_prompt(bool animate);

bool yn_prompt(const std::string &prompt);

int main() {
    // Setup the game
    GameOfLife gol(33, 44);

    // Setup fancy board stuff
    // Uncomment these one at a time as you are working. Only introduce a new
    // one once the previous one is working
    gol.add_blinker(8, 40); // Period 2
    gol.add_toad(12, 38); // Period 2
    gol.add_pentadecathlon(13, 0); // Period 15
    gol.add_pulsar(16, 13); // Period 3
    gol.add_gosper_glider_gun(); // Period 30


    // Ask the user if they would like to see step-by-step or an animation
    bool animate = yn_prompt("Would you like to see an animation (Y) Or step-by-step (N)? ");
    // Loop through until the user says otherwise
    for (int generation_count = 1; animate_or_prompt(animate);
         ++generation_count) {
        std::cout << "Generation " << generation_count << " (Press CTRL+C to quit)\n";

        // Print the board
        std::cout << gol;

        // Simulate a step
        gol.simulate_step();
    }

    std::cout << "Simulation complete\n";

    return 0;
}

bool animate_or_prompt(bool animate) {
    if (!animate) {
        return yn_prompt("Would you like to continue? (Y/N) ");
    }

    // Clear screen using ANSI escape code
    // escape, clear screen, escape move cursor to 1,1
    std::cout << "\033[2J\033[1;1H";

    // Sleep for 0.1 seconds
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);

    return true;
}


bool yn_prompt(const std::string &prompt) {
    // This function should prompt the user with the prompt string
    // parameter
    // It should return true if the answer is "Y" or "y"
    // It should return false if the answer is "N" or "n"
    // If invalid input is entered, a message indicating invalid input
    // should be printed and the prompt should be repeated until
    // valid input is given.
    std::cout << prompt;
    std::string userInput;
    std::cin >> userInput;
    if(userInput == "Y" || userInput == "y"){
        return true;
    }else if(userInput == "N" || userInput == "n"){
        return false;
    }else{
        return yn_prompt(prompt);
    }
}