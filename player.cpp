#include "player.h"
#include <iostream>
#include <iomanip>

void Player::Hit() {
    this->hand.push_back(getCard());
}

void Player::Stand() {
    // Stand, do nothing.
}

void Player::Double() {
    this->Hit();
    this->doubled = true;
}

void Player::Split() {
    // To be implemented
}

int Player::CheckHand() {
    int sum = 0;
    for (auto i : this->hand) {
        if (i == 1 && sum + 11 <= 21) i = 11;
        std::cout << std::setw(4) << i;
        sum += i;
    }
    return sum;
}

char Player::choice() {
    std::cout << "\nChoose your action: Hit, Stand, or Double?" << std::endl;
    std::cout << "Press H to draw a card, press S to stand, press D to double down." << std::endl;
    char c;
    std::cin >> c;
    return c;
}
