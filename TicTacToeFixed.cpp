// TicTacToe_true.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
//Variable Declaration







char player_turn(char turn);
int gameover();
void display_board() {

	//Rander Game Board LAYOUT

	cout << "PLAYER - 1 [X]   PLAYER - 2 [O]\n\n";

	cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
	cout << "\t\t     |     |     \n";

}

int main()
{

	display_board();
	char turn = 'X';
	turn = player_turn(turn);

	int counter = 1;
	int end = 0;
	char win;
	while (end != 1) {
		display_board();
		turn = player_turn(turn);
		end = gameover();
		if (end == 1)
			if (turn == '0')
				win = 'X';
			else
				win = '0';
	}
	display_board();
	if (win == 'X'){
		cout << R"(
				############################################################
				# __   __                         __      __  _            #
				# \ \ / /   ___    _  _      o O O\ \    / / (_)    _ _    #
				#  \ V /   / _ \  | +| |    o      \ \/\/ /  | |   | ' \   #
				#  _|_|_   \___/   \_,_|   TS__[O]  \_/\_/  _|_|_  |_||_|  #
				#_| """ |_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| #
				#"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-' #
				############################################################
			)";
		cout << "\n\n Congratulations! Player with 'X' has won the game\n";
	}
	if (win == '0'){
		cout << R"(
				############################################################
				# __   __                         __      __  _            #
				# \ \ / /   ___    _  _      o O O\ \    / / (_)    _ _    #
				#  \ V /   / _ \  | +| |    o      \ \/\/ /  | |   | ' \   #
				#  _|_|_   \___/   \_,_|   TS__[O]  \_/\_/  _|_|_  |_||_|  #
				#_| """ |_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| #
				#"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-' #
				############################################################
			)";
		cout << "\n\n Congratulations!  Player with '0' has won the game\n";
	}





	return 0;
}

char player_turn(char turn)
{
	if (turn == 'X') {
		cout << "\n Player - 1 [X] turn : \n";
	}
	else if (turn == '0') {
		cout << "\n Player - 2 [0] turn : \n";
	}
	//Taking input from user
	//updating the board 
	int choice;
	cin >> choice;

	//switch case to get which row and column will be update
	int row, column;

	switch (choice) {
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "Invalid Move";
	}

	if (turn == 'X') {
		//updating the position for 'X' symbol 
		if (board[row][column] != '0' && board[row][column] != 'X') {
			board[row][column] = 'X';
			turn = '0';
		}
		else {
			cout << "-------- \nInvalid Move \nThis Square has already been Selected \n--------\n";
			turn = 'X';
		}
			
		
	}
	else
		if (turn == '0') {
			//updating the position for 'O' symbol 
			if (board[row][column] != 'X' && board[row][column] != '0') {
				board[row][column] = '0';
				turn = 'X';
			}
			else {
				cout << "-------- \nInvalid Move \nThis Square has already been Selected \n--------\n";
				turn = '0';
			}
		}

	return turn;
}

int gameover()
{
	int end = 0;
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			end = 1;

	for (int i = 0; i < 3; i++)
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			end = 1;

	//checking the win for both diagonal

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		end = 1;


	return end;
}




