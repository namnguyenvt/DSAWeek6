/*
 * HumanPlayer.h
 *      Author: dongmo
 */

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

class RandomPlayer :public Player {
public:
	RandomPlayer(char ps): Player(ps) {}

	void getMove(ticTacToe board, int& x, int& y) {
		board.getRandomMove(x,y);
		return;
	}
};

#endif /* RANDOMPLAYER_H_ */
