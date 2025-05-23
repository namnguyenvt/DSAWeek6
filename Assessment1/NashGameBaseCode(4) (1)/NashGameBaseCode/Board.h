/*
 * BaseBoard.h
 *
 *  Created on: 1/03/2025
 *      Author: dongmo
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Cell {
public:
	int x;
	int y;
	Cell(int x, int y) : x(x), y(y) {}
};

class Board {
private:
	int boardSize;
	int turn;
	int **grid;
	vector<Cell> emptyCells;
public:

	Board(int bs) {
		boardSize = bs;
		grid = new int*[boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = 0;
			}
		turn = 1;

		// initialize empty Cells
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				emptyCells.push_back(Cell(i, j));
			}
		}
	}


	virtual ~Board() {

		for (int i = 0; i < boardSize; i++)
			delete[] grid[i];

		delete[] grid;
	}

	Board(Board &cboard) {
		boardSize = cboard.getBoardSize();

		grid = new int*[boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				grid[i][j] = 0;

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = cboard.getGrid(i, j);
			}

		turn = cboard.getTurn();
	}

	int getBoardSize() {
		return boardSize;
	}

	int getGrid(int x, int y) {
		return grid[x][y];
	}

	int getTurn() {
		return turn;
	}

    // Assessment 1 - task 1
    bool isBoardFull();

	bool validInput(int, int);

	bool addMove(int playerType, int &x, int &y);

	bool dfs(bool** visited, int playerType, int x, int y);

	vector<Cell> getEmptyCells();

	void printBoard();

	stack<vector<int>> checkNeighbours(int player, int x, int y);

	// Assessment 1 - task 3
	int checkWinningStatus(int playerType);

};

// Task 3.3
stack<vector<int>> Board::checkNeighbours(int player, int x, int y) {
	stack<vector<int>> neighbours;

	// Hexagonal neighbors (down-left, down-right, left, right, up-left, up-right)
	int dx[] = {1, 1, 0, 0, -1, -1};
	int dy[] = {-1, 0, -1, 1, 0, 1};

	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && grid[nx][ny] == player) {
			neighbours.push(vector{nx, ny});
		}
	}

	return neighbours;
}

int Board::checkWinningStatus(int playerType) {
		// To be implemented
		//Check col for White Player Win
		stack<vector<int>> stacktrackingStack;
		stack<vector<int>> visitedList;
		//White
		if (playerType == -1) {
			for (int i = 0; i < boardSize; i++) {
				if (grid[i][0] == playerType) {
					stacktrackingStack.push(vector{i, 0});
				}
			}

			while (!stacktrackingStack.empty()) {
				vector<int> trackingCell = stacktrackingStack.top();
				stacktrackingStack.pop();
				visitedList.push(trackingCell);

				// Test
				cout << "Tracking Cell size: " << trackingCell.size() << endl;
				cout << "trackingCell values: ";
				for (int v : trackingCell) cout << v << " ";
				cout << endl;

				if (trackingCell[1] == boardSize - 1) {
					return playerType;
				}
				stack<vector<int> > neighbours = checkNeighbours(playerType, trackingCell[0], trackingCell[1]);
				while (!neighbours.empty()) {
					vector<int> neighbourCell = neighbours.top();
					neighbours.pop();
					bool checkExist = false;
					stack<vector<int>> tempVisitList = visitedList;
					while (!tempVisitList.empty()) {
						if (tempVisitList.top() == neighbourCell) {
							checkExist = true;
						}
						tempVisitList.pop();
					}
					if (checkExist) {
						continue;
					} else {
						stacktrackingStack.push(neighbourCell);
					}
				}
			}

			while (!stacktrackingStack.empty()) {
				stacktrackingStack.pop(); // removes one element at a time
			}
		} else { // Black
			for (int i = 0; i < boardSize; i++) {
				if (grid[0][i] == playerType) {
					stacktrackingStack.push(vector{0, i});
				}
			}

			while (!stacktrackingStack.empty()) {
				vector<int> trackingCell = stacktrackingStack.top();
				stacktrackingStack.pop();
				visitedList.push(trackingCell);

				// Test
				cout << "Tracking Cell size: " << trackingCell.size() << endl;
				cout << "trackingCell values: ";
				for (int v : trackingCell) cout << v << " ";
				cout << endl;

				if (trackingCell[0] == boardSize - 1) {
					return playerType;
				}
				stack<vector<int> > neighbours = checkNeighbours(playerType, trackingCell[0], trackingCell[1]);

				while (!neighbours.empty()) {
					vector<int> neighbourCell = neighbours.top();
					neighbours.pop();
					cout << "Neighbour Cell size: " << neighbourCell.size() << endl;
					cout << "Neighbour values: ";
					for (int v : neighbourCell) cout << v << " ";
					cout << endl;
					bool checkExist = false;
					stack<vector<int>> tempVisitList = visitedList;
					while (!tempVisitList.empty()) {
						if (tempVisitList.top() == neighbourCell) {
							checkExist = true;
						}
						tempVisitList.pop();
					}
					if (checkExist) {
						continue;
					} else {
						stacktrackingStack.push(neighbourCell);
					}
				}
			}

			while (!stacktrackingStack.empty()) {
				stacktrackingStack.pop(); // removes one element at a time
			}
		}
	while (!visitedList.empty()) {
		visitedList.pop(); // removes one element at a time
	}
		return 0;
	}

// Assessment 1 - task 1
bool Board::isBoardFull() {
  	for (int row = 0; row < boardSize; row++) {
	    for (int col = 0; col < boardSize; col++) {
			if (grid[row][col] == 0) {
			    return false;
			}
		}
    }
    return true;
}

bool Board::validInput(int x, int y) {
	if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) {
		cout << "Move (" << x + 1 << ", " << y + 1 << ") out of range!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	return true;
}

bool Board::addMove(int playerType, int &x, int &y) {

	if (playerType != turn) {
		cout << "It is not the player's turn!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	grid[x][y] = playerType;

	turn = -1 * turn;
	return true;
}

vector<Cell> Board::getEmptyCells() {
	return emptyCells;
}

void Board::printBoard() {
	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		if (j < 9)
			cout << j + 1 << "   ";
		else
			cout << j + 1 << "  ";
	}
	cout << endl;

	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}
	cout << endl;

	for (int i = 0; i < boardSize; i++) {
		for (int k = 0; k < i; k++)
			cout << "  ";

		if (i < 9)
			cout << " " << i + 1 << " ";
		else
			cout << i + 1 << " ";

		for (int j = 0; j < boardSize; j++) {
			if (grid[i][j] == 0) {
				if (j == 0) {
					cout << "|   |";
				} else {
					cout << "   |";
				}
			} else if (grid[i][j] == 1) {
				if (j == 0) {
					cout << "| B |";
				} else {
					cout << " B |";
				}
			} else {
				if (j == 0) {
					cout << "| W |";
				} else {
					cout << " W |";
				}
			}
		}
		cout << endl;
	}

	for (int k = 0; k <= boardSize; k++)
		cout << "  ";

	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}

	cout << endl;
	cout << endl;
}

#endif /* BOARD_H_ */
