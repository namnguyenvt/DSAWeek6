//
// Created by 22069149 on 14/04/2025.
//

#ifndef SIMPLEMINDPLAYER_H_
#define SIMPLEMINDPLAYER_H_

#include <iostream>
#include <vector>
#include <queue>
#include "Board.h"
#include "algorithm"
#include "cmath"

using namespace std;

struct Node {
    int x;
    int y;
    double heuristic;
    Node(int x =-1, int y =-1, double heuristic = 0):x(x), y(y), heuristic(heuristic){}

    bool operator<(const Node& c) const {
        return heuristic < c.heuristic;
    }
};

class SimpleMindPlayer: public Player {
private:
    double heuristicCost;
public:
    SimpleMindPlayer(int t, string name = "SimpleMindBot") :
            Player(t, name) {
    }

    vector<Node> getNode();

    bool getMove(Board*, int&, int&);

    int estimatedPathCost(Board *board, Node& startNode, int playerType);

    int heuristic(int startX, int startY, int goalX, int goalY);

    void getBestMove(Board *board, int &x, int &y);
};

int SimpleMindPlayer::heuristic(int startX, int startY, int goalX, int goalY) {
    return (abs(startX - goalX) + abs(startX + startY - goalX - goalY) + abs(startY - goalY)) / 2;
}

// Best-First Search
int SimpleMindPlayer::estimatedPathCost(Board *board, Node& startNode, int playerType) {
    int boardSize = board->getBoardSize();
    priority_queue<vector<Node>> trackingPriorityQueue;
    priority_queue<vector<Node>> visitedList;

    // White
    if (playerType == -1) {
        for (int goalX = 0; goalX < boardSize; goalX++) {
            heuristicCost = heuristic(startNode.x, startNode.y, goalX, boardSize - 1);
            trackingPriorityQueue.push({goalX, boardSize - 1, int(heuristicCost)});
        }

        while (!trackingPriorityQueue.empty()) {
            vector<Node> trackingNodes = {startNode.x, startNode.y};
            trackingNodes = trackingPriorityQueue.top();
            trackingPriorityQueue.pop();
            visitedList.push(trackingNodes);

            // Test
            cout << "TrackingNode size: " << trackingNodes.size() << endl;
            cout << "trackingNode values: ";
            for (Node& v : trackingNodes) {
                cout << v.x << " " << v.y;
            }
            cout << endl;

            if (!trackingNodes.empty() && trackingNodes[1] == boardSize - 1) {
                return heuristicCost;
            }
        }
    }
    return 0;
}

void SimpleMindPlayer::getBestMove(Board *board, Node& startNode, int &x, int &y) {
    x = startNode.[heuristicCost].x;
    y = getNode()[heuristicCost].y;
}

bool SimpleMindPlayer::getMove(Board *board, int &x, int &y) {
    bool flag = false;
    int bs = board->getBoardSize();

    while (!flag) {

        getBestMove(board, x, y);
        flag = board->validInput(x, y);
        if (flag == false)
            cout << "Invalid input! Please input again." << endl;
    }

    return true;
}

#endif //SIMPLEMINDPLAYER_H_
