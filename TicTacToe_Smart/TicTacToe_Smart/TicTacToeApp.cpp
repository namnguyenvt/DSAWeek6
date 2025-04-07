//Main program

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#include "Cell.h"
#include "TicTacToe.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "BestFirstPlayer.h"
#include "MonteCarloPlayer.h"
#include "MiniMaxPlayer.h"
#include "Game.h"

using namespace std;

int main() {
	srand(time(0)); // @suppress("Function cannot be resolved")

	Game game;
	game.play();

	return 0;
}
