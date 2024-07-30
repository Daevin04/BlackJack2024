#include <iostream>
#include "game.h"

int main() {
    // Add a Dealer
    addDealer();
    // Add players
    addPlayer();
    addPlayer();
    addPlayer();
    addPlayer();
    // Start game
    start();
    turn();
    checkWin();
    
    std::cout << "Press Enter to exit...";
    std::cin.ignore(); // Wait for user to press Enter
    std::cin.get(); // Consume the newline character
    return 0;
}
