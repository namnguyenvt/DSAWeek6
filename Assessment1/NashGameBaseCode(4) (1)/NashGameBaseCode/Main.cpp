/*
 * Main.cpp
 *
 *  Created on: 1/03/2025
 *      Author: dongmo
 */

#include<iostream>
#include<string>

using namespace std;

#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "NashGame.h"
#include "RandomPlayer.h"

int main() {
	int boardSize = 5;
	string typePlayer;
	bool checkTypePlayer = false;
	cout <<"Input the size of board:" << endl;
    cin >> boardSize;
	if (boardSize < 3)
		boardSize = 3;

	Board *board = new Board(boardSize);
	while (!checkTypePlayer) {
		cout <<"Input the type of Player:" << endl;
		cin >> typePlayer;

		if (typePlayer != "Human" && typePlayer != "Random") {
			cout << "Invalid type of player" << endl;
		} else {
			checkTypePlayer = true;
		}
	}

	Player *p1 = new HumanPlayer(1, "Human (Black)");
	Player *p2;
	if (typePlayer == "Random") {
		p2 = new RandomPlayer(-1, "Random (White)");
	} else {
		p2 = new HumanPlayer(-1, "Human (White)");
	}

	NashGame game(board, p1, p2);
	game.play(typePlayer);

	delete board;
	delete p1;
	delete p2;

//	system("pause");
	return 0;
}

