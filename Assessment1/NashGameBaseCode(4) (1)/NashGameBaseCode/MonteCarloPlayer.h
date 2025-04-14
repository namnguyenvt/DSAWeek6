//
// Created by nguye on 15/04/2025.
//

#ifndef MONTECARLOPLAYER_H
#define MONTECARLOPLAYER_H

#include <iostream>
#include <queue>
#include "Board.h"

using namespace std;

class MonteCarloPlayer: public Player {
public:
    MonteCarloPlayer(int t, string name = "MonteCarlo") :
            Player(t, name) {
    }
    bool getMove(Board*, int&, int&);
};

#endif //MONTECARLOPLAYER_H
