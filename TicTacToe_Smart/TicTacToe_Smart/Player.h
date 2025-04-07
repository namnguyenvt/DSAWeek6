/*
 * Player.h
 *      Author: dongmo
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
protected:
	char playerSymbol;
public:
	Player(char ps) {
		playerSymbol = ps;
	}

	char getPlayerSymbol() {
		return playerSymbol;
	}

	virtual void getMove(ticTacToe board, int& x, int& y) = 0;
};

#endif /* PLAYER_H_ */
