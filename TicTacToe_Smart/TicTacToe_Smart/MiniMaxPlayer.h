/*
 *
 *  Created on: 05/03/2025
 *      Author: dongmo
 */

#ifndef MINIMAXPLAYER_H_
#define MINIMAXPLAYER_H_

#include<iostream>
#include<sstream>
#include<limits>

using namespace std;

class MiniMaxPlayer : public Player {
	double maxMove(ticTacToe board);
	double minMove(ticTacToe board);
	int steps;
public:
	MiniMaxPlayer(char ps) : Player(ps){
		steps = 100000;
	}

	void getMove(ticTacToe board, int& x, int& y);
};

void MiniMaxPlayer::getMove(ticTacToe board, int& x, int& y) {

	vector<int> emptyCells = board.getEmptyPositions();
	if (emptyCells.empty())
		return;
	random_shuffle(emptyCells.begin(), emptyCells.end());


	priority_queue < Cell > moves;

	for (int index : emptyCells) {
		steps = 100000;
		int i = index / 3;
		int j = index % 3;
		ticTacToe tempBoard(board);
		tempBoard.addMove(playerSymbol, i, j);
		if (tempBoard.isFull()) {
			if (tempBoard.gameStatus() == playerSymbol) {
				x = i;
				y = j;
				return;
			} else {
				continue;
			}
		}
		double minUtility = minMove(tempBoard);
		Cell c(i, j, minUtility);
		moves.push(c);
	}

	if (moves.size() > 0) {
		x = moves.top().x;
		y = moves.top().y;

		cout << moves.size() << " MiniMax Utility = " << moves.top().heuristic
				<< " at (" << (x + 1) << "," << (y + 1) << ")" << endl;
	}

	return;
}

double MiniMaxPlayer::maxMove(ticTacToe board) {
	vector<int> emptyCells = board.getEmptyPositions();
	if (emptyCells.empty() || steps <= 0)
		return 0.01;

	random_shuffle(emptyCells.begin(), emptyCells.end());

	double maxUtility = -2;
	for (int index : emptyCells) {
		int i = index / 3;
		int j = index % 3;
		ticTacToe tempBoard(board);
		tempBoard.addMove(playerSymbol, i, j);
		char gameStatus = tempBoard.gameStatus();
		if (gameStatus != 'C') {
			if (gameStatus == playerSymbol)
				return 1; //score 1 if wins
			else if (gameStatus == 'D')
				return 0; //score 0 if tie
			else
				return -1; //score -1 if lose
		}

		double utility;
		utility = minMove(tempBoard);

		if (utility > maxUtility) {
			maxUtility = utility;
		}
	}
	steps--;
	return maxUtility;
}

double MiniMaxPlayer::minMove(ticTacToe board) {

	vector<int> emptyCells = board.getEmptyPositions();
	if (emptyCells.empty() || steps <= 0)
		return -0.01;

	random_shuffle(emptyCells.begin(), emptyCells.end());
	double minUtility = 2;
	for (int index : emptyCells) {
		int i = index / 3;
		int j = index % 3;
		ticTacToe tempBoard(board);
		char player = (playerSymbol == 'X') ? 'O' : 'X';
		tempBoard.addMove(player, i, j);

		char gameStatus = tempBoard.gameStatus();
		if (gameStatus != 'C') {
			if (gameStatus == playerSymbol)
				return 1; //score 1 if wins
			else if (gameStatus == 'D')
				return 0; //score 0 if tie
			else
				return -1; //score -1 if lose
		}

		double utility = maxMove(tempBoard);

		if (utility < minUtility) {
			minUtility = utility;
		}
	}
	steps--;
	return minUtility;
}

#endif /* MINIMAXPLAYER_H_ */
