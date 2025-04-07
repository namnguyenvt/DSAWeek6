/*
 * Game.h
 *      Author: dongmo
 */

#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	void play() {
		ticTacToe board;
		board.displayBoard();
		Player *players[2];
//		players[0] = new BestFirstPlayer('X');
//		players[0] = new MonteCarloPlayer('X');
		players[0] = new MiniMaxPlayer('X');
//		players[1] = new RandomPlayer('O');
		players[1] = new MonteCarloPlayer('O');
//		players[1] = new MiniMaxPlayer('O');

		bool done = false;
		int i = 0;
		while (!done) {
			int x = -1;
			int y = -1;
			players[i]->getMove(board, x, y);
			board.addMove(players[i]->getPlayerSymbol(), x, y);
			cout << players[i]->getPlayerSymbol() << " makes move ("
					<< (x + 1) << "," << (y + 1) << ") " << endl;
			board.displayBoard();
			done = checkWin(players[i]->getPlayerSymbol(), board);
			i = (i + 1) % 2;
		}
	}

	bool checkWin(char playerSymbol, ticTacToe board) {
		char gStatus = board.gameStatus();

		if (gStatus == playerSymbol) {
			cout << "Player " << playerSymbol << " wins!" << endl;
			return true;
		} else if (gStatus == 'D') {
			cout << "This game is a draw!" << endl;
			return true;
		} else if (gStatus != 'C') {
			return true;
		} else
			return false;
	}
};

#endif /* GAME_H_ */
