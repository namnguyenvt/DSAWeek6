//
// Created by nguye on 15/04/2025.
//

#ifndef NODE_H
#define NODE_H

struct Node {
    int x;
    int y;
    double heuristic;
    Node(int xx =-1, int yy =-1, double hh = 0):x(xx), y(yy), heuristic(hh){}

    bool operator<(const Node& c) const {
        return heuristic < c.heuristic;
    }
};

#endif //NODE_H
