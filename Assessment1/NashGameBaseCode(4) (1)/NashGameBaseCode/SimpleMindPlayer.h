//
// Created by 22069149 on 14/04/2025.
//

#ifndef SIMPLEMINDPLAYER_H_
#define SIMPLEMINDPLAYER_H_

#include <iostream>
#include <queue>
#include "Node.h"
#include "Board.h"

using namespace std;

class SimpleMindPlayer: public Player {
public:
    SimpleMindPlayer(int t, string name = "SimpleMindBot") :
            Player(t, name) {
    }

    bool getMove(Board*, int&, int&);

    double heuristic(Board *board, int playerType);

    void getBestMove(Board *board, int &x, int &y, int playerType);
};

// Best-First Search
void SimpleMindPlayer::getBestMove(Board *board, int& x, int& y, int playerType) {
    priority_queue<Node> moves;

    // White Player
    if (playerType == -1) {
        for (int i = 0; i < board->getBoardSize(); i++) {
            for (int j = 0; j < board->getBoardSize(); j++) {
                Board tempBoard(*board);
                if (tempBoard.validInput(i, j)) {
                    tempBoard.addMove(playerType, i, j);
                    Node c(i, j, heuristic(board, playerType));
                    moves.push(c);
                }
            }
        }

        if (moves.size() > 0) {
            x = moves.top().x;
            y = moves.top().y;
        } else {
            cout << "Cannot find the new replacement";
        }

        cout << "Heuristic = " << moves.top().heuristic << " at (" << (x + 1) << "," << (y + 1) << ")" << endl;
    } else {
        for (int i = 0; i < board->getBoardSize(); i++) {
            for (int j = 0; j < board->getBoardSize(); j++) {
                Board tempBoard(*board);
                if (tempBoard.validInput(i, j)) {
                    tempBoard.addMove(playerType, i, j);
                    Node c(i, j, heuristic(board, playerType));
                    moves.push(c);
                }
            }
        }

        if (moves.size() > 0) {
            x = moves.top().x;
            y = moves.top().y;
        } else {
            cout << "Cannot find the new replacement";
        }

        cout << "Heuristic = " << moves.top().heuristic << " at (" << (x + 1) << "," << (y + 1) << ")" << endl;
    }
}

double SimpleMindPlayer::heuristic(Board *board, int playerType) {
    int boardSize = board->getBoardSize();
    int connectCount = 0;

    // White Player
    if (playerType == -1) {
        // White Player moves left to right
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board->getGrid(i, j) == playerType) {
                    connectCount += j;  // The more close to the right, the more better
                    break;
                }
            }
        }
    } else { // Black Player
        //  moves top to bottom
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board->getGrid(i, j) == playerType) {
                    connectCount += j;  // The more close to bottom, the more better
                    break;
                }
            }
        }
    }
    double heuristicValue = (double)(boardSize * boardSize - connectCount) / boardSize;
    return heuristicValue;
}

bool SimpleMindPlayer::getMove(Board *board, int &x, int &y) {
    bool flag = false;
    int bs = board->getBoardSize();

    while (!flag) {

        getBestMove(&*board, x, y, board->getTurn());
        flag = board->validInput(x, y);
        if (flag == false)
            cout << "Invalid input! Please input again." << endl;
    }

    return true;
}

#endif //SIMPLEMINDPLAYER_H_
