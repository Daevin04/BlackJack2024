#include "game.h"
#include <iostream>
#include <string>

std::vector<Dealer*> dealerSet;
std::vector<Player*> playerSet;

void addDealer() {
    Dealer* d = new Dealer();
    dealerSet.push_back(d);
}

void addPlayer() {
    Player* p = new Player();
    playerSet.push_back(p);
}

void start() {
    system("cls"); // Clear console (Windows-specific). Use "clear" for Unix-based systems.
    std::cout << "****** Welcome to Blackjack! ******\n";
    init_deck();
    print_deck();
    shuffler();
    print_deck();
    Dealer* d = dealerSet.front();
    d->setPlayerSet(playerSet);
    d->Distribute();

    // Show the dealer's first card after shuffle
    std::cout << "\n****** Dealer's Cards ******\n";
    int dealerFirstCard = d->CheckHand(false); // Show only the first card (face-up)
    std::cout << "Dealer's face-up card: " << dealerFirstCard << std::endl;
    std::cout << "****** Player's Turn *******" << std::endl;
}

void checkWin() {
    std::cout << "\n****** Checking Results ******\n";
    Dealer* d = dealerSet.front();
    d->RevealHand(); // Reveal the dealer's hand
    int dealerHand = d->CheckHand(true);
    int player = 0;
    std::string res = "";

    std::cout << "\nDealer's Hand:\n";
    d->CheckHand(true); // Print dealer's final hand

    for (auto p : d->getPlayerSet()) {
        player++;
        std::cout << "\nPlayer" << player << "'s Hand: ";
        int playerHand = p->CheckHand();
        if (playerHand == 21 && dealerHand == 21) {
            res += "Player" + std::to_string(player) + " Blackjack Push!\n";
        } else if (playerHand == 21 && dealerHand != 21) {
            res += "Player" + std::to_string(player) + " Wins, Blackjack!\n";
        } else if (playerHand != 21 && dealerHand == 21) {
            res += "Dealer Wins, Blackjack!\n";
        } else if (playerHand < 21 && playerHand > dealerHand) {
            res += "Player" + std::to_string(player) + " Wins!\n";
        } else if (playerHand > 21) {
            res += "Player" + std::to_string(player) + " Busts, lose!\n";
        } else if (dealerHand > 21) {
            res += "Dealer Busts, Player" + std::to_string(player) + " Wins!\n";
        } else if (playerHand == dealerHand) {
            res += "Player" + std::to_string(player) + " Push!\n";
        } else if (playerHand < dealerHand) {
            res += "Player" + std::to_string(player) + " Loses!\n";
        }
    }
    std::cout << res << std::endl;
}

void turn() {
    Dealer* d = dealerSet.front();
    int player = 0;
    for (auto p : d->getPlayerSet()) {
        player++;
        std::cout << "\n****** Player" << player << "'s Turn *******\n";
        std::cout << "Player" << player << "'s Hand: ";
        int playerHand = p->CheckHand();
        char c = ' ';
        while (c != 'S' && playerHand < 21) {
            c = p->choice();
            if (c == 'H') {
                p->Hit();
                std::cout << "Player" << player << "'s Hand: ";
            } else if (c == 'S') {
                // Stand, do nothing
            } else if (c == 'D') {
                p->Double();
                std::cout << "Player" << player << " doubled down!" << std::endl;
                break; // Player must stand after doubling
            } else {
                std::cout << "Invalid input, try again." << std::endl;
            }
            playerHand = p->CheckHand();
        }
    }
    std::cout << "\n****** Dealer's Turn *******\n";
    while (d->CheckHand() < 17) 
        d->Hit();
}
