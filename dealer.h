#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include "player.h"

class Dealer {
private:
    std::vector<int> hand;
    std::vector<Player*> playerSet;
    bool revealed = false; // Indicates if the dealer's hand is fully revealed

public:
    void setPlayerSet(std::vector<Player*>& playerSet);
    std::vector<Player*> getPlayerSet();
    void Hit();
    void Distribute();
    int CheckHand(bool reveal = false);
    void RevealHand();
    bool isRevealed() const { return revealed; }
};

#endif // DEALER_H
