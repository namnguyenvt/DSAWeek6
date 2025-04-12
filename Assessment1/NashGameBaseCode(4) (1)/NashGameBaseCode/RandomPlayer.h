//
// Created by nguye on 9/04/2025.
//

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

class RandomPlayer: public Player {
public:
    RandomPlayer(int t, string name = "Human") :
            Player(t, name) {
    }
    bool getMove(Board*, int&, int&);

    void getRandomMove(int &x, int &y);
};

void RandomPlayer::getRandomMove(int &x, int &y) {
    int random = rand() % Board::emptyCells.size();
    x = emptyCells[random].x;
    y = emptyCells[random].y;
}

bool RandomPlayer::getMove(Board *board, int &x, int &y) {
    bool flag = false;
    int bs = board->getBoardSize();

    while (!flag) {

        getRandomMove(x, y);
        flag = board->validInput(x, y);
        if (flag == false)
            cout << "Invalid input! Please input again." << endl;
    }

    return true;
}

#endif //RANDOMPLAYER_H_
