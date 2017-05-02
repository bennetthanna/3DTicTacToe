#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool winner = false;
char winner_number = '0';
string winning_move;

// initialize the board to all empty squares
void initialize_board (char board[4][4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				board[i][j][k] = ' ';
			}
		}
	}
}

// print out the board with the board numbers, the row numbers, and the column numbers
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

// check for winning cases
// cases where someone wins on board[i][j][k]
// i = board #
// j = row #
// k = column #
// on same board (i's are the same)
	// across a row (j's are the same, k's are different)
	// down a column (k's are the same, j's are different)
	// diagonal left top to right bottom (i,0,0)(i,1,1)(i,2,2)(i,3,3)
	// diagonal right top to left bottom (i,3,0)(i,2,1)(i,1,2)(i,0,3)
// on all different boards (i's are different)
	// same coordinate through the boards (j's and k's are the same - example: (1,2) for all i's)
	// diagonal through the boards in same row (j's are the same, k's are different)
	// diagonal through the boards in same column (k's are the same, j's are different)
	// diagonal through the boards top left back to bottom right front (0,0,0)(1,1,1)(2,2,2)(3,3,3)
	// diagonal through the boards top right back to bottom left front (0,0,3)(1,1,2)(2,2,1)(3,3,0)
	// diagonal through the boards bottom left front to top right back (0,3,0)(1,2,1)(2,1,2)(3,0,3)
	// diagonal through the boards bottom right front to top left back (0,3,3)(1,2,2)(2,1,1)(3,0,0)

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

int main() {

	int board_number, row_number, column_number, player;
	char board[4][4][4];
	initialize_board(board);

	// explain the background of the game and give a visual example of a valid move
	cout << endl << "Welcome to 3D Four Board Tic Tac Toe" << endl;
	cout << "When it is your turn, you will be prompted to enter your desired move" << endl;
	cout << "You will do so in the format board_number row_number column_number" << endl;
	cout << "Options range from 0-3" << endl;
	cout << "For example: 0 3 1" << endl;
	cout << "This would be board 0, row 3, column 1 and would be as follows" << endl << endl;

	board[0][3][1] = 'X';
	print_board(board);

	// reset board
	board[0][3][1] = ' ';
	player = 1;

	// continuously prompt players while there is no winner
	do {
		cout << "Player " << player << " what's your move?\n";
		cin >> board_number >> row_number >> column_number;
		cout << endl;
		// error check user input
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
		// if valid move, set chosen square to player's number
		board[board_number][row_number][column_number] = player+'0';
		print_board(board);

		// toggle players
		if (player == 1) {
			player = 2;
		} else {
			player = 1;
		}

		check_for_winner(board);

	} while (!winner);

	// output who the winner is and how they won
	cout << "Congratulations Player " << winner_number << "! You're the winner!" << endl;
	cout << "The winning move was " << winning_move << endl << endl;
}