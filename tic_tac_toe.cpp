#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool winner = false;
char winner_number = '0';
string winning_move;

void initialize_board (char board[4][4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				board[i][j][k] = ' ';
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

void check_for_winner(char board[4][4][4]) {
	if (board[0][0][0] == board[1][1][1] && 
		board[1][1][1] == board[2][2][2] && 
		board[2][2][2] == board[3][3][3] &&
		board[0][0][0] != ' ') {
		winner_number = board[0][0][0];
		winner = true;
		winning_move = "the diagonal through the boards from top left back to bottom right front";
	} else if (board[0][0][3] == board[1][1][2] && 
			   board[1][1][2] == board[2][2][1] && 
   			   board[2][2][1] == board[3][3][0] &&
   			   board[0][0][3] != ' ') {
		winner_number = board[0][0][3];
		winner = true;
		winning_move = "the diagonal through the boards from top right back to bottom left front";
	} else if (board[0][3][0] == board[1][2][1] && 
			   board[1][2][1] == board[2][1][2] && 
		   	   board[2][1][2] == board[3][0][3] &&
		   	   board[0][3][0] != ' ') {
		winner_number = board[0][3][0];
		winner = true;
		winning_move = "the diagonal through the boards from top left front to bottom right back";
	} else if (board[0][3][3] == board[1][2][2] && 
			   board[1][2][2] == board[2][1][1] && 
			   board[2][1][1] == board[3][0][0] &&
		 	   board[0][3][3] != ' ') {
		winner_number = board[0][3][3];
		winner = true;
		winning_move = "the diagonal through the boards from top right front to bottom left back";
	}

	for (int i = 0; i < 4; ++i) {
		if (board[i][0][0] == board[i][1][1] && 
			board[i][1][1] == board[i][2][2] && 
			board[i][2][2] == board[i][3][3] &&
			board[i][0][0] != ' ') {
			winner_number = board[i][0][0];
			winner = true;
			winning_move = "the diagonal on one board from top left to bottom right";
		} else if (board[i][0][3] == board[i][1][2] && 
				   board[i][1][2] == board[i][2][1] && 
				   board[i][2][1] == board[i][3][0] &&
				   board[i][0][3] != ' ') {
			winner_number = board[i][0][3];
			winner = true;
			winning_move = "the diagonal on one board from bottom left to top right";
		} else if (board[0][i][0] == board[1][i][1] && 
				   board[1][i][1] == board[2][i][2] && 
				   board[2][i][2] == board[3][i][3] &&
				   board[0][i][0] != ' ') {
			winner_number = board[0][i][0];
			winner = true;
			winning_move = "the diagonal through the boards from top left to bottom right same row";
		} else if (board[0][i][3] == board[1][i][2] && 
				   board[1][i][2] == board[2][i][1] && 
				   board[2][i][1] == board[3][i][0] &&
				   board[0][i][3] != ' ') {
			winner_number = board[0][i][3];
			winner = true;
			winning_move = "the diagonal through the boards from top right to bottom left same row";
		} else if (board[0][3][i] == board[1][2][i] && 
				   board[1][2][i] == board[2][1][i] && 
				   board[2][1][i] == board[3][0][i] &&
				   board[0][3][i] != ' ') {
			winner_number = board[0][i][0];
			winner = true;
			winning_move = "the diagonal through the boards from top front to bottom back same column";
		} else if (board[0][0][i] == board[1][1][i] && 
				   board[1][1][i] == board[2][2][i] && 
				   board[2][2][i] == board[3][3][i] &&
				   board[0][0][i] != ' ') {
			winner_number = board[0][0][i];
			winner = true;
			winning_move = "the diagonal through the boards from top back to bottom front same column";
		}
		for (int j = 0; j < 4; ++j) {
			if (board[i][j][0] == board[i][j][1] && 
				board[i][j][1] == board[i][j][2] && 
				board[i][j][2] == board[i][j][3] &&
				board[i][j][0] != ' ') {
				winner_number = board[i][j][0];
				winner = true;
				winning_move = "the row on one board";
			} else if (board[i][0][j] == board[i][1][j] && 
					   board[i][1][j] == board[i][2][j] && 
					   board[i][2][j] == board[i][3][j] &&
					   board[i][0][j] != ' ') {
				winner_number = board[i][0][j];
				winner = true;
				winning_move = "the column on one board";
			} else if (board[0][i][j] == board[1][i][j] &&
					   board[1][i][j] == board[2][i][j] &&
					   board[2][i][j] == board[3][i][j] &&
					   board[0][i][j] != ' ') {
				winner_number = board[0][i][j];
				winner = true;
				winning_move = "the columns through the boards";
			}
		}
	}
}

// cases where someone wins on board[i][j][k]
// i = board #
// j = row #
// k = column #
// on same board (all i's are the same)
	// all rows are the same (all j's are the same) DONE
	// all columns are the same (all k's are the same) DONE
	// diagonal (0,0)(1,1)(2,2)(3,3) or (3,0)(2,1)(1,2)(0,3) DONE
// on all different boards (all i's are different)
	// all same coordinate (j and k same - example: all (0,0) on all boards - board[i][j][k] == board[i+1][j][k]) DONE
	// diagonal down the boards
		// all j's are the same, all k's are different DONE
		// all k's are the same, all j's are different DONE
		// (0,0,0)(1,1,1)(2,2,2)(3,3,3) DONE
		// (0,0,3)(1,1,2)(2,2,1)(3,3,0) DONE
		// (0,3,0)(1,2,1)(2,1,2)(3,0,3) DONE
		// (0,3,3)(1,2,2)(2,1,1)(3,0,0) DONE

int main() {

	int board_number, row_number, column_number, player;

	cout << endl << "Welcome to 3D Four Board Tic Tac Toe" << endl;
	cout << "When it is your turn, you will be prompted to enter your desired move" << endl;
	cout << "You will do so in the format board_number row_number column_number" << endl;
	cout << "Options range from 0-3" << endl;
	cout << "For example: 0 3 1" << endl;
	cout << "This would be board 0, row 3, column 1 and would be as follows" << endl << endl;

	char board[4][4][4];
	initialize_board(board);
	board[0][3][1] = 'X';
	print_board(board);
	board[0][3][1] = ' ';
	player = 1;

	do {
		cout << "Player " << player << " what's your move?\n";
		cin >> board_number >> row_number >> column_number;
		cout << endl;
		while (board_number < 0 || board_number > 3 || 
			   row_number < 0 || row_number > 3 ||
			   column_number < 0 || column_number > 3 ||
			   board[board_number][row_number][column_number] != ' ') {
			if (board_number < 0 || board_number > 3 || 
			   row_number < 0 || row_number > 3 ||
			   column_number < 0 || column_number > 3) {
				cout << "Sorry Player " << player << ". That was an invalid move. Options are 0-3\n";
				cin >> board_number >> row_number >> column_number;
			} else if (board[board_number][row_number][column_number] != ' ') {
				cout << "Sorry Player " << player << ". That spot is already taken. Try again\n";
				cin >> board_number >> row_number >> column_number;
			}
		}
		board[board_number][row_number][column_number] = player+'0';
		print_board(board);

		if (player == 1) {
			player = 2;
		} else {
			player = 1;
		}

		check_for_winner(board);

	} while (!winner);

	cout << "Congratulations Player " << winner_number << "! You're the winner!" << endl;
	cout << "The winning move was " << winning_move << endl << endl;
}