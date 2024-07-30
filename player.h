#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "deck.h"

class Player {
private:
    std::vector<int> hand;
    bool doubled;
public:
    Player() : doubled(false) {}
    void Hit();
    void Stand();
    void Double();
    void Split();
    int CheckHand();
    char choice();
    bool hasDoubled() const { return doubled; }
};

#endif // PLAYER_H
