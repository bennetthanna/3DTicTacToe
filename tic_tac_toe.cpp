#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// void print_boards(vector<char>board) {
// 	for (int i = 0; i < board.size(); ++i) {
// 		cout << board[i];
// 	}
// }

int main() {

	bool winner = false;
	int board_number, row_number, column_number;

	cout << endl << "Welcome to 3D Four Board Tic Tac Toe" << endl;
	cout << "When it is your turn, you will be prompted to enter your desired move" << endl;
	cout << "You will do so in the format board_number row_number column_number" << endl;
	cout << "Options range from 0-3" << endl;
	cout << "For example: 0 3 1" << endl;
	cout << "This would be board 0, row 3, column 1" << endl << endl;

	char board[4][4][4];

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				board[i][j][k] = 'N';
			}
		}
	}

	board[0][3][1] = 'X';

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

	board[0][3][1] = 'N';

	if (!winner) {
		cout << "Player 1 what's your move?" << endl;
		cin >> board_number >> row_number >> column_number;
		if (board[board_number][row_number][column_number] == 'N') {
			board[board_number][row_number][column_number] = '1';
		} else {
			cout << "Sorry Player 1. That spot is already taken. Try again" << endl;
		}
	}

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