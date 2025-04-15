//
// Created by nguye on 15/04/2025.
//

#ifndef MONTECARLOPLAYER_H
#define MONTECARLOPLAYER_H

#include <iostream>
#include <queue>
#include "Board.h"
#include "Node.h"

using namespace std;

class MonteCarloPlayer: public Player {
public:
    MonteCarloPlayer(int t, string name = "MonteCarlo") :
            Player(t, name) {
    }

    void getMonteCarloMove(Board *board, int &x, int &y) {
        priority_queue<Node> moves;
        cout << "Ultilities of moves: " << endl;
        for (int i = 0; i < board->getBoardSize(); i++) {
            for (int j = 0; j < board->getBoardSize(); j++) {
                if (board->getGrid(i, j) != ' ') {
                    continue;
                }
                Board *tempBoard;

                tempBoard->addMove(board->getTurn(), i, j);
                if (tempBoard->checkWinningStatus(board->getTurn()) == board->getTurn()) {
                    x = i;
                    y = j;
                    return;
                }

                double utility = simulation(tempBoard);

                Node c(i, j, utility);
                moves.push(c);
            }
        }

        if (!moves.empty()) {
            x = moves.top().x;
            y = moves.top().y;
        }

        return;
    }

    double simulation(Board *board) {
        int times = 10000;
        double winning = 0.0;

        for (int i = 0; i < times; i++) {
            Board *tempBoard(board);
            int playerType;
            if (board->getTurn() == -1) {
                playerType = 1;
            } else {
                playerType = -1;
            }
        }
        return (winning / (double) times);
    }

    bool getMove(Board *board, int &x, int &y) {
        bool flag = false;
        int bs = board->getBoardSize();

        while (!flag) {

            getMonteCarloMove(board, x, y);
            flag = board->validInput(x, y);
            if (flag == false)
                cout << "Invalid input! Please input again." << endl;
        }

        return true;
    }
};

#endif //MONTECARLOPLAYER_H
