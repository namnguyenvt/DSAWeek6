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
#include "SimpleMindPlayer.h"
#include "MonteCarloPlayer.h"


int main() {
	int boardSize = 5;
	int typePlayer;
	bool checkTypePlayer = false;
	cout <<"Input the size of board:" << endl;
    cin >> boardSize;
	if (boardSize < 3)
		boardSize = 3;

	Board *board = new Board(boardSize);
	while (!checkTypePlayer) {
		cout <<"Input the type of Player:" << endl;
		cout <<	"1. Human vs Human" << endl;
		cout <<	"2. Random player vs Random player" << endl;
		cout <<	"3. Random player vs Simple Mind player" << endl;
		cout <<	"4. Monte Carlo player vs Simple Mind player" << endl;
		cout <<	"5. Monte Carlo player vs human player" << endl;
		cout <<	"Others: Quit" << endl;
		cin >> typePlayer;

		if (typePlayer != 1 && typePlayer != 2 && typePlayer != 3 && typePlayer != 4 && typePlayer != 5) {
			cout << "Invalid type of player" << endl;
		} else {
			checkTypePlayer = true;
		}
	}

	Player *p1;
	Player *p2;
	if (typePlayer == 1) {
		p1 = new HumanPlayer(1, "Human (Black)");
		p2 = new HumanPlayer(-1, "Human (White)");
	} else if (typePlayer == 2) {
		p1 = new RandomPlayer(1, "Random (Black)");
		p2 = new RandomPlayer(-1, "Random (White)");
	} else if (typePlayer == 3) {
		p1 = new RandomPlayer(1, "Random (Black)");
		p2 = new SimpleMindPlayer(-1, "SimpleMindBot (White)");
	} else if (typePlayer == 4) {
		p1 = new SimpleMindPlayer(1, "SimpleMindBot (Black)");
		p2 = new SimpleMindPlayer(-1, "SimpleMindBot (White)");
	}

	NashGame game(board, p1, p2);
	game.play(typePlayer);

	delete board;
	delete p1;
	delete p2;

//	system("pause");
	return 0;
}

