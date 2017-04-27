#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void initialize_board (char board[4][4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				board[i][j][k] = 'N';
			}
		}
	}
}

void print_board(char board[4][4][4]) {
	for (int i = 0; i < 4; ++i) {
		cout << "Board " << i << endl;
		cout << "   0  1  2  3 " << endl;
		for (int j = 0; j < 4; ++j) {
			cout << j << " ";
			for (int k = 0; k < 4; ++k) {
					cout << "[" << board[i][j][k] << "]";
			} cout << endl;
		} cout << endl;
	}
}

// cases where someone wins on board[i][j][k]
// on same board (all i's are the same)
	// all rows are the same (all j's are the same)
	// all columns are the same (all k's are the same)
	// diagonal (0,0)(1,1)(2,2)(3,3) or (3,0)(2,1)(1,2)(0,3)
// on all different boards (all i's are different)
	// all same coordinate (j and k same - example: all (0,0) on all boards - board[i][j][k] == board[i+1][j][k])
	// diagonal down the boards

int main() {

	bool winner = false;
	int board_number, row_number, column_number, player;

	cout << endl << "Welcome to 3D Four Board Tic Tac Toe" << endl;
	cout << "When it is your turn, you will be prompted to enter your desired move" << endl;
	cout << "You will do so in the format board_number row_number column_number" << endl;
	cout << "Options range from 0-3" << endl;
	cout << "For example: 0 3 1" << endl;
	cout << "This would be board 0, row 3, column 1" << endl << endl;

	char board[4][4][4];
	initialize_board(board);
	board[0][3][1] = 'X';
	print_board(board);
	board[0][3][1] = 'N';
	player = 1;

	do {
		if (player == 1) {
			cout << "Player 1 what's your move?\n";
			cin >> board_number >> row_number >> column_number;

			while (board_number < 0 || board_number > 3 || 
				   row_number < 0 || row_number > 3 ||
				   column_number < 0 || column_number > 3 ||
				   board[board_number][row_number][column_number] != 'N') {
				if (board_number < 0 || board_number > 3 || 
				   row_number < 0 || row_number > 3 ||
				   column_number < 0 || column_number > 3) {
					cout << "Sorry Player 1. That was an invalid move. Options are 0-3\n";
					cin >> board_number >> row_number >> column_number;
				} else if (board[board_number][row_number][column_number] != 'N') {
					cout << "Sorry Player 1. That spot is already taken. Try again\n";
					cin >> board_number >> row_number >> column_number;
				}
			}
			board[board_number][row_number][column_number] = '1';
			print_board(board);
			player = 2;
		} else if (player == 2) {
			cout << "Player 2 what's your move?\n";
			cin >> board_number >> row_number >> column_number;

			while (board_number < 0 || board_number > 3 || 
				   row_number < 0 || row_number > 3 ||
				   column_number < 0 || column_number > 3 ||
				   board[board_number][row_number][column_number] != 'N') {
				if (board_number < 0 || board_number > 3 || 
				   row_number < 0 || row_number > 3 ||
				   column_number < 0 || column_number > 3) {
					cout << "Sorry Player 1. That was an invalid move. Options are 0-3\n";
					cin >> board_number >> row_number >> column_number;
				} else if (board[board_number][row_number][column_number] != 'N') {
					cout << "Sorry Player 1. That spot is already taken. Try again\n";
					cin >> board_number >> row_number >> column_number;
				}
			}
			board[board_number][row_number][column_number] = '2';
			print_board(board);
			player = 1;
		}

		// check if someone won

	} while (!winner);
}