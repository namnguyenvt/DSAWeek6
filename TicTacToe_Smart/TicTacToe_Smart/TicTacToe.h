//Tic-Tac-Toe Header file

class ticTacToe {
public:
	ticTacToe(const ticTacToe &cboard) {
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[row][col] = cboard.board[row][col];

		noOfMoves = cboard.noOfMoves;
	}

	char getGrid(int i, int j) {
		return board[i][j];
	}

	bool isFull() {
		return (noOfMoves >= 9);
	}

	void getRandomMove(int &x, int &y);
	vector<int> getEmptyPositions();
	int heuristics(char player);
	void displayBoard() const;
	bool isValidMove(int x, int y) const;
	void addMove(char moveSymbol, int x, int y);
	char gameStatus();
	void reStart();
	ticTacToe();

private:
	char board[3][3];
	int noOfMoves;
};

vector<int> ticTacToe:: getEmptyPositions() {
	vector<int> emptyCells;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				emptyCells.push_back(i * 3 + j);
		}
	}
    return emptyCells;
}

void ticTacToe::displayBoard() const {
	cout << "   1    2    3" << endl << endl;

	for (int row = 0; row < 3; row++) {
		cout << row + 1;

		for (int col = 0; col < 3; col++) {
			cout << setw(3) << board[row][col];

			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}

	cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const {
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

void ticTacToe::getRandomMove(int &x, int &y) {
	if (isFull())
		return;

	do {
		x = rand() % 3; // @suppress("Function cannot be resolved")
		y = rand() % 3; // @suppress("Function cannot be resolved")
	} while (!isValidMove(x, y));
}

void ticTacToe::addMove(char playerSymbol, int x, int y) {
	if (!isValidMove(x, y))
		return;

	board[x][y] = playerSymbol;
	noOfMoves++;
}

char ticTacToe::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1])
				&& (board[row][1] == board[row][2]))
			return board[row][0];

	//Check columns for a win
	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col])
				&& (board[1][col] == board[2][col]))
			return board[0][col];

	//Check diagonals for a win
	if (board[0][0] != ' ' && (board[0][0] == board[1][1])
			&& (board[1][1] == board[2][2]))
		return board[0][0];

	if (board[2][0] != ' ' && (board[2][0] == board[1][1])
			&& (board[1][1] == board[0][2]))
		return board[2][0];

	if (noOfMoves < 9)
		return 'C';

	return 'D';
}

int ticTacToe::heuristics(char player) {
	int length = 0;
	//check rows
	for (int i = 0; i < 3; i++) {
		int k = 0;
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == player)
				k++;
			else {
				break;
			}
		}

		if (k > length) {
			length = k;
		}
	}

//check column
	for (int j = 0; j < 3; j++) {
		int k = 0;
		for (int i = 0; i < 3; i++) {
			if (board[i][j] == player)
				k++;
			else {
				break;
			}
		}
		if (k > length)
			length = k;
	}

//check forward diagonal
	int k = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][i] == player)
			k++;
		else {
			break;
		}
	}

	if (k > length)
		length = k;

//check backward diagonal
	k = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][2 - i] == player)
			k++;
		else {
			break;
		}
	}

	if (k > length)
		length = k;

//	cout << "The length is " << length << endl;

	return length;
}

void ticTacToe::reStart() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

ticTacToe::ticTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

