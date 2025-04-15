/*
 * HexGame.h
 *
 *  Created on: 1/03/2025
 *      Author: dongmo
 */

#ifndef NASHGAME_H_
#define NASHGAME_H_

class NashGame {
private:
	Board *board;
	Player *player[2];
public:
	NashGame(Board *b, Player *p1, Player *p2) {
		board = b;
		player[0] = p1;
		player[1] = p2;
	}

	void play(int typePlayer);
};

void NashGame::play(int typePlayer) {
	int won = 0;
	board->printBoard();

	while (!won) {
		bool isFull = board->isBoardFull();

		// Terminate when board is full
		if (isFull) {
			cout << "The board is full, please try a new game";
			return;
		}

		// Human Player
		int playerType = board->getTurn();
		int playerIndex = (playerType == player[0]->getType()) ? 0 : 1;
		int x = -1;
		int y = -1;

		if (!player[playerIndex]->getMove(board, x, y)) {
			cout << "No available move" << endl;
			return;
		}

		cout << player[playerIndex]->getPlayerName() << " plays " << " ("
				<< x + 1 << ", " << y + 1 << "):" << endl;

		if (!board->addMove(playerType, x, y))
			return;

		board->printBoard();
		won = board->checkWinningStatus(playerType);
        if(won == playerType)
        	cout << player[playerIndex]->getPlayerName() << " player wins!" << endl;

		// Random Player
		if (typePlayer == 2) {
			if (won) {
				return;
			}
			isFull = board->isBoardFull();
			if (isFull) {
				cout << "The board is full, please try a new game";
				return;
			}

			// RandomPlayer
			playerType = board->getTurn();
			playerIndex = (playerType == player[0]->getType()) ? 0 : 1;
			x = -1;
			y = -1;

			if (!player[playerIndex]->getMove(board, x, y)) {
				cout << "No available move" << endl;
				return;
			}

			cout << player[playerIndex]->getPlayerName() << " plays " << " ("
					<< x + 1 << ", " << y + 1 << "):" << endl;

			if (!board->addMove(playerType, x, y))
				return;

			board->printBoard();
			won = board->checkWinningStatus(playerType);
			cout << "Player Win:" << won << endl;
			if(won == playerType)
				cout << player[playerIndex]->getPlayerName() << " player wins!" << endl;
		}

		// Simple Mind Player
		if (typePlayer == 3) {
			if (won) {
				return;
			}
			isFull = board->isBoardFull();
			if (isFull) {
				cout << "The board is full, please try a new game";
				return;
			}

			// Simple Mind Player
			playerType = board->getTurn();
			playerIndex = (playerType == player[0]->getType()) ? 0 : 1;
			x = -1;
			y = -1;

			if (!player[playerIndex]->getMove(board, x, y)) {
				cout << "No available move" << endl;
				return;
			}

			cout << player[playerIndex]->getPlayerName() << " plays " << " ("
					<< x + 1 << ", " << y + 1 << "):" << endl;

			if (!board->addMove(playerType, x, y))
				return;

			board->printBoard();
			won = board->checkWinningStatus(playerType);
			cout << "Player Win:" << won << endl;
			if(won == playerType)
				cout << player[playerIndex]->getPlayerName() << " player wins!" << endl;
		}

		// Monte Carlo Player
		if (typePlayer == 4) {
			if (won) {
				return;
			}
			isFull = board->isBoardFull();
			if (isFull) {
				cout << "The board is full, please try a new game";
				return;
			}

			// Monte Carlo Player
			playerType = board->getTurn();
			playerIndex = (playerType == player[0]->getType()) ? 0 : 1;
			x = -1;
			y = -1;

			if (!player[playerIndex]->getMove(board, x, y)) {
				cout << "No available move" << endl;
				return;
			}

			cout << player[playerIndex]->getPlayerName() << " plays " << " ("
					<< x + 1 << ", " << y + 1 << "):" << endl;

			if (!board->addMove(playerType, x, y))
				return;

			board->printBoard();
			won = board->checkWinningStatus(playerType);
			cout << "Player Win:" << won << endl;
			if(won == playerType)
				cout << player[playerIndex]->getPlayerName() << " player wins!" << endl;
		}
	}
}

#endif /* NASHGAME_H_ */
