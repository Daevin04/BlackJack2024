#include "dealer.h"

void Dealer::setPlayerSet(std::vector<Player*>& playerSet) {
    this->playerSet = playerSet;
}

std::vector<Player*> Dealer::getPlayerSet() {
    return this->playerSet;
}

void Dealer::Hit() {
    this->hand.push_back(getCard());
}

void Dealer::Distribute() {
    int numPlayers = this->playerSet.size();
    
    // First round of dealing: Player 1, Player 2, Player 3, Player 4, Dealer (face-up)
    for (int i = 0; i < numPlayers; i++) {
        this->playerSet[i]->Hit();
    }
    this->Hit(); // Dealer's face-up card
    
    for (int i = 0; i < numPlayers; i++) {
        this->playerSet[i]->Hit();
    }
    this->Hit(); // Dealer's face-down card
    
    // Optionally reveal dealer's face-down card here if desired
}

int Dealer::CheckHand(bool reveal) {
    int sum = 0;
    std::cout << "Dealer Hand:" << std::endl;
    for (auto i : this->hand) {
        if (i == 1 && sum + 11 <= 21) i = 11;
        std::cout << "Card:" << i << std::endl;
        sum += i;
    }
    return sum;
}

void Dealer::RevealHand() {
    std::cout << "Dealer's Hand:" << std::endl;
    for (auto i : this->hand) {
        std::cout << "Card:" << i << std::endl;
    }
}
