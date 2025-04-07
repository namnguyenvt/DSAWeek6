/*
 * MonteCarloPlayer.h
 *      Author: dongmo
 */

#ifndef MONTECARLOPLAYER_H_
#define MONTECARLOPLAYER_H_

class MonteCarloPlayer: public Player {
public:
	MonteCarloPlayer(char ps) :
			Player(ps) {
	}

	void getMove(ticTacToe board, int &x, int &y) {
		priority_queue<Cell> moves;
		cout << "Utilities of Moves" << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board.getGrid(i, j) != ' ') {
					cout << "  x   ";
					continue;
				}
				ticTacToe tempBoard(board);

				tempBoard.addMove(playerSymbol, i, j);
				if (tempBoard.gameStatus() == playerSymbol) {
					x = i;
					y = j;
					return;
				}

				double utility = simulation(tempBoard);

				Cell c(i, j, utility);
				moves.push(c);
				cout << setw(5) << c.heuristic << " ";
			}
			cout << endl;
		}

		if (!moves.empty()) {
			x = moves.top().x;
			y = moves.top().y;
			cout << "Best utility " << moves.top().heuristic << endl;
		}

		return;
	}

	double simulation(ticTacToe board) {
		int times = 10000;
		double winning = 0.0;

		for (int i = 0; i < times; i++) {
			ticTacToe tempBoard(board);
			char player = (playerSymbol == 'X') ? 'O' : 'X';
			winning += expansion(player, tempBoard);
		}
		return (winning / (double) times);
	}

	double expansion(char player, ticTacToe board) {

		if (board.gameStatus() == playerSymbol) {
			return 1.0;
		} else if (board.gameStatus() == 'D') { //draw game
			return 0.5;
		} else if (board.gameStatus() != 'C') { //No player is winning; continue.
			return 0.0;
		}
		int x, y;
		board.getRandomMove(x, y);
		board.addMove(player, x, y);
		player = (player == 'X') ? 'O' : 'X';

		return expansion(player, board);
	}
}
;

#endif /* MONTECARLOPLAYER_H_ */
